%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include "game.h"
	char operation;
	char direction;
	int count=0;
%}

%token ADD
%token SUBTRACT
%token MULTIPLY
%token DIVIDE
%token LEFT 
%token RIGHT 
%token UP
%token DOWN
%token add
%token subtract
%token multiply
%token divide
%token left 
%token right 
%token up
%token down
%token ASSIGN
%token TO 
%token VAR
%token IS
%token VALUE
%token IN 
%token TERMINATOR
%token<number> NUMBER
%token SEPARATOR
%token EOL
%token<string> VARNAME



%union{
	int number;
	char string[100];
}

%%

program: line program | line
;

KEYWORD: OP | DIRECTION | ASSIGN | TO | VAR | IS | VALUE | IN | TERMINATOR | NUMBER | SEPARATOR | EOL
;

op: add | multiply | subtract | divide
;

direction: left | right | up | down
;

OP: ADD {operation = '+';} 
| MULTIPLY {operation = '*';} 
| SUBTRACT {operation = '-';} 
| DIVIDE {operation = '/';} 
;

DIRECTION: LEFT {direction = 'l';}
| UP {direction = 'u';}
| DOWN {direction = 'd';}
| RIGHT {direction = 'r';}
;

line: op direction EOL { fprintf(stderr, "-1\n");
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("Syntax error.\n");
	printf("\033[33;1m");
	printf("----> ");
	printf("\033[0m");
	}
	
| op direction TERMINATOR EOL { fprintf(stderr, "-1\n");
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("Syntax error.\n");
	printf("\033[33;1m");
	printf("----> ");
	printf("\033[0m");}
	
| OP DIRECTION EOL { fprintf(stderr, "-1\n"); 
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("You need to end a command with a full-stop.\n");
	printf("\033[33;1m");
	printf("----> ");
	printf("\033[0m");}
	
| ASSIGN NUMBER TO NUMBER SEPARATOR NUMBER EOL { fprintf(stderr, "-1\n"); 
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("You need to end a command with a full-stop.\n");
	printf("\033[33;1m");
	printf("----> ");
	printf("\033[0m");}
| VALUE IN NUMBER SEPARATOR NUMBER EOL { fprintf(stderr, "-1\n"); 
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("You need to end a command with a full-stop.\n");
	printf("\033[33;1m");
	printf("----> ");
	printf("\033[0m");}
| VAR VARNAME IS NUMBER SEPARATOR NUMBER EOL { fprintf(stderr, "-1\n"); 
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("You need to end a command with a full-stop.\n");
	printf("\033[33;1m");
	printf("----> ");
	printf("\033[0m");}
| OP DIRECTION TERMINATOR EOL { opAndDirInput(operation, direction);}
| ASSIGN NUMBER TO NUMBER SEPARATOR NUMBER TERMINATOR EOL  { assignTile($2, $4, $6);}
| VALUE IN NUMBER SEPARATOR NUMBER TERMINATOR EOL { findValue($3, $5);}
| VAR VARNAME IS NUMBER SEPARATOR NUMBER TERMINATOR EOL  {setVarName($2, $4, $6);}
| VAR KEYWORD IS NUMBER SEPARATOR NUMBER TERMINATOR EOL { fprintf(stderr, "-1\n"); 
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("No, a keyword cannot be a variable name.\n");
	printf("\033[33;1m");
	printf("----> ");
	printf("\033[0m");}
;

%%

int yyerror(char* err)
{
	//printf("\033[33;1m2048> \033[0mSyntax error.\n");
	fprintf(stderr, "-1\n");
	yyparse();
}

int main()
{	
	srand(time(0));
	
	printInitialPrompt();
	
	//Function to instantiate the matrix with 0 values
    	instantiateMatrix();
    	
    	printPrompt();
    	
    	yyparse();
	
	return 0;

}
