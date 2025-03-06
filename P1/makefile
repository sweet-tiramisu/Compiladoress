miniC: main.c miniC.tab.c lex.yy.c miniC.tab.h
	gcc lex.yy.c main.c miniC.tab.c -lfl -o miniC
miniC.tab.c miniC.tab.h: miniC.y
	bison -d -v miniC.y
lex.yy.c: miniC.l
	flex miniC.l
limpia:
	rm lex.yy.c miniC.tab.c miniC.tab.h miniC
run:
	./miniC prueba.c
