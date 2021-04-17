#ifndef GAME_H
#define GAME_H

//We can define N to be anything so we can have boards of different sizes
#define N 4

/* 
	Add declarations of all the required functions here
*/
//To print the matrix in stderr
void stderrPrintBoard();

void setVarName(char name[], int x, int y);

//To instantiate the initial stage of the matrix
void instantiateMatrix();

//To print the initial prompt of the game.
void printInitialPrompt();

//To print the prompt of the game.
void printPrompt();

//To select a particular tile from the board for random insertion
int randSelectTile(int start);

//To generate a random number 
int randomNumberGenerator();

//Print the state of matrix
void printBoard();

//To take input from yyparse()
void opAndDirInput(char op, char dir);

//It implements the LEFT move
void leftMove(char c);

//It implements the RIGHT move
void rightMove(char c);

//It implements the UP move
void upMove(char c);

//It implements the DOWN move
void downMove(char c);

//To check if any empty tiles are left in the matrix for random insertion
int emptySpaceChecker();

//To insert the random number generated from the function randomNumberGenerator into the matrix
void randomNumberInserter(int pos);

//To assign number to a position (x,y)
void assignTile(int number, int x, int y);

void findValue(int x, int y);

#endif
