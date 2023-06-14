#include <stdio.h>

// Write a program that accepts a positive integer and gives its prime factorization, that expresses the integer as a product of primes. 

// 15
// 3 x 5 = 15

int main()
{
    int num;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Please enter a non-negative integer:    ");
    scanf("%d", &num);
    printf("\n%s, %d = ", name, num);

    // Continue to divide by 2 if it is divisible by 2 and iterate 1 to the divisor if it is not divisible  by 2 
    // Update the number by the answer to the looped division
    
    for (int i = 2; num != 1; i++)
    {
        while (num % i == 0)
        {
            printf("%d", i);
            num /= i; // num = num / i
            if (num != 1)
                printf(" x ");
            else
                printf("\n");
        }
                
    }
          
    return 0;
}



    // same result but different loop syntax (while and do-while)
    
    // while(num != 1)
    // {
    //     while (num % i == 0)
    //     {
    //         printf("%d", i);
    //         num /= i; // num = num / i
    //         if (num != 1)
    //             printf(" x ");
    //         else
    //             printf("\n");
    //     }
    //     i++;
    // }
    
    // do
    // {
    //     while (num % i == 0)
    //     {
    //         printf("%d", i);
    //         num /= i; // num = num / i
    //         if (num != 1)
    //             printf(" x ");
    //         else
    //             printf("\n");
    //     }
    //     i++;
    // }while(num != 1);
