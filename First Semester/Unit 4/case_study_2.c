#include <stdio.h>

// Create a program that will get the factorial of the inputted number
// 3!
// 3 x 2 x 1 = 6

int main()
{
    int num;
    int product = 1;
    char name[80];

    // printf("Please input your name:    ");
    // scanf("%s", name);
    printf("Please enter a non-negative integer:    ");
    scanf("%d", &num);

    if (num < 0)
        printf("Please input a positive integer");
    if (num > 0)
    {
        for (int i = num; i >= 1; i--) 
        {   
            printf("%d", i);
            product = product * i;
            printf("%s", (i != 1) ? " x " : " ");
        }
        printf("is equals to %d", product);
    }
    else
        printf("0 is equals to %d", product);
    
    return 0;
}

