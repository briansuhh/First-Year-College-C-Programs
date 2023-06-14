#include <stdio.h>

// Create a program that calculates the sum, difference, product, quotients and the sum of squares of the 3 integers inputted by the user
// IPO
// 2 3 5
// 2 + 3 + 5
// 2 - 3 - 5
// 2 * 3 * 5
// 2 / 3 / 5
// (2 * 2) + (3 * 3) + (5 * 5)
// 10
// -6
// 30
// 0.13
// 38

int main(){
    float a, b, c, sum, diff, prod, quot, sum_square;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Enter 3 numbers:    ");
    scanf("%f %f %f", &a, &b, &c);
    
    sum = a + b + c;
    diff = a - b - c;
    prod = a * b * c;
    quot = a / b / c;
    sum_square = (a * a) + (b * b) + (c * c);
    
    printf("\n%s, the results of the numbers %g, %g, and %g are stated below:\n\n", name, a, b, c);
    printf("The sum is %g\n", sum);
    printf("The difference is %g\n", diff);
    printf("The product is %g\n", prod);
    printf("The quotient is %g\n", quot);
    printf("The sum  of squares is %g", sum_square);
    
    return 0;
}
