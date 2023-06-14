#include <stdio.h>

// Create a program with a function that will return 0 if it is a prime number and 1 if not
// 4
// 4 is not a prime number

int prime(num){   
    if (num < 2)
        return 1;

    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return 1; 
    return 0; 
}

int main()
{
    int num;

    printf("This program evaluates the number if it is a prime number or not.\n");

    while(1){
        printf("\n\nPlease, enter a non-negative integer: ");
        scanf("%d", &num);
        if (num < 0)
            printf("\nInvalid input! Please, enter a non-negative integer.\n");
        else
            printf("\n%d is %s\n", num, prime(num) == 0 ? "a prime number." : "not a prime number.");
    }
    return 0;
}

