#include <stdio.h>

// Create a program that converts the weight of a person from Earth to Mars and Jupiter
// IPO
// 100
// 100 * 0.38
// 100 * 2.64
// Your weight on Mars is 38 pounds
// Your weight on Jupiter is 264 pounds

int main(){
    int weight, mars, jupiter;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Enter your weight in pounds:    ");
    scanf("%d", &weight);
    
    mars = weight * 0.38;
    jupiter = weight * 2.64;
    
    printf("\n%s, the results of your conversion are stated below:\n\n", name);
    printf("Your weight on Mars is %d pounds.\n", mars);
    printf("Your weight on Jupiter is %d pounds.\n", jupiter);
    
    return 0;
}
