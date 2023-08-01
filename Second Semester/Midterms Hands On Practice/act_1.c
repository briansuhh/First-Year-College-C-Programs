/*
Instructions:
Write a program in C to count the total number of duplicate elements in an array. 

Test Data : 
Input the number of elements to be stored in the array :3 
Input 3 elements in the array : 
element - 0 : 5 
element - 1 : 1 
element - 2 : 1 

Expected Output : 
Total number of duplicate elements found in the array is : 1 
*/

#include <stdio.h>

void duplicateChecker(int arr[3], int total) {
    int count = 0;
    
    for(int i=0; i<total; i++){
        for(int j=i+1; j<total; j++){
            if(arr[i] == arr[j]){
                count++;
                break;
            }   
        }
    }

    printf("Total number of duplicate elements found in the array is : %d", count);
}

int main() {
    int total;

    printf("Enter the number of elements in the array:     ");
    scanf("%d", &total);
    
    int arr[total];

    printf("\nEnter %d numbers:     \n");
    
    for(int i=0; i<total; i++) {
        printf("Number %d:    ", i+1);
        scanf("%d",&arr[i]);
    }

    duplicateChecker(arr, total);
    
    return 0;
}