/*
Instructions:
Write a program in C to convert a decimal number into octal without using an array. 

Test Data : 
Enter a number to convert : 79 

Expected Output :
The Octal of 79 is 117.

*/

#include <stdio.h>

void decimalToOctal(int decimalNum, int *octalNum){
    int i = 1;

    while (decimalNum != 0){
        *octalNum += (decimalNum % 8) * i;
        decimalNum /= 8;
        i *= 10;
    }
}

int main(){
    int decimalNum, octalNum = 0;

    printf("Enter a number to convert: ");
    scanf("%d", &decimalNum);

    decimalToOctal(decimalNum, &octalNum);

    printf("The Octal of %d is %d.\n", decimalNum, octalNum);

    return 0;
}