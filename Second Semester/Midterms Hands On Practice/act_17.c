/*
Instructions:
Write a C program to convert an octal number to a decimal without using an array. 

Test Data : 
Input an octal number (using digit 0 - 7) : 745 

Expected Output :
The Octal Number : 745 
The equivalent Decimal Number : 485

*/

#include <stdio.h>
#include <math.h>

void octaltoDecimal(int octalNumber, int *decimalNumber){
    int i = 0;

    while(octalNumber != 0){
        *decimalNumber += (octalNumber % 10) * (int)pow(8, i);
        octalNumber /= 10;
        i++;
    }
}

int main(){
    int octalNumber, decimalNumber = 0;

    printf("Input an octal number (using digit 0 - 7) : ");
    scanf("%d", &octalNumber);

    printf("The Octal Number : %d\n", octalNumber);

    octaltoDecimal(octalNumber, &decimalNumber);

    printf("The equivalent Decimal Number : %d\n", decimalNumber);

    return 0;
}