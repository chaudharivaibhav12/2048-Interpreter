Here I have already made the code for the makefile.

Just execute the following command on the Terminal.

Terminal:
>make clean (Use this command to clean the unnecessary temporary files)
>make
>./2048 2>stderr.txt (This will redirect the stderr command to an external output file for easier checking)

Using the last command will open the 2048 Interpreter.

I have taken care of the Syntax Error along with the few extra test cases. 
The stderr output is also displayed in the terminal. Please have a look at the code for more detail. 

The Code Explanation:

The lex.l file is the lexer file. Here I have made extra REGEX for handling the Add Left syntax error.

The parser.y file is the parser file. Here I have used different CFG's to make my implementation better. 
I have included the game.h header file so that I can use the functionality of the game.c file in the parser.y file.
I have called different functions at different rules to make the program work.
I have written two rules of the same type, one ending with '.' and others without '.' so I can use the You need to add full stop thing.

The game.c file is self-explanatoy as these functions are used for the functioning of the game.

The makefile has commands to compile all this.

The game.h is the header file for all functions in game.c.
