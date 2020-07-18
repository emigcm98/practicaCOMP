%{
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sintactico.tab.h"

int errores_lexicos;
int aux;

%}

%option yylineno

digito              [0-9]
letra               [a-zA-Z]
entero              {digito}+
panico		        [^a-zA-Z0-9;,/()+\-="\r\n\t ]

%x comentario

%%

[ \n\t]+                            ;
"//"(.*)[\n]                        ;
program                             return PROGRAM;
function                            return FUNCTION;
const                               return CONST;
var                                 return VAR;
integer                             return INTEGER;
begin                               return BEGINN;
end                                 return END;
if                                  return IF;
then                                return THEN;
else                                return ELSE;
while                               return WHILE;
do                                  return DO;
for                                 return FOR;
to                                  return TO;
write                               return WRITE;
read                                return READ;
"("                                 return PARI;		
")"                                 return PARD;
";"                                 return PYC;
","                                 return COMA;
":="                                return ASIG;
"+"                                 return MAS;
"-"                                 return MENOS;
":"                                 return DOSPUNTOS;
"*"                                 return POR;
"/"                                 return DIV;
\.                                  return PUNTO;

({letra}|_)({letra}|{digito}|_)*    { if( yyleng > 16 ) {
                                       printf("ERROR: ID demasiado largo en linea %d: %s\n",
									            yylineno, yytext); errores_lexicos++;}
                                       yylval.lexema=strdup(yytext);
                                       return ID;
                                    }
                                    
{entero}                            {  if( atol(yytext) > pow(2,31) ){
                                          printf("ERROR: entero demasiado grande en linea %d: %s\n",
                                          yylineno, yytext);
                                          errores_lexicos++;
                                       }
                                       yylval.lexema=strdup(yytext);
                                       return ENTERO;  
                                    }

"(*"					                  {  aux = yylineno; BEGIN(comentario); }


\"([^"\n]|\\\")*\"                  {  yylval.lexema = strdup(yytext);
                                       return STRING;  }
\"([^"\n]|\\\")*                    {  printf("ERROR: cadena sin cerrar en linea %d\n", yylineno);
                                       errores_lexicos++;  }

{panico}+                           {  printf("ERROR: caracteres no validos en linea %d : %s\n"
                                       , yylineno, yytext); 
                                       errores_lexicos++; }

<comentario>([^*]|[*]+[^*)])*       ;    
<comentario>[*]+")"			         BEGIN(INITIAL); 
<comentario><<EOF>> 				      {  printf("ERROR: comentario no cerrado iniciado en linea %d\n", aux);
                                       errores_lexicos++;
                                       BEGIN(INITIAL);   }


%%

