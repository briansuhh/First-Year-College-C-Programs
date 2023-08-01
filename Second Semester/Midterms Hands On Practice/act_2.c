/*
Instructions:
Write a program in C to print all unique elements in an array. 

Test Data : 
Print all unique elements of an array:
------------------------------------------
Input the number of elements to be stored in the array: 4
Input 4 elements in the array :
element - 0 : 3
element - 1 : 2
element - 2 : 2
element - 3 : 5

Expected Output : 
The unique elements found in the array are:
3 5
*/

#include <stdio.h>

void uniqueElemChecker(int arr[3], int total) {


    printf("The unique elements found in the array are: ");
    for(int i=0; i<total; i++){
        int counter = 0;
        for(int j=0; j<total; j++){
            if(i!=j){
                if(arr[i] == arr[j]){
                    counter++;
                }   
            }
        }
        if(counter==0){
            printf("%d ", arr[i]);
        }
    }
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

    uniqueElemChecker(arr, total);
    
    return 0;
}