#include <stdio.h>
#include <stdlib.h>

// Members
// Bantolino, Elton Jhon B.
// Buga-ay, Carl Tristan V.
// Camacho, Rommel Jr. T.
// Lerit, Jezreel Anne B.
// Sebastian, Brian May E.

// Direct Address
#include "Calculator Functions\addition.c"
#include "Calculator Functions\subtraction.c"
#include "Calculator Functions\multiplication.c"
#include "Calculator Functions\division.c"

int main() {   
    
    int choice; 

    do {

        system("cls");

        printf("--------------------------------------------------------\n");
        printf("\t\t    \033[33mMDAS Calculator\033[0m\n");
        printf("--------------------------------------------------------\n");
  
        printf("\nThe instructions are as follows:");
        printf("\n1. Choose any math operation from the Main Menu.");
        printf("\n2. Input two numbers for the chosen operation.");
        printf("\n3. Pick between 0 and 1. \n(0 to go back to Main Menu / 1 to repeat the operation)\n");

        printf("\nMENU:\n");
        printf("[1] Multiplication\n");
        printf("[2] Division\n");
        printf("[3] Addition\n");
        printf("[4] Subtraction\n");
        printf("[5] Quit\n");

        while (1) {
            printf("\nEnter your choice (1-5): \t\t");

            if (scanf("%d", &choice) != 1) {
                printf("\n\033[31mInvalid input. Please enter a number.\033[0m\n\n");
                while (getchar() != '\n'); // Clear input buffer
            } else {
                break;
            }
        }

        system("cls");

        switch (choice) {

            case 1:
                multiplication();
                break;
            case 2:
                division();
                break;
            case 3:
                addition();
                break;
            case 4:
                subtraction();
                break;
            case 5:
                break;
        }

            printf("\n");

    } while (choice != 5);
    
    printf("\033[33mThank you for using our program!\033[0m\n\n");

    return 0;
}
