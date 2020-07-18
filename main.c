#include <stdio.h>
#include <stdlib.h>
#include "sintactico.tab.h"

extern char *yytext;
extern int  yyleng;
extern FILE *yyin;
extern int yylex();
extern int yylineno;
extern int errores_lexicos;
extern int errores_sintacticos;
extern int errores_semanticos;

FILE *fich;

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Uso correcto: %s fichero\n",argv[0]);
		exit(1);
	}
	FILE *fich = fopen(argv[1],"r");
	if (fich == 0) {
		printf("No se puede abrir %s\n",argv[1]);
		exit(1);
	}
	yyin = fich;
	
	/*
	int i;
		while (i=yylex()) { 
        
        if(i==ID || i==STRING || i==ENTERO) 
			printf("Token: %d ; lexema: %s\n",i,yytext);
        else printf("Token: %d\n",i);
    }
	printf("------------------------\n");
	printf("Errores lexicos: %d\n", errores_lexicos);*/

	yyparse();
	printf("\n#----------------------\n");
	printf("#errores léxicos: %d\n",errores_lexicos);
	printf("#errores sintacticos: %d\n", errores_sintacticos);
	printf("#errores semánticos: %d\n", errores_semanticos);
	fclose(fich);
}
