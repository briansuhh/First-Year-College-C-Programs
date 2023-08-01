/*
Instructions:
Write a program in C to find the second largest element in an array. 

Test Data : 
Input the size of array : 5 
Input 5 elements in the array : 
element - 0 : 2 
element - 1 : 9 
element - 2 : 1 
element - 3 : 4 
element - 4 : 6 

Expected Output : 
The Second largest element in the array is : 6 

*/

#include <stdio.h>

void findSecondLargest(int array[], int size, int *secondLargest) {
    int i;
    int max = array[0];
    *secondLargest = array[0];
    
    for(i=1; i<size; i++){
        if (array[i] > max){
            *secondLargest = max;
            max = array[i];
        }
        else if (array[i] > *secondLargest && array[i] < max){
            *secondLargest = array[i];
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
    
    int secondLargest;
    findSecondLargest(array, size, &secondLargest);
    
    printf("The Second largest element in the array is : %d\n", secondLargest);

    return 0;
}
