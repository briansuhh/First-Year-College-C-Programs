#include <stdio.h>

int sudoku[9][9] = {0};

// Stylization functions
void line(){printf("\n-----------------------------------------------------");}
void line1(){printf("-----------------------------------------------------");}
void verticalBorder(){printf("\n     \033[32m-------------  -------------  -------------\033[0m\n");}
void grid(int j){printf("%s", j == 0 ? "     \033[32m|\033[0m" : "");}
void grid1(int j){printf("%s", j < 9 ? "\033[32m|\033[0m" : "");}

void printSudoku(){
    for (int i = 0; i < 9; i++) {
        verticalBorder();
        for (int j = 0; j < 9; j++) {
            grid(j);
                printf("%s %d %s", 
                    (sudoku[i][j] == 0) ? "\033[34m" : "\033[32m", 
                    sudoku[i][j], 
                    (sudoku[i][j] == 0) ? "\033[0m" : "\033[0m");
            grid1(j);
            if (j == 2 || j == 5) {
                {printf("%s", j < 9 ? "\033[32m  |\033[0m" : "");}
            }
        }
        if (i == 2 || i == 5) {
            {printf("\n     \033[32m-------------  -------------  -------------\033[0m");}
        }
        
    }
    verticalBorder(); 
}

int sameColumn(int x, int y, int num) {
    
    for (int i = 0; i < 9; i++) {
        if (sudoku[x][i] == num) {
            return 1;
        } 
    }

    return 0;
}

int sameRow(int x, int y, int num) {
    
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][y] == num) {
            return 1;
        }
    }

    return 0;
}

int sameSquare(int x, int y, int num) {

    // Check which square of the sudoku board the x-coordinate belongs to
    if (x < 3) {
        x = 0;
    } else if (x < 6) {
        x = 3;
    } else {
        x = 6;
    }

    // Check which square of the sudoku board the x-coordinate belongs to
    if (y < 3) {
        y = 0;
    } else if (y < 6) {
        y = 3;
    } else {
        y = 6;
    }

    // Check the 3x3 sudoku block
    for (int i = x; i < x+3; i++) {
        for (int j = y; j < y+3; j++) {
            if (sudoku[i][j] == num) {
                return 1;
            }
        }
    }

    return 0;
}

int solveSudoku(int x, int y) {
    
    int num = 1;
    int tx = 0;
    int ty = 0;

    // Check if current cell is already filled
    if (sudoku[x][y] != 0) {
        // If last cell, return 1 (solution found)
        if (x == 8 && y == 8) {
            return 1;
        }

        // Move to next cell
        if (x < 8) {
            x++;
        }
        else {
            if (y < 8) {
                x = 0;
                y++;
            }
        }

        // Continue solving recursively
        if (solveSudoku(x, y)) {
            return 1;
        }
        else {
            return 0;
        }
    }

    
    // If current cell is empty, try filling it with numbers 1-9
    if (sudoku[x][y] == 0) {
        while (num < 10) {
            // Check if num/input is a valid solution for the current cell
            if (!sameSquare(x, y, num) && !sameRow(x, y, num) && !sameColumn(x, y, num)) {
                sudoku[x][y] = num;

                // If last cell, return 1 (solution found)
                if (x == 8 && y == 8) {
                    return 1;
                }

                // Move to next cell
                if (x < 8) {
                    tx = x + 1;
                }
                else {
                    if  (y < 8) {
                        tx = 0;
                        ty = y + 1;
                    }
                }

                // Continue solving recursively
                if (solveSudoku(tx, ty)) {
                    return 1;
                }
            }
            num++;
        }
        // If no valid solution is found, backtrack and try a different number in the previous cell
        sudoku[x][y] = 0;
        return 0;
    }
}

int main() {   
    
    int userChoice;
    line(); printf("\n\t\t    \033[33mSudoku Solver\033[0m\n"); line1();
    do {
        int x = 0, y = 0, numElements, input = 0, count = 0, row, col;

        printSudoku();
        printf("\n\nThe instructions are as follows:");
        printf("\n1. Enter how many numbers you want to insert in the \n   empty sudoku table");
        printf("\n2. Enter the numbers you want to insert.");
        printf("\n3. Enter the positions where you want to place each \n   number.");
        
        do {
            printf("\n\nHow many numbers do you want to insert? [1 - 8]:   ");
            scanf("%d", &numElements);
    
            if (numElements > 8 || numElements < 1) {
                printf("Please enter a number between 1 and 8");
            }
        }while(numElements > 8 || numElements < 1);
    
        while(count < numElements){
            do {
                printf("\n\nEnter a number you want to insert. [1 - 9]\n");
                printf("Number %d: ", count + 1);
                scanf("%d", &input);
                if (input > 9) {
                    printf("\n\033[31mPlease enter a number between 1 and 9.\033[0m\n");
                }
            }while(input > 9);
    
            do {
                printf("\nEnter the position you want to put your number. [1 - 9]\n");
                printf("Row: ");
                scanf("%d", &row);
                printf("Column: ");
                scanf("%d", &col);
                if (row > 9 || col > 9) {
                    printf("\n\033[31mPlease enter a number between 1 and 9.\033[0m\n");
                    continue;
                }
                else if (sudoku[row - 1][col - 1] != 0) {
                    printf("\n\033[31mRow %d Column %d is already occupied.\033[0m\n", row, col);
                    continue;
                }
            }while(row > 9 || col > 9 || sudoku[row - 1][col - 1] != 0);
    
            if (sameSquare(row-1, col-1, input) || sameRow(row-1, col-1, input) || sameColumn(row-1, col-1, input)) {
                printf("\n\033[31mInvalid input. Please enter a number that is not on the same row, column or block.\033[0m\n");
                continue;
            }
            
            sudoku[row - 1][col - 1] = input;
            printSudoku();
            count++;
        }
    
        solveSudoku(x, y);
    
        printf("\n\n\033[33mHere is the solved 3x3 Sudoku block:\033[0m\n");
        printSudoku();
        line();
        printf("\nDo you want to play again? (1 for Yes / 0 for No): ");
        scanf("%d", &userChoice);
        line1(); 
        
        // To reset the values of the array
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sudoku[i][j] = 0;
            }
        }
        
    }while(userChoice != 0);
    
    printf("\n\nThank you for using our program!");

    return 0;
}


// int sudoku2[9][9] = {
//  {0, 0, 3, 0, 2, 0, 6, 0, 0},
//  {9, 0, 0, 3, 0, 5, 0, 0, 1},
//  {0, 0, 1, 8, 0, 6, 4, 0, 0},
//  {0, 0, 8, 1, 0, 2, 9, 0, 0},
//  {7, 0, 0, 0, 0, 0, 0, 0, 8},
//  {0, 0, 6, 7, 0, 8, 2, 0, 0},
//  {0, 0, 2, 6, 0, 9, 5, 0, 0},
//  {8, 0, 0, 2, 0, 3, 0, 0, 9},
//  {0, 0, 5, 0, 1, 0, 3, 0, 0},
// };

// int sudoku1[9][9] = {
//     5, 3, 0, 0, 7, 0, 0, 0, 0,
//     6, 0, 0, 1, 9, 5, 0, 0, 0,
//     0, 9, 8, 0, 0, 0, 0, 6, 0,
//     8, 0, 0, 0, 6, 0, 0, 0, 3,
//     4, 0, 0, 8, 0, 3, 0, 0, 1,
//     7, 0, 0, 0, 2, 0, 0, 0, 6,
//     0, 6, 0, 0, 0, 0, 2, 8, 0,
//     0, 0, 0, 4, 1, 9, 0, 0, 5,
//     0, 0, 0, 0, 8, 0, 0, 7, 9
// };