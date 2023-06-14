#include <stdio.h>
#include <math.h>

// Create a program that will determine the area of the pizza and the price by the divided area. Also, which among the 3 is the least expensive

int main(){
    int diameter_a, diameter_b, diameter_c;
    int cost_a, cost_b, cost_c;
    float area_a, area_b, area_c;
    float price_a, price_b, price_c;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Please input the diameters of Domino's pizza:    ");
    scanf("%d %d %d", &diameter_a, &diameter_b, &diameter_c);
    printf("Please input the costing of Domino's pizza:    ");
    scanf("%d %d %d", &cost_a, &cost_b, &cost_c);
    
    area_a = (pow(diameter_a, 2) * M_PI) / 4;
    area_b = (pow(diameter_b, 2) * M_PI) / 4;
    area_c = (pow(diameter_c, 2) * M_PI) / 4;
    price_a = cost_a / area_a;
    price_b = cost_b / area_b;
    price_c = cost_c / area_c;

    printf("\nThe area of the 3 pizzas are stated below:\n");
    printf("Pizza A(%d in) = %g inches\n", diameter_a, area_a);
    printf("Pizza B(%d in) = %g inches\n", diameter_b, area_b);
    printf("Pizza C(%d in) = %g inches\n\n", diameter_c, area_c);

    printf("The price per square inch of the 3 pizzas are stated below:\n");
    printf("Pizza A(%d in) = %g\n", diameter_a, price_a);
    printf("Pizza B(%d in) = %g\n", diameter_b, price_b);
    printf("Pizza C(%d in) = %g\n\n", diameter_c, price_c);
    
    if (price_a < price_b && price_a < price_c)
        printf("%s, %d inches is the least expensive with a %g price per square inch", name, diameter_a, price_a);

    if (price_b < price_a && price_b < price_c)
        printf("%s, %d inches is the least expensive with a %g price per square inch", name, diameter_b, price_b);

    if (price_c < price_a && price_c < price_b)
        printf("%s, %d inches is the least expensive with a %g price per square inch", name, diameter_c, price_c);


    return 0;
}
