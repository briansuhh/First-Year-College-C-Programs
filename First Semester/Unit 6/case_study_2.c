#include <stdio.h>

//Create a program that evaluates the type of triangle based on the 3 sides the user inputted
// 4 4 6
//Isosceles

//Determines the type of triangle
void triangle(int a, int b, int c) {
    if (a == b && b == c) 
        printf("The triangle is equilateral.\n");
    else if (a == b || b == c || c == a) 
        printf("The triangle is isosceles.\n");
    else 
        printf("The triangle is scalene.\n");
}

int main() {
    int a, b, c;
    printf("This program determines whether the given three sides of a triangle are equilateral, isosceles, or scalene.\n\n");

    while(1){
        printf("\nPlease enter 3 sides of a triangle separated with a space: ");
        scanf("%d %d %d", &a, &b, &c);
        triangle(a, b, c);
    }
    return 0;
}
