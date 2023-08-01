/*
Instructions:
Write a program in C to count the frequency of each element of an array. 

Test Data : 
Input the number of elements to be stored in the array : 3 
Input 3 elements in the array : 
element - 0 : 25 
element - 1 : 12 
element - 2 : 43 

Expected Output : 
The frequency of all elements of an array : 
25 occurs 1 times 
12 occurs 1 times 
43 occurs 1 times 
*/

#include <stdio.h>

#define MAX_SIZE 100

void countFrequency(int array[], int size) {
    int frequency[MAX_SIZE] = {0};  // Initialize frequency array with 0s

    // Count the frequency of each element
    for (int i = 0; i < size; i++) {
        frequency[array[i]]++;
    }

    // Print the frequency of each element
    printf("The frequency of all elements of an array:\n");
    for (int i = 0; i < size; i++) {
        if (frequency[array[i]] != 0) {
            printf("%d occurs %d times\n", array[i], frequency[array[i]]);
            frequency[array[i]] = 0;  // Reset the frequency to avoid duplicate printing
        }
    }
}

int main() {
    int size;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Input %d elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("element - %d: ", i);
        scanf("%d", &array[i]);
    }

    countFrequency(array, size);

    return 0;
}
