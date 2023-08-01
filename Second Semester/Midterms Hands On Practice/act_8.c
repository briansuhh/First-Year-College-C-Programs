/*
Instructions:
Write a program in C to convert a decimal number to a binary number using the function. 

Test Data : 
Input any decimal number : 65 

Expected Output : 
 The Binary value is : 1000001
*/

#include <stdio.h>

void decimalToBinary(int n, int binaryNum[100], int *i){
    while (n > 0) {
        binaryNum[*i] = n % 2;
        n = n / 2;
        (*i)++;
    }
}

int main() {
    int binaryNum[100];
    int i = 0, num;
    
    printf("Input any decimal number : ");
    scanf("%d", &num);

    decimalToBinary(num, binaryNum, &i);
    
    printf("The Binary value is : ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);

    return 0;
}
