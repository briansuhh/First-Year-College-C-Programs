#include <stdio.h>

// Create a program that will call a function DWARF to determine if the integer is DWARF or NOT. 
// DWARF = sum of its factors is greater than half of the number
// 6
// 1 2 3
// 1 + 2 + 3 = 6
// 6 is a DWARF

int DWARF(int num, int sum) 
{
    if (sum > num/2)
        printf("\n%d is a DWARF\n", num);
    else
        printf("\n%d is NOT a DWARF\n", num);

    // (sum > num/2) ? printf("\n%d is a DWARF\n", num) : printf("\n%d is NOT a DWARF\n", num);
}

int main()
{
    int num, sum = 0;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Please enter a non-negative integer:    ");
    scanf("%d", &num);
    printf("\n%s, the factors of %d are ", name, num);

    //Get the factors of the inputted number
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            printf("%d ", i);
            sum = sum + i;
        }     
    }

    printf("\nThe sum of its factors is %d \n", sum);
    DWARF(num, sum);
    
    return 0;
}

