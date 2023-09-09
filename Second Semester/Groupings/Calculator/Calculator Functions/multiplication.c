#include <stdio.h>

void multiplication() {

    float num1, num2, result;
    int userChoice;
    
    printf("--------------------------------------------------------\n");
    printf("\t\t   \033[33mMULTIPLICATION (*)\033[0m\n");
    printf("--------------------------------------------------------\n");

    do {

        while (1) {
            printf("\nEnter the first number: \t\t");

            if (scanf("%f", &num1) != 1) {
                printf("\n\033[31mInvalid input. Please enter a number.\033[0m\n\n");
                while (getchar() != '\n'); // Clear input buffer
            } else {
                break;
            }
        }

        while (1) {
            printf("\nEnter the second number: \t\t");

            if (scanf("%f", &num2) != 1) {
                printf("\n\033[31mInvalid input. Please enter a number.\033[0m\n\n");
                while (getchar() != '\n'); // Clear input buffer
            } else {
                break;
            }
        }

        result = num1 * num2;

        printf("\n\033[33mThe result of %s%g%s * %s%g%s is: %g\033[0m\n", 
            (num1 < 0) ? "(" : "", num1, (num1 < 0) ? ")" : "", 
            (num2 < 0) ? "(" : "", num2, (num2 < 0) ? ")" : "", 
            result);

        while (1) {
            printf("\n--------------------------------------------------------");
            printf("\nDo you want to multiply again? (1 for Yes / 0 for No): ");
            
            if (scanf("%d", &userChoice) != 1) {
                printf("--------------------------------------------------------\n");
                printf("\n\033[31mInvalid input. Please enter a number.\033[0m\n\n");
                while (getchar() != '\n'); // Clear input buffer
            } else {
                break;
            }
        }

        printf("--------------------------------------------------------\n");

    } while (userChoice != 0);

}