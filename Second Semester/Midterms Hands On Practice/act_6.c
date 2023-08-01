/*
Instructions:
Write a program in C to separate odd and even integers into separate arrays. 

Test Data : 
Input the number of elements to be stored in the array :5 
Input 5 elements in the array : 
element - 0 : 25 
element - 1 : 47 
element - 2 : 42 
element - 3 : 56 
element - 4 : 32 

Expected Output : 
The Even elements are : 
42 56 32 
The Odd elements are : 
25 47
 
*/

#include <stdio.h>

void separateOddEven(int array[], int size, int even[], int odd[], int *evenSize, int *oddSize) {
    
    int i;
    
    *evenSize = 0;
    *oddSize = 0;
    
    for(i=0; i<size; i++){
        if(array[i] % 2 == 0){
            even[*evenSize] = array[i];
            (*evenSize)++;
        }
        else{
            odd[*oddSize] = array[i];
            (*oddSize)++;
        }
    }
}

int main() {
    int size;
    int evenSize, oddSize;
    int even[100], odd[100];

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);
    int array[size];
    
    printf("Input %d elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("element - %d: ", i);
        scanf("%d", &array[i]);
    }

    separateOddEven(array, size, even, odd, &evenSize, &oddSize);
    
    printf("The Even elements are: ");
    for (int i = 0; i < evenSize; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");

    printf("The Odd elements are: ");
    for (int i = 0; i < oddSize; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    return 0;
}

