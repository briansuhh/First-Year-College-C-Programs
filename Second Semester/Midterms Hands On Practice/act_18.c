/*
Instructions:
Write a program in C to find the largest element using Dynamic Memory Allocation. 

Test Data : 
Input total number of elements(1 to 100): 5 
Number 1: 5 
Number 2: 7 
Number 3: 2 
Number 4: 9 
Number 5: 8

Expected Output :
The Largest element is :  9.00 
*/

#include <stdio.h>
#include <stdlib.h>

void largestElement(float *element, int size) {
    int i;

    for(i = 0; i < size; i++){
        if(*element < *(element+i)){
            *element = *(element+i);
        }
    }
}

int main(){
    int i, size;
    float *element;

    printf("Input total number of elements(1 to 100): ");
    scanf("%d", &size);

    // element = (float*)malloc(size * (sizeof(float)));

    for(i = 0; i < size; i++) {
       printf("Number %d: ", i+1);
       scanf("%f", element+i);
    }

    largestElement(element, size);

    printf("The Largest element is : %g", *element);

    return 0;
}

