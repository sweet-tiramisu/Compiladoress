lex.yy.c: miniC.l.l
	flex miniC.l.l
alex: lex.yy.c main.c lexico1.h
	gcc main.c lex.yy.c -lfl -o alex
	

