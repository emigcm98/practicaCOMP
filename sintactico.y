%{

    #include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "listaSimbolos.h"
	#include "listaCodigo.h"

    extern int yylex();
    extern int yylineno;
	extern int yytext();
    
	Lista tablaSimb;
    int errores_sintacticos = 0;
	int errores_semanticos = 0;
	int contador_string = 0;
    void yyerror (char const *);

	Tipo tipo; //para mostrar cuándo es constante, variable o string

	short registros[10] = {0};
	char* getRegistro(); //te da el primer registro disponible
	void liberarReg(char*); //libera el registro que le pases
	char* generaEtiqSalto();
	void generarCodigoFuncion(ListaC);

	/* statements */
	int contadorSalto = 1;

	/* FUNCIONES */
	char args_on; //estoy en los argumentos
	char * function_name;
	int n_args; // numero de argumentos de la funcion actual;
%}

%union{
	char *lexema;
	ListaC codigo;
}

%code requires {
	#include "listaCodigo.h"
}

%expect 1 //bison por  defecto, para conflictos shift/reduce usa derivaciones por la izquierda, 
//así que coge el else con el if mas cercano.
//con este comando eliminamos el warning

%token BEGINN          	"begin"
%token END             	"end"
%token READ            	"read"
%token WRITE           	"write"
%token PARI          	"("
%token PARD         	")"
%token PYC              ";"
%token COMA           	","
%token ASIG             ":="
%token PROGRAM          "program"
%token FUNCTION         "function"
%token CONST            "const"
%token IF               "if"
%token ELSE             "else"
%token THEN             "then"
%token DOSPUNTOS        ":"
%token MAS              "+"
%token MENOS            "-"
%token POR  	        "*"
%token DIV              "/"
%token PUNTO            "."         
%token INTEGER          "integer"
%token VAR              "var"
%token WHILE            "while"
%token DO               "do"
%token FOR              "for"
%token TO               "to"
%token <lexema> STRING ID ENTERO

%start program

%type <codigo> program functions function declarations identifiers compound_statement optional_statements statements 
statement expressions expression print_item print_list constants read_list optional_arguments

%define parse.error verbose //errores sintacticos con detalle

%left MAS MENOS
%left POR DIV
%left UMINUS

%%

program : {tablaSimb=creaLS(); } "program" ID "(" ")" ";" functions declarations compound_statement "." { 
	
	if(errores_semanticos==0){
		
		printf("##################\n# Seccion de datos\n\t.data\n\n");
		imprimirLS(tablaSimb, CADENA);
		imprimirLS(tablaSimb, VARIABLE); 
		imprimirLS(tablaSimb, CONSTANTE);

		printf("\n####################\n # Seccion de codigo\n\t.text\n\t.globl main\n\n");
			
		Operacion o;
		o.op = "li";
		o.res = "$v0";
		o.arg1 = "10";
		o.arg2 = NULL;
		insertaLC($9, finalLC($9), o);
		Operacion o2;
		o2.op = "syscall";
		o2.res = NULL;
		o2.arg1 = NULL;
		o2.arg2 = NULL;
		insertaLC($9, finalLC($9), o2);

		imprimirLC($7);	//funciones	
		printf("main:\n");
		imprimirLC($8); //declaraciones
		imprimirLC($9); //codigo

		liberaLC($7);
		liberaLC($8);
		liberaLC($9);
		liberaLS(tablaSimb);
	}
	

	}
		;
functions : functions function ";" {concatenaLC($$,$2);}
		| {$$=creaLC();}/*lambda*/
		;
function : FUNCTION ID {

	if (buscaLS(tablaSimb, $2) == finalLS(tablaSimb)){ //si llegamos al final, no está
		Simbolo s;
		s.tipo = FUNCION;
		s.nombre = $2;
		s.valor = 0; // numero de argumentos
		function_name = $2;
		insertaLS(tablaSimb, finalLS(tablaSimb), s);
	}
	else{	//insertamos al final
		printf("Error en linea %d: Variable %s ya declarada, no puede identificar a una función\n", yylineno, $2);
		errores_semanticos++;
	}
} "(" "const" {args_on = 1;} identifiers {args_on=0;} ":" type ")" ":" type {

		if(n_args>4){
			printf("Error en linea %d: se tienen %d argumentos, pero el máximo es 4\n", yylineno, n_args);
			errores_semanticos++;
		}
		
		PosicionLista p = buscaLS(tablaSimb, $2);
		Simbolo s = recuperaLS(tablaSimb, p);
		s.valor = n_args; 
		suprimeLS(tablaSimb, p);
		insertaLS(tablaSimb, finalLS(tablaSimb), s); //lo sacamos, cambiamos, suprimimos e insertamos de nuevo con el nuevo valor
				
		n_args = 0; //ponemos a 0 para la siguiente funcion
		
	} declarations compound_statement { 
			
			$$ = creaLC();
			concatenaLC($$,$7);
			concatenaLC($$,$15);
			concatenaLC($$,$16);		
			function_name=NULL;

			generarCodigoFuncion($$); //codigo de apilación
			
			Operacion salto; //etiqueta de salto
			salto.op = NULL;
			salto.res = concat(concat("_", $2),":"); //$2 es el ID
			salto.arg1 = NULL;
			salto.arg2 = NULL;
			insertaLC($$, inicioLC($$), salto);
	
		}
		;
declarations : declarations "var" {tipo = VARIABLE;} identifiers ":" type ";"  {
				$$ = creaLC();
				concatenaLC($$,$1);
				concatenaLC($$,$4);
				liberaLC($1);
				liberaLC($4);
			}
			| declarations "const" {tipo = CONSTANTE;} constants ";" {
				$$ = creaLC();
				concatenaLC($$,$1);
				concatenaLC($$,$4);
				liberaLC($1);
				liberaLC($4);

			}
			| /* lambda*/ {$$ = creaLC();}
			;
identifiers : ID { 
				$$=creaLC();
				if(args_on){ //si son ARGUMENTOS

					if (buscaLS(tablaSimb, $1) == finalLS(tablaSimb)){
						Simbolo s;
						s.tipo = ARGUMENTO; //la variable de un argumento es constante
						s.nombre = concat(concat(function_name,"."), $1);
						s.valor = n_args; // el numero de argumento.
						insertaLS(tablaSimb, finalLS(tablaSimb),s);
						n_args++; //tenemos un argumento más siendo procesado

					}
					else {
						printf("Error en linea %d: Variable %s ya declarada, quizas en el nombre de la funcion \n", yylineno, $1);
						errores_semanticos++;
					}
				}
				else{

					char* var;
					if (function_name == NULL) var = $1; 
					else{
						if(buscaLS(tablaSimb, $1) == finalLS(tablaSimb))
							var = concat(concat(function_name,"."), $1); //ambito de una funcion
						else var = $1;
					} 

					if (buscaLS(tablaSimb, var) == finalLS(tablaSimb)){ //si llegamos al final, no está
						Simbolo s;
						if (function_name!=NULL){ //estamos declarando variable del ambito de la funcion strcmp(function_name,"nada")!=0
							s.tipo = tipo;
							s.nombre = concat(concat(function_name,"."), $1);
							s.valor = n_args; //el numero del argumento 
						}
						else {
							s.tipo = tipo;
							s.nombre = $1;
							s.valor = 0; // por defecto
						}
						insertaLS(tablaSimb, finalLS(tablaSimb), s);
					}
					else{	//insertamos al final
						printf("Error en linea %d: Variable %s ya declarada \n", yylineno, $1);
						errores_semanticos++;
					}
				}

			}

			| identifiers "," ID {
				$$=creaLC();
				if(args_on){ //si son identificadores de parametro de una función...
					//calcular el número de argumentos convirtiendo a identifiers en tipo entero
					if (buscaLS(tablaSimb, $3) == finalLS(tablaSimb)){
						Simbolo s;
						s.tipo = ARGUMENTO; //la variable de un argumento es constante
						s.nombre = concat(concat(function_name,"."), $3); //y.a
						s.valor = 0; // por defecto 
						insertaLS(tablaSimb, finalLS(tablaSimb),s);
						n_args++; 
					}
					else {
						printf("Error en linea %d: Variable %s ya declarada, quizas en el nombre de la funcion \n", yylineno, $3);
						errores_semanticos++;
					}
				}
				else{			
					concatenaLC($$,$1);
					liberaLC($1);

					char* var;
					if (function_name == NULL) var = $3; 
					else{
						if(buscaLS(tablaSimb, $3) == finalLS(tablaSimb))
							var = concat(concat(function_name,"."), $3); //ambito de una funcion
						else var = $3;
					}

					/*char* var;
					if (function_name == NULL) var = $3;
					else var = concat(concat(function_name,"."), $3); //si estoy en el ambito de una funcion*/

					if (buscaLS(tablaSimb, var) == finalLS(tablaSimb)){
						Simbolo s;
						if (function_name!=NULL){ //estamos declarando variable del ambito de la funcion strcmp(function_name,"nada")!=0
							s.tipo = tipo;
							s.nombre = concat(concat(function_name,"."), $3);
							s.valor = 0; // por defecto 
						}
						else {
							s.tipo = tipo;
							s.nombre = $3;
							s.valor = 0; // por defecto
						}
						insertaLS(tablaSimb, finalLS(tablaSimb), s);
					} 
					else{	//insertamos al final
						printf("Error en linea %d: Variable %s ya declarada \n", yylineno, $3);
						errores_semanticos++;
					}
				}
					
			}
type 		: "integer"
			;
constants	: ID ":=" expression { 
					$$=creaLC();
					char* var;
					if (function_name == NULL) var = $1; 
					else var = concat(concat(function_name,"."), $1); //si estoy en el ambito de una funcion

				if (buscaLS(tablaSimb, var) == finalLS(tablaSimb)){ //si llegamos al final, no está
					
					Simbolo s;
					s.tipo = CONSTANTE;
					s.nombre = var;
					s.valor = 0; // por defecto
					insertaLS(tablaSimb, finalLS(tablaSimb), s);

					concatenaLC($$,$3);

					Operacion o;
	  				o.op = "sw";
					o.res = recuperaResLC($3);
	  				o.arg1 = concat("_", $1); //$1 o var?
	  				o.arg2 = NULL; 
	  				insertaLC($$,finalLC($$),o);	
					liberarReg(o.res);
					
					liberaLC($3);
				}
				else{	//insertamos al final
						printf("Error en linea %d: Variable %s ya declarada \n", yylineno, $1);
						errores_semanticos++;
				}

			}
			| constants "," ID ":=" expression {
					$$=creaLC();
				if (buscaLS(tablaSimb, $3) == finalLS(tablaSimb)){ //si llegamos al final, no está
					Simbolo s;
					s.tipo = CONSTANTE;
					s.nombre = $3;
					s.valor = 0; // por defecto
					insertaLS(tablaSimb, finalLS(tablaSimb), s);
					concatenaLC($$,$1);
					concatenaLC($$,$5);
					liberaLC($1);
					liberaLC($5);
				}
				 else{	//insertamos al final
						printf("Error en linea %d: Variable %s ya declarada \n", yylineno, $3);
						errores_semanticos++;
				}
					
			}
			;
compound_statement : BEGINN optional_statements END{
			$$ = $2;

			}
					;
optional_statements : statements {$$=$1;}
			| /*lambda*/ {$$=creaLC();}
			;
statements : statement  {
				$$=$1;
			}
			| statements ";" statement {
				$$ = creaLC();
				concatenaLC($$,$1);
				concatenaLC($$,$3);
				liberaLC($1);
				liberaLC($3);
			}
			;
statement : ID ":=" expression {

					char* var;
					if (function_name == NULL) var = $1; 
					else {
						if (buscaLS(tablaSimb, $1) == finalLS(tablaSimb)) var = concat(concat(function_name,"."), $1); //NO ES UNA VARIABLE FUNCION
						else var = $1;
					}

					$$ = creaLC();

					if (buscaLS(tablaSimb, var) == finalLS(tablaSimb)){ //si no se encuentra no se puede asignar
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, $1);
						errores_semanticos++;
					}
					else{
						Simbolo s = recuperaLS(tablaSimb,buscaLS(tablaSimb, var)); 
						if (s.tipo == CONSTANTE){
							printf("Error en linea %d: %s es constante\n", yylineno, $1);
							errores_semanticos++;
						}
						if ( s.tipo == ARGUMENTO){
							printf("Error en linea %d: %s es un argumento, y por lo tanto es constante\n", yylineno, $1);
							errores_semanticos++;
						}

						concatenaLC($$, $3);

						if ( s.tipo == FUNCION){
							Operacion o;
							o.op = "move";
							o.res = "$v0";
							o.arg1 = recuperaResLC($3);
							o.arg2 = NULL;
							liberarReg(o.arg1);
							insertaLC($$, finalLC($$), o);
						}
						else {
							Operacion o;
	  						o.op = "sw";
							o.res = recuperaResLC($3);
	  						o.arg1 = concat("_", var);
	  						o.arg2 = NULL; 
	  						insertaLC($$,finalLC($$),o);	
							liberarReg(o.res);
							liberaLC($3);
						}
						
						
					}
					

				}

			| "if" expression "then" statement { //SIN HACER
				
				$$ = creaLC();
				concatenaLC($$,$2);

				Operacion o;

				o.op = "beqz";
				o.res = recuperaResLC($2);
				o.arg1 = generaEtiqSalto();//etiqueta de salto
				o.arg2 = NULL;
				insertaLC($$, finalLC($$), o);

				concatenaLC($$,$4);

				Operacion o2; //salto
				o2.op = NULL; //la etiqueta
				o2.res = concat(o.arg1, ":");
				o2.arg1= NULL;
				o2.arg2 = NULL;
				insertaLC($$, finalLC($$), o2);

				liberarReg(o.res); //liberamos el registro de la sentencia
				liberaLC($2);
				liberaLC($4);
				
			}

			| "if" expression "then" statement "else" statement {

				$$=creaLC();
				concatenaLC($$,$2);
				Operacion o;

				o.op = "beqz";
				o.res = recuperaResLC($2);
				o.arg1 = generaEtiqSalto();//etiqueta de salto
				o.arg2 = NULL;
				insertaLC($$, finalLC($$), o);

				concatenaLC($$,$4);

				Operacion o2; //salto 1
				o2.op = NULL; //la etiqueta
				o2.res = concat(o.arg1, ":");
				o2.arg1= NULL;
				o2.arg2 = NULL;			

				Operacion o3; //salto incondicional 
				o3.op = "b"; //salta incodicionlamente al resto del codigo para no pasar por el else
				o3.res = generaEtiqSalto(); //genera la etiqueta del resto del codigo
				o3.arg1 = NULL;
				o3.arg2 = NULL;

				insertaLC($$, finalLC($$), o3);
				insertaLC($$, finalLC($$), o2);
				concatenaLC($$,$6);

				Operacion o4; //etiqueta de salto final
				o4.op = NULL;
				o4.res = concat(o3.res, ":");
				o4.arg1 = NULL;
				o4.arg2 = NULL;

				insertaLC($$,finalLC($$), o4);

				liberarReg(o.res); //liberamos el registro de la sentencia
				liberaLC($2);
				liberaLC($4);
				liberaLC($6);
			}

			| "while" expression "do" statement {

				$$=creaLC();

				Operacion o3; //la pongo antes para que genere el registre y la otra le concatene los ":"
				o3.op = "b";
				o3.res = generaEtiqSalto(); //hay que quitar ":"
				o3.arg1 = NULL;
				o3.arg2 = NULL;

				Operacion o; //etiqueta de inicio;
				o.op = NULL;
				o.res = concat(o3.res, ":");
				o.arg1 = NULL;
				o.arg2 = NULL;

				insertaLC($$, finalLC($$), o);

				concatenaLC($$,$2);

				Operacion o2;
				o2.op = "beqz";
				o2.res = recuperaResLC($2);
				o2.arg1 = generaEtiqSalto();
				o2.arg2= NULL;

				insertaLC($$, finalLC($$), o2);
				concatenaLC($$, $4);

				insertaLC($$, finalLC($$), o3);
				
				Operacion o4; //etiqueta de salto 2
				o4.op = NULL;
				o4.res = concat(o2.arg1, ":");
				o4.arg1= NULL;
				o4.arg2 = NULL;

				insertaLC($$,finalLC($$), o4);

				liberaLC($2);
				liberaLC($4);
			}

			| "for" ID ":=" expression "to" expression "do" statement{

				$$=creaLC();
				if (buscaLS(tablaSimb, $2) == finalLS(tablaSimb)){ //si no se encuentra no se puede asignar
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, $2);
						errores_semanticos++;
					}
				else{
					Simbolo s = recuperaLS(tablaSimb,buscaLS(tablaSimb, $2)); 
					if (s.tipo == CONSTANTE){
						printf("Error en linea %d: %s es constante\n", yylineno, $2);
						errores_semanticos++;
					}
					else{ //si todo está bien pasemos a generar las operaciones

						concatenaLC($$,$4); 
						
						Operacion o;
						o.op = "sw";
						o.res = recuperaResLC($4);
						o.arg1 = concat("_", $2);
						o.arg2 = NULL;
						liberarReg(o.res);
						insertaLC($$, finalLC($$), o);

						Operacion o2; 
						o2.op = "lw";
						o2.res = getRegistro();
						o2.arg1 = concat("_", $2);
						o2.arg2 = NULL;
						insertaLC($$, finalLC($$), o2);

						concatenaLC($$,$6);

						Operacion o3;
						o3.op = "b";
						o3.res = generaEtiqSalto(); 
						o3.arg1 = NULL;
						o3.arg2 = NULL;				

						Operacion o4; //etiqueta de inicio for;
						o4.op = NULL;
						o4.res = concat(o3.res, ":");
						o4.arg1 = NULL;
						o4.arg2 = NULL;

						insertaLC($$, finalLC($$), o4); //añadimos primera etiqueta

						Operacion o5; //para ver cuando salimos, si es mayor de la expression
						o5.op = "bgt";
						o5.res = o2.res; //el registro temporal 
						o5.arg1 = recuperaResLC($6); //recuperamos el registro de la expression de "to"
						o5.arg2 = generaEtiqSalto();

						insertaLC($$, finalLC($$), o5);

						concatenaLC($$, $8);

						Operacion o6; //sumar 1 a la variable MIRAR
						o6.op = "addiu";
						o6.res = o2.res;
						o6.arg1 = o2.res;
						o6.arg2 = "1";
						insertaLC($$,finalLC($$),o6);

						Operacion o7; //sumar 1 a la variable MIRAR
						o7.op = "sw";
						o7.res = o5.res;
						o7.arg1 = concat("_", $2);
						o7.arg2 = NULL;
						insertaLC($$,finalLC($$), o7);
						
						insertaLC($$, finalLC($$), o3);
				
						Operacion o8; //etiqueta de salto 2
						o8.op = NULL;
						o8.res = concat(o5.arg2, ":");
						o8.arg1= NULL;
						o8.arg2 = NULL;
						insertaLC($$,finalLC($$), o8);

						liberaLC($4);
						liberaLC($6);
						liberaLC($8);
					}	
				}	
			}

			| "write" "(" print_list ")" {

				$$=$3;
			}						
			| "read" "(" read_list ")" {
				$$=$3;
			}
			| compound_statement {
				$$=$1;
			}
			;
print_list : print_item {$$=$1;}
			|	print_list "," print_item {
				$$=creaLC();
				concatenaLC($$,$1);
				concatenaLC($$,$3);
				liberaLC($1);
				liberaLC($3);

			}
			;
print_item : expression {

				$$=creaLC();
				concatenaLC($$,$1);

				if (function_name!=NULL){

					Operacion op;
					op.op = "move";
					op.res = "$s0";
					op.arg1 = "$a0"; //lo que haya previamente
					op.arg2 = NULL;
					insertaLC($$, finalLC($$),op);

					Operacion op2;
					op2.op = "move";
					op2.res = "$s1";
					op2.arg1 = "$v0"; //lo que haya previamente
					op2.arg2 = NULL;
					insertaLC($$, finalLC($$),op2);					
				}

				Operacion o1;
				o1.op = "move"; //move o li?
				o1.res = "$a0"; 
				o1.arg1 = recuperaResLC($1);
				o1.arg2 = NULL;
				Operacion o2;
				o2.op = "li";
				o2.res = "$v0"; 
				o2.arg1 = "1";
				o2.arg2 = NULL;
				Operacion o3;
				o3.op = "syscall";
				o3.res = NULL;
				o3.arg1 = NULL;
				o3.arg2 = NULL;
				insertaLC($$, finalLC($$), o1);
				insertaLC($$, finalLC($$), o2);
				insertaLC($$, finalLC($$), o3);
				liberaLC($1);
				liberarReg(o1.arg1); //ya no lo queremos

				if (function_name!=NULL){

					Operacion op3;
					op3.op = "move";
					op3.res = "$a0";
					op3.arg1 = "$s0"; //lo que haya previamente
					op3.arg2 = NULL;
					insertaLC($$, finalLC($$),op3);

					Operacion op4;
					op4.op = "move";
					op4.res = "$v0";
					op4.arg1 = "$s1"; //lo que haya previamente
					op4.arg2 = NULL;
					insertaLC($$, finalLC($$),op4);					
				}
		} 					
						
			| STRING {

				$$= creaLC();
				contador_string++;

				Simbolo s;
				s.tipo = CADENA;
				s.nombre = $1;
				s.valor = contador_string; // para saber cuál es
				insertaLS(tablaSimb, finalLS(tablaSimb), s);
				
				Operacion o1;
				o1.op = "la"; 
				o1.res = "$a0"; 
				char res[8];
				sprintf(res, "$Str%d", contador_string);
				o1.arg1 = strdup(&res[0]); //reserva memoria
				o1.arg2 = NULL;
				
				Operacion o2;
				o2.op = "li"; 
				o2.res = "$v0"; 
				o2.arg1 = "4"; 
				o2.arg2 = NULL;

				Operacion o3;
				o3.op = "syscall";
				o3.res = NULL;
				o3.arg1 = NULL;
				o3.arg2 = NULL;

				insertaLC($$, finalLC($$), o1);
				insertaLC($$, finalLC($$), o2);
				insertaLC($$, finalLC($$), o3);
				
			}
			;
read_list : ID {
				$$ = creaLC();
				if (buscaLS(tablaSimb, $1) == finalLS(tablaSimb)){ //si no se encuentra no se puede asignar
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, $1);
						errores_semanticos++;
					}
				else if (recuperaLS(tablaSimb, buscaLS(tablaSimb,$1)).tipo == CONSTANTE) {
						printf("Error en linea %d: %s es constante\n", yylineno, $1);
						errores_semanticos++;
					}
				else{ //si todo está bien creamos
						
					Operacion o1;
					o1.op = "li";
					o1.res = "$v0";
					o1.arg1 = "5"; 
					o1.arg2 = NULL;
					Operacion o2;
					o2.op = "syscall";
					o2.res = NULL;
					o2.arg1 = NULL;
					o2.arg2 = NULL;
					Operacion o3;
					o3.op = "sw";
					o3.res = "$v0";
					o3.arg1 = concat("_", $1);
					o3.arg2 = NULL;
					insertaLC($$, finalLC($$), o1);
					insertaLC($$, finalLC($$), o2);
					insertaLC($$, finalLC($$), o3);
				}
			}

			| read_list "," ID {	

				$$ = creaLC();
				if (buscaLS(tablaSimb, $3) == finalLS(tablaSimb)){ //si no se encuentra no se puede asignar
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, $3);
						errores_semanticos++;
					}
				else if (recuperaLS(tablaSimb, buscaLS(tablaSimb,$3)).tipo == CONSTANTE) {
						printf("Error en linea %d: %s es constante\n", yylineno, $3);
						errores_semanticos++;
					}
				else{				
					concatenaLC($$,$1);
					Operacion o1;
					o1.op = "li";
					o1.res = "$v0"; //no hay que comprobar registros
					o1.arg1 = "5"; //AQUÍ HAY QUE DISTINGUIR ENTRE ENTEROS Y STRINGS
					o1.arg2 = NULL;
					Operacion o2;
					o2.op = "syscall";
					o2.res = NULL;
					o2.arg1 = NULL;
					o2.arg2 = NULL;
					Operacion o3;
					o3.op = "sw";
					o3.res = "v0";
					o3.arg1 = concat("_", $3);
					o3.arg2 = NULL;
					insertaLC($$, finalLC($$), o1);
					insertaLC($$, finalLC($$), o2);
					insertaLC($$, finalLC($$), o3);
					liberaLC($1);
				}
			}
			;
expression : expression "+" expression {

				$$=creaLC();
				concatenaLC($$, $1);
				concatenaLC($$, $3);
				Operacion o;
				o.op = "add";
				o.res = getRegistro();
				o.arg1 = recuperaResLC($1);
				o.arg2 = recuperaResLC($3);
				insertaLC($$, finalLC($$), o);
				guardaResLC($$, o.res);
				liberarReg(o.arg1);
				liberarReg(o.arg2);
				liberaLC($1);
				liberaLC($3);
			}

			| expression "-" expression {

				$$=creaLC();
				concatenaLC($$, $1);
				concatenaLC($$, $3);
				Operacion o;
				o.op = "sub";
				o.res = getRegistro();
				o.arg1 = recuperaResLC($1);
				o.arg2 = recuperaResLC($3);
				insertaLC($$, finalLC($$), o);
				guardaResLC($$, o.res);
				liberarReg(o.arg1);
				liberarReg(o.arg2);
				liberaLC($1);
				liberaLC($3);
			}

			| expression "*" expression {
				$$ = creaLC();
				concatenaLC($$, $1);
				concatenaLC($$, $3);
				Operacion o;
				o.op = "mul";
				o.res = getRegistro();
				o.arg1 = recuperaResLC($1);
				o.arg2 = recuperaResLC($3);
				insertaLC($$, finalLC($$), o);
				guardaResLC($$, o.res);
				liberarReg(o.arg1);
				liberarReg(o.arg2);
				liberaLC($1);
				liberaLC($3);
			}

			| expression "/" expression {
				$$ = creaLC();
				concatenaLC($$, $1);
				concatenaLC($$, $3);
				Operacion o;
				o.op = "div";
				o.res = getRegistro();
				o.arg1 = recuperaResLC($1);
				o.arg2 = recuperaResLC($3);
				insertaLC($$, finalLC($$), o);
				guardaResLC($$, o.res);
				liberarReg(o.arg1);
				liberarReg(o.arg2);
				liberaLC($1);
				liberaLC($3);
			}

			| "-" expression %prec UMINUS {
				$$ = creaLC();
				concatenaLC($$,$2);
				Operacion o;
				o.op = "neg";
				o.res = getRegistro();
				o.arg1 = recuperaResLC($2);
				o.arg2 = NULL;
				insertaLC($$, finalLC($$), o);
				guardaResLC($$, o.res);
				liberarReg(o.arg1);
				liberaLC($2); 
			}

			| "(" expression ")" { //PUTOS PARENTESIS

				$$=$2;
			}
			| ID	{

				$$ = creaLC();
				char* var;
				if (function_name == NULL) var = $1; 
					else {
						if (buscaLS(tablaSimb, $1) == finalLS(tablaSimb)) var = concat(concat(function_name,"."), $1); //NO ES UNA VARIABLE FUNCION
						else var = $1;
					}				
	
				if (buscaLS(tablaSimb, var) == finalLS(tablaSimb)){ //si no se encuentra no se puede asignar
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, $1);
						errores_semanticos++;
					}
				else {
						Simbolo s = recuperaLS(tablaSimb, buscaLS(tablaSimb, var)); 
					if (s.tipo != ARGUMENTO){
						Operacion o;
						o.op = "lw";
						o.res = getRegistro();
						o.arg1 = concat("_", var);
						o.arg2 = NULL;
						insertaLC($$, finalLC($$), o);
						guardaResLC($$, o.res);
					}
					else {
						char reg[4];
						sprintf(reg, "$a%d", s.valor);
						guardaResLC($$, strdup(reg)); //se guarda el registro de parametro
					}

				}
			}
				
			| ENTERO {
				$$=creaLC();
				Operacion o;
  				o.op = "li";
				o.res = getRegistro();
  				o.arg1 = $1;
  				o.arg2 = NULL;
  				insertaLC($$,finalLC($$),o);
				guardaResLC($$,o.res);
			}

			| ID "(" optional_arguments ")" { //comprobar que ID existe y es de tipo FUNCION

				$$ = creaLC();
				Simbolo s;
				
				if (buscaLS(tablaSimb, $1) == finalLS(tablaSimb)){ 
						printf("Error en linea %d: La variable %s no está declarada\n" , yylineno, $1);
						errores_semanticos++;
				}
				else {
					s = recuperaLS(tablaSimb, buscaLS(tablaSimb, $1));
					if (s.tipo != FUNCION){
						printf("Error en linea %d: La variable %s no es una funcion\n" , yylineno, $1);
						errores_semanticos++;
					}
					else if (s.valor != n_args){
						printf("Error en linea %d: Numero de argumentos incorrectos para %s, se esperaban %d y se tienen %d\n" , yylineno, $1, s.valor, n_args);
						errores_semanticos++;
					}
				}
				
				concatenaLC($$,$3);

				Operacion o;
				o.op = "jal";
				o.res = concat("_", $1);
				o.arg1 = o.arg2 = NULL;
				insertaLC($$, finalLC($$), o);

				Operacion o2;
				o2.op = "move";
				o2.res = getRegistro();
				o2.arg1 = "$v0";
				o2.arg2=NULL;
				guardaResLC($$, o2.res); //GUARDAR
				insertaLC($$, finalLC($$), o2);

				n_args = 0; //se vuelven a poner a 0 para posteriores usos
			}
			;
optional_arguments : expressions
			| /*lambda*/ {$$ = creaLC();}
			;
expressions : expression {
	
				$$=creaLC();
				concatenaLC($$,$1);
				Operacion o;
				o.op = "move";
				char arr[4];
				sprintf(arr, "$a%d", n_args);
				o.res = strdup(arr); 
				o.arg1 = recuperaResLC($1);
				o.arg2 = NULL;
				insertaLC($$, finalLC($$), o);
				guardaResLC($$, o.res);
				liberarReg(o.arg1);
				
				n_args++;
			}
			| expressions "," expression {
				concatenaLC($$,$3);
				
				Operacion o;
				o.op = "move";
				char arr[4];
				sprintf(arr, "$a%d", n_args);
				o.res = strdup(arr); 
				o.arg1 = recuperaResLC($3);
				o.arg2 = NULL;
				guardaResLC($$, o.res);
				liberarReg(o.arg1);
				insertaLC($$, finalLC($$), o);
				liberaLC($3);
				n_args++;
			}
			;

%%

void yyerror (char const *s)
     {
	   errores_sintacticos++;
       fprintf (stderr, "%s en linea %d\n", s, yylineno);
     }


void liberarReg(char *r){ //r = registro
	if (r==NULL)return;	//POR SI LA VARIABLE NO ESTÁ DECLARADA. Si no lo está, recuperará un Res NULL, y por lo tanto no se podrá liberar
	short pos = atoi(r + 2); // $tn, donde n es la segunda posicion;
	registros[pos] = 0;
}

char* getRegistro(){
	for(int i = 0; i < 10; i++){
		if (registros[i]==0){
			registros[i]=1;
			char *res = malloc(4); //mirar si reserva bien
			sprintf(res, "$t%d", i);
			return res;
		}
	}
	return NULL;
}

char *generaEtiqSalto() {
	char aux[10];
	sprintf(aux, "$l%d", contadorSalto++);
	return strdup(aux);	
}

void generarCodigoFuncion(ListaC lista_statements){

	char temporales[11] = {0};	

	PosicionListaC p = inicioLC(lista_statements);
	while (p != finalLC(lista_statements)){
		Operacion o = recuperaLC(lista_statements, p);	

		if(o.res!=NULL && o.res[0]=='$'){
			if (o.res[1]=='t'){
				temporales[o.res[2]-'0']=1;
			}
		}
		/*if(o.arg1!=NULL && o.arg1[0]=='$'){
			if (o.arg1[1]=='t'){
			temporales[o.arg1[2]]=1;
			}
		}
		if(o.arg2!=NULL && o.arg2[0]=='$'){
			if (o.arg2[1]=='t'){
				temporales[o.arg2[2]]=1;
			}
		}*/
		
		p = siguienteLC(lista_statements, p);
	}

	int tempors=0;
	for(int i = 0; i < 11; i++ ) if(temporales[i]==1)tempors++;	

	Operacion o;
	o.op = "move";
	o.res = "$v0";
	o.arg1 = "$zero";
	o.arg2 = NULL;
	insertaLC(lista_statements, inicioLC(lista_statements), o);

	Operacion ra;
	ra.op = "sw";
	ra.res="$ra";
	ra.arg1 = "0 ($sp)";
	ra.arg2 = NULL;
	insertaLC(lista_statements, inicioLC(lista_statements), ra);

	int cont = 1;
	for (int i = 0; i < 11; i++){
		if (temporales[i]==1){
			Operacion o;
			o.op = "sw";
			char ja[4];
			sprintf(ja, "$t%d",i);
			o.res = strdup(ja);
			char ja2[10];
			sprintf(ja2, "%d ($sp)", cont*4);
			o.arg1 = strdup(ja2);
			o.arg2 = NULL;
			insertaLC(lista_statements, inicioLC(lista_statements), o);
			cont++;
		}

	}
	cont = 1;

	Operacion o2;
	o2.op = "addiu";
	o2.res = "$sp";
	o2.arg1 = "$sp";
	char pr[4];
	sprintf(pr, "%d", -4*(tempors+1));
	o2.arg2 = strdup(pr); 
	insertaLC(lista_statements, inicioLC(lista_statements), o2);

	Operacion ral;
	ral.op = "lw";
	ral.res="$ra";
	ral.arg1 = "0 ($sp)";
	ral.arg2 = NULL;
	insertaLC(lista_statements, finalLC(lista_statements), ral);

	for (int i = 0; i < 11; i++){
		if (temporales[i]==1){
			Operacion o;
			o.op = "lw";
			char ja[4];
			sprintf(ja, "$t%d",i);
			o.res = strdup(ja);
			char ja2[10];
			sprintf(ja2, "%d ($sp)", cont*4);
			o.arg1 = strdup(ja2);
			o.arg2 = NULL;
			insertaLC(lista_statements, finalLC(lista_statements), o);
			cont++;
		}

	}

	Operacion o3;
	o3.op = "addiu";
	o3.res = "$sp";
	o3.arg1 = "$sp";
	sprintf(pr, "%d", 4*(tempors+1));
	o3.arg2 = strdup(pr); 
	insertaLC(lista_statements, finalLC(lista_statements), o3);	

	Operacion jra;
	jra.op = "jr";
	jra.res = "$ra";
	jra.arg1=NULL;
	jra.arg2= NULL;
	insertaLC(lista_statements, finalLC(lista_statements), jra);
}
