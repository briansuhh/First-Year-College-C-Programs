/*
Instructions:
Write a program in C to compute the sum of all elements in an array using pointers. 

Test Data : 
Input the number of elements to store in the array (max 10) : 5 
Input 5 number of elements in the array : 
element - 1 : 2 
element - 2 : 3 
element - 3 : 4 
element - 4 : 5 
element - 5 : 6

Expected Output :
The sum of array is : 20 

*/

#include <stdio.h>

void sumOfArray(int array[], int size, int *sum){
    int i;

    for (i = 0; i < size; i++) {
        *sum += *(array + i);
    }
}

int main(){
    int size, i, sum = 0;

    printf("Input the number of elements to store in the array (max 10): ");
    scanf("%d", &size);

    int array[size];

    printf("Input %d number of elements in the array:\n", size);

    for (i = 0; i < size; i++) {
        printf("element - %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    sumOfArray(array, size, &sum);

    printf("\nThe sum of array is: %d\n", sum);

    return 0;
}