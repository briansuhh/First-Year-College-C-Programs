/*
Instructions:
Write a program in C to print all perfect numbers in a given range using the function. 

Test Data : 
Input lowest search limit of perfect numbers : 1
Input highest search limit of perfect numbers : 100

Expected Output : 
 The perfect numbers between 1 to 100 are :                                      
 6   28  

*/

#include <stdio.h>

// Function to print all perfect numbers in a given range
void perfectNumbers(int start, int end) {
    printf("The perfect numbers between %d and %d are:\n", start, end);

    for (int number = start; number <= end; number++) {
        int sum = 0;

        // Get the divisor of the number and their sum 
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }

        // Check if the sum is the same with the number
        if (sum == number) {
            printf("%d ", number);
        }
    }
}

int main() {
    int start, end;

    printf("Input the lowest search limit of perfect numbers: ");
    scanf("%d", &start);

    printf("Input the highest search limit of perfect numbers: ");
    scanf("%d", &end);

    perfectNumbers(start, end);

    return 0;
}
