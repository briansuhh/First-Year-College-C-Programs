#include <stdio.h>

// Create a program that will sort 3 integers in descending order

// 18
// You are a teen-ager

int main(){
    int num1, num2, num3;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Please enter 3 integers:    ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 > num2 && num1 > num3)
    {
        if (num2 > num3)
        {
            printf("\nThe descending order is %d %d %d", num1, num2, num3);
        }
        if (num3 > num2)
        {
            printf("\nThe descending order is %d %d %d", num1, num3, num2);
        }
    }

    if (num2 > num1 && num2 > num3)
    {
        if (num1 > num3)
        {
            printf("\nThe descending order is %d %d %d", num2, num1, num3);
        }
        if (num3 > num1)
        {
            printf("\nThe descending order is %d %d %d", num2, num3, num1);
        }
    }

    if (num3 > num1 && num3 > num2)
    {
        if (num1 > num2)
        {
            printf("\nThe descending order is %d %d %d", num3, num1, num2);
        }
        if (num2 > num1)
        {
            printf("\nThe descending order is %d %d %d", num3, num2, num1);
        }
    }

        
    return 0;
}

