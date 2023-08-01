/*
Instructions:
Write a C program to convert a binary number into a decimal number without using array, function and while loop. 

Test Data : 
Input a binary number :1010101 

Expected Output :
The Binary Number : 1010101 
The equivalent Decimal Number : 85 

*/

#include <stdio.h>

int main(){
    long long binaryNum;
    int lastDigit, decimalNum = 0;

    printf("Inpute a binary number :");
    scanf("%lld", &binaryNum);

    printf("The Binary Number : %lld", binaryNum);

    // // Extraction of digit from right to left
    // lastDigit = binaryNum % 10;
    // decimalNum += lastDigit * 1;
    // binaryNum /= 10;

    // lastDigit = binaryNum % 10;
    // decimalNum += lastDigit * 2;
    // binaryNum /= 10;

    // lastDigit = binaryNum % 10;
    // decimalNum += lastDigit * 4;
    // binaryNum /= 10;

    // lastDigit = binaryNum % 10;
    // decimalNum += lastDigit * 8;
    // binaryNum /= 10;

    // lastDigit = binaryNum % 10;
    // decimalNum += lastDigit * 16;
    // binaryNum /= 10;

    // lastDigit = binaryNum % 10;
    // decimalNum += lastDigit * 32;
    // binaryNum /= 10;

    // lastDigit = binaryNum % 10;
    // decimalNum += lastDigit * 64;
    // binaryNum /= 10;

    // lastDigit = binaryNum % 10;
    // decimalNum += lastDigit * 128;
    // binaryNum /= 10;

    for (int i = 0; binaryNum != 0; i++) {
        int lastDigit = binaryNum % 10;
        decimalNum += lastDigit << i;
        binaryNum /= 10;
    }

    printf("\nThe equivalent Decimal Number : %d", decimalNum);

    return 0;
}