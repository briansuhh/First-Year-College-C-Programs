#include <stdio.h>

// Create a program that calculates the amount of bag of candies based on the weight of each type of candies indicated by the user
// IPO
// 2 3 4 2
// 2 * 35
// 3 * 45
// 4 * 56
// 2 * 57.50
// 70
// 135
// 224
// 115

int main(){
    float candy_a, candy_b, candy_c, candy_d;
    float weight_a, weight_b, weight_c, weight_d;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Enter the weight of Candy A, Candy B, Candy C, and Candy D accordingly:    ");
    scanf("%f %f %f %f", &weight_a, &weight_b, &weight_c, &weight_d);
    
    candy_a = weight_a * 35;
    candy_b = weight_b * 45;
    candy_c = weight_c * 56;
    candy_d = weight_d * 57.5;
        
    printf("\n%s, the price of each candies are stated below:\n\n", name);
    printf("The price of Candy A is %g pesos.\n", candy_a);
    printf("The price of Candy B is %g pesos.\n", candy_b);
    printf("The price of Candy C is %g pesos.\n", candy_c);
    printf("The price of Candy D is %g pesos.\n", candy_d);
    
    return 0;
}
