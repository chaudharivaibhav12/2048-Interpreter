#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "game.h"

int matrix[N][N];
char varName[N][N][16][100];
int nameCount[N][N];

void stderrPrintBoard()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
				fprintf(stderr, "%d ", matrix[i][j]);
		}
	}

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(nameCount[i][j]>0)
			{
				fprintf(stderr, "%d,%d", i, j);
				
				for(int k=0; k<nameCount[i][j]; k++)
				{
					if(k==0)
						fprintf(stderr, "%s", varName[i][j][k]);
					else 
						fprintf(stderr, ",%s", varName[i][j][k]);
				}
				fprintf(stderr, " ");
			}
		}
	}

	fprintf(stderr, "\n"); 
}

void instantiateMatrix()
{
	for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            matrix[i][j]=0;
        }
    }

    int pos1=randSelectTile(0);
    
    int count=0;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(count == pos1)
                matrix[i][j]=randomNumberGenerator();
            count++;
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(matrix[i][j]!=0)
            {
                printf("\033[1;31m");
                printf("%d\t",matrix[i][j]);
                printf("\033[0m");
            }
            else 
                printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

    stderrPrintBoard();
}

void printInitialPrompt()
{
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("Hi, I am the 2048-game Engine.\n");
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("The start state is:\n");
}

void printPrompt()
{
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("Please type a command.\n");
	printf("\033[33;1m");
	printf("----> ");
	printf("\033[0m");
}

int randSelectTile(int start)
{
    if(!start)
    {
        return rand()%(N*N);
    }
    return rand()%start;
}

int randomNumberGenerator()
{
    int res=rand()&1;
    if(res == 1)
        return 2;
    return 4;
}

void printBoard()
{
	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("The current state is:\n");

	for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(matrix[i][j]!=0)
            {
                printf("\033[1;31m");
                printf("%d\t",matrix[i][j]);
                printf("\033[0m");
            }
            else 
                printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}



void opAndDirInput(char op, char dir)
{
	if(dir == 'l')
	{
		leftMove(op);
	}
	else if(dir == 'r')
	{
		rightMove(op);
	}
	else if(dir == 'u')
	{
		upMove(op);
	}
	else if(dir == 'd')
	{
		downMove(op);
	}

}

void leftMove(char c)  
{
	for(int i=0; i<N; i++)
	{
		int arr[N];

		for(int j=0; j<N; j++)
		{
			arr[j]=0;
		}

		int k=0;
		for(int j=0; j<N; j++)
		{
			if(matrix[i][j])
			{
				if(arr[k-1] == matrix[i][j] && k>0)
				{
					if(c == '+')
						arr[k-1]*=2;
					else if(c == '-')
						arr[k-1]=0;
					else if(c == '*')
						arr[k-1]*=arr[k-1];
					else if(c == '/')
						arr[k-1]=1;
				}
				else
				{
					arr[k++]=matrix[i][j];
				}
			}
		}

		for(int j=0; j<N; j++)
		{
			matrix[i][j]=arr[j];
		}
	}
	
	int empty=emptySpaceChecker();
	int pos=randSelectTile(empty);
	randomNumberInserter(pos);

	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("Thanks, left move done, random tile added.\n");

	stderrPrintBoard();
	printBoard();
	printPrompt();
 
}

void rightMove(char c)
{
	for(int i=0; i<N; i++)
	{
		int arr[N];

		for(int j=0; j<N; j++)
		{
			arr[j]=0;
		}

		int k=N-1;
		for(int j=N-1; j>=0; j--)
		{
			if(matrix[i][j])
			{
				if(arr[k+1] == matrix[i][j] && k<N-1)
				{
					if(c == '+')
						arr[k+1]*=2;
					else if(c == '-')
						arr[k+1]=0;
					else if(c == '*')
						arr[k+1]*=arr[k+1];
					else if(c == '/')
						arr[k+1]=1;
				}
				else
				{
					arr[k--]=matrix[i][j];
				}
			}
		}

		for(int j=N-1; j>=0; j--)
		{
			matrix[i][j]=arr[j];
		}
	}
	
	int empty=emptySpaceChecker();
	int pos=randSelectTile(empty);
	randomNumberInserter(pos);

	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("Thanks, right move done, random tile added.\n");

	stderrPrintBoard();
	printBoard();
	printPrompt();
}

void upMove(char c)
{
	for(int i=0; i<N; i++)
	{
		int arr[N];

		for(int j=0; j<N; j++)
		{
			arr[j]=0;
		}

		int k=0;
		for(int j=0; j<N; j++)
		{
			if(matrix[j][i])
			{
				if(arr[k-1] == matrix[j][i] && k>0)
				{
					if(c=='+')
						arr[k-1]*=2;
					else if(c == '-')
						arr[k-1]=0;
					else if(c == '*')
						arr[k-1]*=arr[k-1];
					else if(c == '/')
						arr[k-1]=1;
				}
				else
				{
					arr[k++]=matrix[j][i];
				}
			}
		}

		for(int j=0; j<N; j++)
		{
			matrix[j][i]=arr[j];
		}
	}
	
	int empty=emptySpaceChecker();
	int pos=randSelectTile(empty);
	randomNumberInserter(pos);

	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("Thanks, up move done, random tile added.\n");

	stderrPrintBoard();
	printBoard();
	printPrompt();

}

void downMove(char c)
{
	for(int i=0; i<N; i++)
	{
		int arr[N];

		for(int j=0; j<N; j++)
		{
			arr[j]=0;
		}

		int k=N-1;
		for(int j=N-1; j>=0; j--)
		{
			if(matrix[j][i])
			{
				if(arr[k+1] == matrix[j][i] && k<N-1)
				{
					if(c == '+')
						arr[k+1]*=2;
					else if(c == '-')
						arr[k+1]=0;
					else if(c == '*')
						arr[k+1]*=arr[k+1];
					else if(c == '/')
						arr[k+1]=1;
				}
				else
				{
					arr[k--]=matrix[j][i];
				}
			}
		}

		for(int j=N-1; j>=0; j--)
		{
			matrix[j][i]=arr[j];
		}
	}
	
	int empty=emptySpaceChecker();
	int pos=randSelectTile(empty);
	randomNumberInserter(pos);

	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("Thanks, down move done, random tile added.\n");

	stderrPrintBoard();
	printBoard();
	printPrompt();
}

int emptySpaceChecker()
{
	int count=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(matrix[i][j] == 0)
                count++;
        }
    }
    return count;
}

void randomNumberInserter(int pos)
{
	int count=0;

    int numberInserted=randomNumberGenerator();

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(matrix[i][j] == 0)
            {
                if(count == pos)
                    matrix[i][j]=numberInserted;
                
                count++;
            }
        }
    }
}

void assignTile(int no, int x, int y)
{
	if(no<=0)
	{
		printf("\033[33;1m");
		printf("2048> ");
		printf("\033[0m");
		printf("Cannot assign a negative value to a tile.\n");
		fprintf(stderr, "-1\n");
		printPrompt();
		return ;
	}

	if(x>N || x<1 || y>N || y<1 )
	{
		printf("\033[33;1m");
		printf("2048> ");
		printf("\033[0m");
		fprintf(stderr, "-1\n");
		printf("There is no tile like that. The tile co-ordinates must be in the range 1,2,3,4.\n");
		printPrompt();
		return ;
	}

	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("Thanks, assignment done.\n");
	matrix[x-1][y-1]=no;

	stderrPrintBoard();
	printBoard();
	printPrompt();
}

void setVarName(char name[], int x, int y)
{
	if(matrix[x-1][y-1]==0)
	{
		printf("No Tile at that location.\n");
		fprintf(stderr, "-1\n");
		printPrompt();
		return ;
	}

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			for(int k=0; k<nameCount[i][j]; k++)
			{
				if(!strcmp(varName[i][j][k], name))
				{
					printf("\033[33;1m");
					printf("2048> ");
					printf("\033[0m");
					printf("Tile with same name already exists.\n");
					fprintf(stderr, "-1\n");
					printPrompt();
					return ;
				}
			}
		}
	}

	strcpy(varName[x][y][nameCount[x][y]++], name);

	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("Thanks, naming done.\n");

	stderrPrintBoard();
	printPrompt();

}

void findValue(int x, int y)
{
	if(x>N || x<1 || y>N || y<1 )
	{
		printf("\033[33;1m");
		printf("2048> ");
		printf("\033[0m");
		printf("There is no tile like that. The tile co-ordinates must be in the range 1,2,3,4.\n");
		fprintf(stderr, "-1\n");
		return ;
	}

	if(matrix[x-1][y-1]==0)
	{
		printf("No Tile at that location.\n");
		fprintf(stderr, "-1\n");
		printPrompt();
		return ;
	}

	printf("\033[33;1m");
	printf("2048> ");
	printf("\033[0m");
	printf("The value at %d,%d is %d.\n", x, y, matrix[x-1][y-1]);
	printPrompt();
}