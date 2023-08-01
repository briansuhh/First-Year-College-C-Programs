/*
Instructions:
Write a program in C to print the elements of an array in reverse order using pointer. 

Test Data : 
Input the number of elements to store in the array (max 15) : 5 
Input 5 number of elements in the array : 
element - 1 : 2 
element - 2 : 3 
element - 3 : 4 
element - 4 : 5 
element - 5 : 6 

Expected Output :
The elements of array in reverse order are :                                                                 
element - 5 : 6                                                                                              
element - 4 : 5                                                                                              
element - 3 : 4                                                                                              
element - 2 : 3                                                                                              
element - 1 : 2       

*/

#include <stdio.h>

void reverseArray(int array[], int size){
    int i;

    for(i = size - 1; i >= 0; i--){
        printf("element - %d : %d\n", i+1, *(array + i));
    }
}

int main(){
    int size, i;

    printf("Input the number of elements to store in the array (max 15): ");
    scanf("%d", &size);

    int array[size];

    printf("Input %d number of elements in the array:\n", size);
    for (i = 0; i < size; i++) {
        printf("element - %d : ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nThe elements of the array in reverse order are:\n");

    reverseArray(array, size);
    
    return 0;
}