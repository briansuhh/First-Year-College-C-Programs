#include <stdio.h>

int main()
{
    int num, exponent;
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
        if (num % i == 0) 
        {
            exponent = 0;
            while (num % i == 0) //updating the value of num by dividing it multiple times without printing 
            {
                exponent++;
                num /= i;
            }
            if (1)
            {
                printf("%d^%d ", i, exponent);
                if(num > 1)
                    printf("and ");
            }
        }            
    }
          
    return 0;
}

