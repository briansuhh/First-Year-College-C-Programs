/*
Instructions:
Write a program in C to find the maximum and minimum elements in an array. 

Test Data : 
Input the number of elements to be stored in the array :3 
Input 3 elements in the array : 
element - 0 : 45 
element - 1 : 25 
element - 2 : 21 

Expected Output : 
Maximum element is : 45 
Minimum element is : 21 

*/

#include <stdio.h>

void minAndMax(int array[], int size, int *min, int *max) {
    int i;
    
    *min = array[0];
    *max = array[0];
    
    for(i=1; i<size; i++){
        if(array[i] <= *min){
            *min = array[i];
        }
        if(array[i] >= *max){
            *max = array[i];
        }
    }
}

int main() {
    int size;
    int min, max;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);
    
    int array[size];
    
    printf("Input %d elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("element - %d: ", i);
        scanf("%d", &array[i]);
    }
    
    minAndMax(array, size, &min, &max);
    
    printf("Maximum element is : %d\n", max);
    printf("Minimum element is : %d", min);

    return 0;
}
