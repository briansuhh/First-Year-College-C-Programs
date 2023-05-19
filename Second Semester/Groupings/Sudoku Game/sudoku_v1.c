#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sudoku_v1() {
    int sudokuBlock[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}   
    };

    printf("This is a Sudoku Game Program created by Group 9.\n");

    // To create a randomized numbers for the 6 presets from 1 to 9
    int preset[6];
    srand(time(NULL));  
    for(int i=0; i<6; i++) {
        int num;
        do {
            num = rand() % 9 + 1;  // TO generate a random number from 1 to 9
        } while (num == preset[0] || num == preset[1] || num == preset[2] ||
                 num == preset[3] || num == preset[4] || num == preset[5]);
        preset[i] = num;
    }

    // To fill in the preset numbers into the sudoku block
    sudokuBlock[0][0] = preset[0];
    sudokuBlock[0][1] = preset[1];
    sudokuBlock[0][2] = preset[2];
    sudokuBlock[1][0] = preset[3];
    sudokuBlock[1][1] = preset[4];
    sudokuBlock[1][2] = preset[5];
    
    // To display the partially filled sudoku block
    printf("Sudoku Grid:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", sudokuBlock[i][j]);
        }
        printf("\n");
    }

    int num1, num2, num3;
    while(1){
        // To ask user to input three numbers
        printf("\nEnter three numbers to complete the Sudoku grid:\n");
        printf("Number 1: ");
        scanf("%d", &num1);
        printf("Number 2: ");
        scanf("%d", &num2);
        printf("Number 3: ");
        scanf("%d", &num3);

        // To check if the user inputted a number higher than 9
        if(num1 > 9 || num2 > 9 || num3 > 9){
            printf("Please input a number from 1 to 9.\n");
            continue;
        } 

        //To check if the user inputted a number that is already in the sudoku block
        int isDuplicate = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(sudokuBlock[i][j] == num1 || sudokuBlock[i][j] == num2 || sudokuBlock[i][j] == num3){
                    printf("Error: Number %d is already in the grid\n", sudokuBlock[i][j]);
                    isDuplicate = 1;
                }
                    
            }
        }

        // To continue looping if there is a duplicate
        if(isDuplicate == 1)
            continue;

        // To break the loop if there is no error
        break;
    }    

    // To fill in the 3 empty spaces in the sudoku block
    sudokuBlock[2][0] = num1;
    sudokuBlock[2][1] = num2;
    sudokuBlock[2][2] = num3;

    // To display the completed grid
    printf("\n\nCompleted Sudoku Grid:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", sudokuBlock[i][j]);
        }
        printf("\n");
    }
}
