#include <stdio.h>

// Create a program that calculates the volume of the box whose dimensions are specified by the user
// IPO
// 4 5 6
// 4 * 5 * 6
// The volume is 120

int main(){
    float v, length, width, height;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Enter the length, width and height of the box accordingly:    ");
    scanf("%f %f %f", &length, &width, &height);
    
    v = length * width * height;
    
    printf("\n%s, the total volume of the box is %g", name, v);
    
    return 0;
}
