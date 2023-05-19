#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

void sudoku_final(){
    int userChoice;
    line();
    printf("\nThis is a Sudoku Game Program created by Group 9.\n");
    line1();
    do{
        int sudokuBlock[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        int result[6];
        int row=-1, col=-1;
    
        randomPreset1(result);
        randomPosition(result, sudokuBlock);

        printf("\n\nTry to solve this 3x3 Sudoku Block. The rules are as follows:");
        printf("\n1. The 3x3 block must contain numbers from 1 to 9 without repition.");
        printf("\n2. Fill in only the empty spaces indicated by zeros with digits from 1 to 9.\n");
        printf("\n\nFor reference, here are the positions of each number in the Sudoku block.");
        
        printPositionBlock();
        printSudokuBlock(sudokuBlock, row, col);
        time_t start_time = time(NULL);
        userInput2(sudokuBlock);
        time_t end_time = time(NULL);

        printf("\n\n\033[31mCongratulations! You have successfully solved the 3x3 Sudoku puzzle.\033[0m\n");
        printTimeTaken(start_time, end_time);

        line();
        printf("\nDo you want to play again? (1 for Yes / 0 for No): ");
        scanf("%d", &userChoice);
        line1();
    }while(userChoice != 0);
    
    printf("\n\nThank you for using our program!");
}

