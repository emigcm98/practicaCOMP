miniP : sintactico.tab.c lex.yy.c main.c listaSimbolos.c listaCodigo.c
	gcc -g sintactico.tab.c lex.yy.c main.c listaSimbolos.c listaCodigo.c -lfl -o miniP

lex.yy.c : lexico.l sintactico.tab.h
	flex lexico.l

sintactico.tab.h sintactico.tab.c : sintactico.y listaSimbolos.h listaCodigo.h
	bison -d -v sintactico.y

limpiar :
	rm -f sintactico.tab.* lex.yy.c miniP sintactico.output

