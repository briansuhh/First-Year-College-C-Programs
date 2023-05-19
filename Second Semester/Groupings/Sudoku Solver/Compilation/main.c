#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sudoku3();
void sudoku9();

int main () {
    int choice;

    do {
        system("cls");
        printf("A program that can solve 3x3 and 9x9 sudoku.");
        printf("\n\nMENU:\n");
        printf("1. 3x3 Sudoku Solver\n");
        printf("2. 9x9 Sudoku Solver\n");
        printf("3. Quit\n");
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
            case 1:
                sudoku3();
                break;
            case 2:
                sudoku9();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");

    } while (choice != 3);

    printf("Thank you for using our program!");
}
