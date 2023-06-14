#include <stdio.h>
#include <math.h>

// Create a program that display all the numbers from the given range that are disible by the given number
// Also count the total of numbers from the result
// 4 to 12 divisible by 4
// 4 8 12
// A total of 3 numbers

int main(){
    int range1, range2, m;
    int num1, num2, num3;
    int count = 0;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Please enter the range for your integer:    ");
    scanf("%d %d", &range1, &range2);
    printf("Please input the divisor for your set of numbers:    ");
    scanf("%d", &m);
    
    printf("\n%s, the numbers from %d to %d that are divisible by %d are ", name, range1, range2, m);

    for (range1; range1 <= range2; range1++)
        {
            if (range1 % m == 0)
            {
                printf("%d ", range1);
                count++;
            }               
        }

    printf("\nA total of %d numbers", count);
    
    return 0;
}
