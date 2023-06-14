#include <stdio.h>

// Create a program that will display the prime factors of the given non-negative integer.

// 15
// 3 5

int main()
{
    int num;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Please enter a non-negative integer:    ");
    scanf("%d", &num);
    printf("\n%s, the prime factors of %d are ", name, num);

    // Continue to divide by 2 if it is divisible by 2 and iterate 1 to the divisor if it is not divisible  by 2 
    // Update the number by the answer to the looped division
    for (int i = 2; num != 1; i++)
    {
        while (num % i == 0)
        {
            printf("%d", i);
            num /= i; // num = num / i
            if (num != 1)
                printf(" ");
            else
                printf("\n");
        }
                
    }
          
    return 0;
}

