// /*
// Author: Group 9 (Bantolino, Buga-ay, Camacho, Lerit, Sebastian)
// Date of Completion: May 5, 2023
// Professor: Lydinar Dastas
// */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

int main () {
    int choice;

    do {
        printf("MENU:\n");
        printf("1. Sudoku Version 1\n");
        printf("2. Sudoku Version 2\n");
        printf("3. Sudoku Version 3\n");
        printf("4. Sudoku Final Version\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sudoku_v1();
                break;
            case 2:
                sudoku_v2();
                break;
            case 3:
                sudoku_v3();
                break;
            case 4:
                sudoku_final();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");

    } while (choice != 4);

}