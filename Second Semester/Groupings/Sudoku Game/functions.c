#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Functions for version 2
// Stylization functions
void line(){printf("\n-----------------------------------------------------");}
void line1(){printf("-----------------------------------------------------");}
void verticalBorder(){printf("\n\t\t\t\t\t\033[32m-------------\033[0m\n");}
void grid(int j){printf("%s", j == 0 ? "\t\t\t\t\t\033[32m|\033[0m" : "");}
void grid1(int j){printf("%s", j < 3 ? "\033[32m|\033[0m" : "");}

void randomPreset(int sudokuBlock[3][3]){
    // To create a randomized numbers for the 6 presets from 1 to 9
    int preset[6];
    srand(time(NULL));  
    for(int i=0; i<6; i++) {
        int num;
        do {
            num = rand() % 9 + 1;
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
}

void sudokuGrid(int sudokuBlock[3][3]){
    for(int i = 0; i < 3; i++){
        verticalBorder();
        for(int j = 0; j < 3; j++){
            grid(j);
            printf("%s %d %s", i == 2 && j < 3 ? "\033[34m" : "\033[32m", sudokuBlock[i][j], i == 2 && j < 3 ? "\033[0m" : "\033[0m");
            grid1(j);
        }
    }
    verticalBorder();
}

void partialSudokuBlock(int sudokuBlock[3][3]){
    // To display the partially filled sudoku block
    printf("\n\nPartially Filled Sudoku Block:\n");
    sudokuGrid(sudokuBlock);
}

void userInput(int sudokuBlock[3][3]){
    int num[3];
    for(int i = 0; i < 3; i++){
        printf("\nEnter three numbers to complete the Sudoku block:\n");
        printf("Number %d: ", i+1);
        scanf("%d", &num[i]);
        
        // To check if the user inputted a number higher than 9
        if(num[i] > 9){
            printf("\nPlease input a number from 1 to 9.\n");
            i--;
            continue;
        } 
    
        //To check if the user inputted a number that is already in the sudoku block
        int isDuplicate = 0;
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++){
                if(sudokuBlock[j][k] == num[i]){
                    printf("%sError: Number %d is already in the Sudoku block\n", (sudokuBlock[j][k] == num[i]) ? "\n" : "", sudokuBlock[j][k]);
                    isDuplicate = 1;
                }
            }
        }
    
        // To continue looping if there is a duplicate
        if(isDuplicate == 1){
            i--;
            continue;
            
        }
        sudokuBlock[2][i] = num[i];
        sudokuGrid(sudokuBlock);
    }
}

void completeSudokuBlock(int sudokuBlock[3][3]){
    // To display the completed sudoku block
    printf("\n\n\033[31mCongratulations! You have successfully solved the 3x3 Sudoku puzzle.\033[0m\n");
    sudokuGrid(sudokuBlock);
}

void removeFill(int sudokuBlock[3][3]){
    // To remove the numbers that are already filled up in the empty spaces
    sudokuBlock[2][0] = 0;
    sudokuBlock[2][1] = 0;
    sudokuBlock[2][2] = 0;
}

// Functions for version 3
void randomPreset1(int result[]){
    int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int random_num, temp;
    srand(time(NULL));  // initialize random seed using current time
    
    for (int i = 0; i < 6; i++) {
        random_num = rand() % (9 - i);  // generate random index from 0 to 8 - i
        temp = num[8 - i];  // swap selected number with last element of array
        num[8 - i] = num[random_num];
        num[random_num] = temp;
        result[i] = num[8 - i];
    }
}

void randomPosition(int result[], int sudokuBlock[3][3]){
    int random_index, temp, row, col;
    int indices[] = {0, 1, 2, 10, 11, 12, 20, 21, 22};
    for (int i = 0; i < 6; i++) {
        random_index = rand() % (9 - i);
        temp = indices[8 - i];
        indices[8 - i] = indices[random_index];
        indices[random_index] = temp;
        row = indices[8 - i] / 10;
        col = indices[8 - i] % 10;
        sudokuBlock[row][col] = result[i];
    }
}

void printSudokuBlock(int sudokuBlock[3][3], int row, int col){
    for (int i = 0; i < 3; i++) {
        verticalBorder();
            for (int j = 0; j < 3; j++) {
                grid(j);
                if (i == row && j == col) {
                    printf("%s %d %s", "\033[34m", sudokuBlock[i][j], "\033[0m");
                } else {
                    printf("%s %d %s", (sudokuBlock[i][j] == 0) ? "\033[34m" : "\033[32m", sudokuBlock[i][j], (sudokuBlock[i][j] == 0) ? "\033[0m" : "\033[0m");
                }
                grid1(j);
            }
        }
    verticalBorder();
}

void replaceZerosWithInputs(int sudokuBlock[3][3], int input[3]) {
    int inputIndex = 0;
    int row = -1, col = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudokuBlock[i][j] == 0) {
                row = i;
                col = j;
                sudokuBlock[i][j] = input[inputIndex];
                inputIndex++;
                printSudokuBlock(sudokuBlock, row, col);
            }
        }
    }
}

void userInput1(int sudokuBlock[3][3]){
    int input[3], a, b;
    for(int i = 0; i < 3; i++){
        printf("\nEnter three numbers to complete the Sudoku block:\n");
        printf("Number %d: ", i+1);
        scanf("%d", &input[i]);
        
        // To check if the user inputted a number higher than 9
        if(input[i] > 9){
            printf("\nPlease input a number from 1 to 9.\n");
            i--;
            continue;
        }  

        //To check if the user inputted a number that is already in the sudoku block or in previous inputs
        int isDuplicate = 0;
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++){
                if(sudokuBlock[j][k] == input[i]){
                    printf("\nError: Number %d is already in the Sudoku block\n", sudokuBlock[j][k]);
                    isDuplicate = 1;
                }
            }
        }
        for(int j=0; j<i; j++) {
            if(input[j] == input[i]){
                printf("\nError: Number %d has already been entered\n", input[j]);
                isDuplicate = 1;
            }
        }
        
        // To continue looping if there is a duplicate
        if(isDuplicate == 1){
            i--;
            continue;    
        }
        
        if (i == 2) {
            replaceZerosWithInputs(sudokuBlock, input);
        }

    }
}

void printTimeTaken(time_t start, time_t end) {
    int elapsed_time = (int) difftime(end, start);
    int minutes = elapsed_time / 60;
    int seconds = elapsed_time % 60;
    printf("\n\033[31mYour total completion time is %d minute%s and %d seconds.\033[0m\n", minutes, (minutes > 1) ? "s" : "", seconds);
}

// Functions for the final version
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

void userInput2(int sudokuBlock[3][3]){
    int input[3], a, b, posInput[3];

    for(int i = 0; i < 3; i++){
        printf("\n\nEnter three numbers to complete the Sudoku block:\n");
        printf("Number %d: ", i+1);
        scanf("%d", &input[i]);
        printf("\nEnter the position you want to put your number.\n");
        printf("Position: ");
        scanf("%d", &posInput[i]);

        // To check if the user inputted a number higher than 9 or if the position is already occupied
        if(input[i] > 9 || sudokuBlock[(posInput[i]-1)/3][(posInput[i]-1)%3] != 0){
            printf("\nPlease input a number from 1 to 9 and make sure the position is not already occupied.\n");
            i--;
            continue;
        }  

        //To check if the user inputted a number that is already in the sudoku block or in previous inputs
        int isDuplicate = 0;
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++){
                if(sudokuBlock[j][k] == input[i]){
                    printf("\nError: Number %d is already in the Sudoku block\n", sudokuBlock[j][k]);
                    isDuplicate = 1;
                }
            }
        }
        for(int j=0; j<i; j++) {
            if(input[j] == input[i]){
                printf("\nError: Number %d has already been entered\n", input[j]);
                isDuplicate = 1;
            }
        }
        
        // To continue looping if there is a duplicate
        if(isDuplicate == 1){
            i--;
            continue;    
        }
        
        if (i == 2) {
            replaceZerosWithInputs(sudokuBlock, input);
        }
    }
}

