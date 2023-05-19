/*
Author: Group 9 (Bantolino, Buga-ay, Camacho, Lerit, Sebastian)
Date of Completion: May 11, 2023
Professor: Lydinar Dastas
*/
   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Stylization functions
void line(){printf("\n-----------------------------------------------------");}
void line1(){printf("-----------------------------------------------------");}
void verticalBorder(){printf("\n\t\t    \033[32m-------------\033[0m\n");}
void grid(int j){printf("%s", j == 0 ? "\t\t    \033[32m|\033[0m" : "");}
void grid1(int j){printf("%s", j < 3 ? "\033[32m|\033[0m" : "");}

// To print the 3*3 Sudoku Block
void printSudokuBlock(int sudokuBlock[3][3]){
    for (int i = 0; i < 3; i++) {
        verticalBorder();
        for (int j = 0; j < 3; j++) {
            grid(j);
                printf("%s %d %s", 
                    (sudokuBlock[i][j] == 0) ? "\033[34m" : "\033[32m", 
                    sudokuBlock[i][j], 
                    (sudokuBlock[i][j] == 0) ? "\033[0m" : "\033[0m");
            grid1(j);
        }
    }
    verticalBorder();
}

// To print the reference for the position
void printPositionBlock(){
    int positionArray[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < 3; i++) {
        verticalBorder();
        for (int j = 0; j < 3; j++) {
            grid(j);
                printf(" %d ", positionArray[i][j]);
            grid1(j);
        }
    }
    verticalBorder();
}

// To put the numbers to their positions indicated by the user
void putInputToPositions(int sudokuBlock[3][3], int input[3], int posInput[3], int i) {
        int row = (posInput[i] - 1) / 3;
        int col = (posInput[i] - 1) % 3;
        sudokuBlock[row][col] = input[i];
        printSudokuBlock(sudokuBlock);
}

// To put the generated random numbers inside the sudokuBlock 2d array
void fillSudokuBlock(int sudokuBlock[3][3], int input[3], int numElements){
    int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int random_num, temp;
    int generatedRandom[9 - numElements], arr1d_index = 0;
    srand(time(NULL));

    // To generate random numbers
    for (int i = 0; i < (9 - numElements); i++) {
        do {
            random_num = rand() % (9 - i);
            temp = num[random_num];
            num[random_num] = num[8 - i];
            num[8 - i] = temp;
        } while (num[8 - i] == input[0] || num[8 - i] == input[1] || num[8 - i] == input[2] || num[8 - i] == input[3] || num[8 - i] == input[4] || num[8 - i] == input[5] || num[8 - i] == input[6] || num[8 - i] == input[7]);
        generatedRandom[i] = num[8 - i];
    }

    // To loop through the 2D array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // If the current element is 0, replace it with the next element from the 1D array
            if (sudokuBlock[i][j] == 0) {
                sudokuBlock[i][j] = generatedRandom[arr1d_index];
                arr1d_index++;

                // If we've filled up the 1D array, break out of the loop
                if (arr1d_index == (9 - numElements)) {
                    break;
                }
            }
        }
        // If we've filled up the 1D array, break out of the outer loop as well
        if (arr1d_index == (9 - numElements)) {
            break;
        }
    }
}

int main(){
    int userChoice;
    line(); printf("\n\t\t    \033[33mSudoku Solver\033[0m\n"); line1();
    do{
        int sudokuBlock[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        int result[6], numElements;

        printf("\n\nThe instructions are as follows:");
        printf("\n1. Enter how many numbers you want to insert in the \n   empty sudoku table");
        printf("\n2. Enter the numbers you want to insert.");
        printf("\n3. Enter the positions where you want to place each \n   number.");
        printf("\n\nFor reference, here are the positions of each number \nin the Sudoku block.");
        printPositionBlock();

        do{
            printf("\n\nHow many numbers do you want to insert? [1 - 8]:   ");
            scanf("%d", &numElements);

            if (numElements > 8 || numElements < 1) {
                printf("Please enter a number between 1 and 8");
            }
        }while(numElements > 8 || numElements < 1);
        
        printSudokuBlock(sudokuBlock);
        int input[numElements], posInput[numElements];
        for(int i = 0; i < numElements; i++){
            
            printf("\n\nEnter a number you want to insert. [1 - 9]\n");
            printf("Number %d: ", i+1);
            scanf("%d", &input[i]);

            printf("\nEnter the position you want to put your number. [1 - 9]\n");
            printf("Position: ");
            scanf("%d", &posInput[i]);

            // To check if the user inputted a number higher than 9
            if(input[i] > 9 || posInput[i] > 9){
                printf("\n\033[31mPlease enter a number between 1 and 9.\033[0m\n");
                i--;
                continue;
            }  

            // To check if the position is already occupied
            if (sudokuBlock[(posInput[i] - 1) / 3][(posInput[i] - 1) % 3] != 0){
                printf("\n\033[31mPosition %d is already occupied.\033[0m\n", posInput[i]);
                i--;
                continue;
            }  
    
            //To check if the user inputted a number that is already in the sudoku block
            int isDuplicate = 0;
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++){
                    if(sudokuBlock[j][k] == input[i]){
                        printf("\n\033[31mNumber %d is already in the Sudoku block.\033[0m\n", sudokuBlock[j][k]);
                        isDuplicate = 1;
                    }
                }
            }
            
            // To continue looping if there is a duplicate
            if(isDuplicate == 1){
                i--;
                continue;    
            }
    
            putInputToPositions(sudokuBlock, input, posInput, i);
            
        }
        
        fillSudokuBlock(sudokuBlock, input, numElements);
        printf("\n\n\033[33mHere is the solved 3x3 Sudoku block:\033[0m\n");
        printSudokuBlock(sudokuBlock);

        line();
        printf("\nDo you want to play again? (1 for Yes / 0 for No): ");
        scanf("%d", &userChoice);
        line1();
    }while(userChoice != 0);
    
    printf("\n\nThank you for using our program!");

    return 0;
}

