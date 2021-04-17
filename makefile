2048: lex.yy.c parser.tab.c game.o
	gcc -o 2048 lex.yy.c parser.tab.c game.o
	@echo executable code generated

game.o: game.c
	gcc -c game.c
	@echo object code generated

parser.tab.c: parser.y
	bison -d parser.y
	@echo parser.tab.c code generated

lex.yy.c: lex.l
	flex lex.l
	@echo lex.yy.c code generated

clean:
	rm 2048 game.o parser.tab.c lex.yy.c
	@echo clean complete
