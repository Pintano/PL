normal:
	flex scanner.l
	gcc lex.yy.c -o scanner -lfl
	./scanner

doc:
	flex scanner.l
	gcc lex.yy.c -o scanner -lfl
	./scanner $(file)