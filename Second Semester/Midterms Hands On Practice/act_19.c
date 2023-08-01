/*
Instructions:
Write a program in C to sort an array using a pointer. 

Test Data : 
Input the number of elements to store in the array : 5 
Input 5 number of elements in the array : 
element - 1 : 25 
element - 2 : 45 
element - 3 : 89 
element - 4 : 15 
element - 5 : 82 

Expected Output :                                                                              
The elements in the array after sorting :                                                                    
element - 1 : 15                                                                                             
element - 2 : 25                                                                                             
element - 3 : 45                                                                                             
element - 4 : 82                                                                                             
element - 5 : 89

*/
#include <stdio.h>
#include <stdlib.h>

void sortElement(float *element, int size) {
    int i, j;
    float temp;

    for(i = 0; i < size; i++){
        for(j = i+1; j < size; j++){
            if (*(element+i) < *(element+j)){
                temp = *(element+i);
                *(element+i) = *(element+j);
                *(element+j) = temp;
            }
        }
    }
}

int main(){
    int i, size;
    float *element;

    printf("Input the number of elements to store in the array : ");
    scanf("%d", &size);

    printf("Input %d number of elements in the array : \n", size);

    element = (float*)malloc(size * sizeof(float));

    for(i = 0; i < size; i++) {
       printf("Number %d: ", i+1);
       scanf("%f", element+i);
    }

    sortElement(element, size);

    printf("\nThe elements in the array after sorting : \n");
    for(i = 0; i < size; i++) {
	  printf("element - %d : %g \n", i+1, *(element+i));
	}         
    printf("\n");

    return 0;
}

