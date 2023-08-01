/*
Instructions:
Write a C program to get the indices of two numbers in a given array of integers. This will enable you to get the sum of two numbers equal to a specific target. 

Expected Output: 
Original Array: 4  2  1  5  

Target Value: 7
Indices of the two numbers whose sum equal to target value: 7
1 3

*/

#include <stdio.h>
#include <malloc.h>

void FindTwoSum(int arr[], int size, int target){
    int holder;

    for (int i = 0; i < size; i++){
        holder = target - *(arr + i);
        for (int j = i; j < size; j++)
            if (i != j && holder == *(arr + j)){
                printf("Indices of the two numbers whose equal to target value %d: %d and %d", target, i, j);
                return;
            }
    }
}

int main()
{
    int *numbers, size, target;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);

    numbers = (int*)malloc(size * sizeof(int));

    printf("Input %d elements in the array : \n", size);
    for (int i = 0; i < size; i++){
        printf("Element - %d : ", i + 1);
        scanf("%d", (numbers + i));
    }

    printf("Input the target value: ");
    scanf("%d", &target);

    printf("\nOriginal Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", *(numbers + i));
    
    printf("\nTarget Value: %d\n", target);

    FindTwoSum(numbers, size, target);
}

