#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

void sudoku_v3(){
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
    
        printSudokuBlock(sudokuBlock, row, col);
        
        time_t start_time = time(NULL);
        userInput1(sudokuBlock);
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
