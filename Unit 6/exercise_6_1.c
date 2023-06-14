#include <stdio.h>

// Create a program with a function that will return the factorial of the inputted number
// 3!
// 3 x 2 x 1 = 6

long double factorial(long double num){
    long double product = 1;
    
    printf("\nThe result of !%1.0Lf is ", num);
    for (int i = num; i > 0; i--){ 
        printf("%d%s", i, (i != 1) ? " x ": " = "); 
        product *= i; 
    }
    return product; 
}

int main(){
    long double num;

    printf("This program calculates the factorial of a non-negative integer. \n");
    
    // Ask the user to input a non-negative integer and keep asking until a valid input is entered
    do{
        printf("\n\nPlease, enter a non-negative integer: ");
        scanf("%Lf", &num);
        if (num < 0)
            printf("\nInvalid input! Please, enter a non-negative integer.\n");
        else
            printf("%1.0Lf\n", factorial(num));
    }while(num <= 0);

    return 0;
}

