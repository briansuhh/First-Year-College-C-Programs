#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

void sudoku_v2(){
    int sudokuBlock[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}}, userChoice;
    line();
    printf("\nThis is a Sudoku Game Program created by Group 9.\n");
    line1();
    do{
        randomPreset(sudokuBlock);
    
        partialSudokuBlock(sudokuBlock);
    
        userInput(sudokuBlock);

        completeSudokuBlock(sudokuBlock);
        
        // Loop through the program if the user wants to sort again
        line();
        printf("\nDo you want to play again? (1 for Yes / 0 for No): ");
        scanf("%d", &userChoice);
        line1();
        removeFill(sudokuBlock);
        
    }while(userChoice != 0);
    printf("\n\nThank you for using our program!");
}

/*
Color codes if you want to customize
\033[30m - black
\033[31m - red
\033[32m - green
\033[33m - yellow
\033[34m - blue
\033[35m - magenta
\033[36m - cyan
\033[37m - white
*/