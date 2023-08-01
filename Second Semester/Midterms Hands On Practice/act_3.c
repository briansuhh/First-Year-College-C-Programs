/*
Instructions:
Write a program in C to merge two arrays of the same size sorted in descending order. 

Test Data : 
Input the number of elements to be stored in the first array : 3 
Input 3 elements in the array : 
element - 0 : 1 
element - 1 : 2 
element - 2 : 3 
Input the number of elements to be stored in the second array : 3 
Input 3 elements in the array : 
element - 0 : 1 
element - 1 : 2 
element - 2 : 3 

Expected Output : 
The merged array in decending order is : 
3 3 2 2 1 1 
*/

#include <stdio.h>

void mergeAndSort(int arr1[], int arr2[], int arr3[], int a, int b, int c) { 
    int i, j, k;
    for(i=0; i<a; i++){
        arr3[i] = arr1[i];
    }

    for(j=0; j<b; j++){
        arr3[i] = arr2[j];
        i++; 
    }

    for(i=0; i<c; i++){
        for(k=0; k<c-1; k++){
            if(arr3[k]<=arr3[k+1]){
                j=arr3[k+1];
                arr3[k+1]=arr3[k];
                arr3[k]=j;
            }  
        }
    }   

    printf("\nThe merged array in decending order is :\n");
    for(i=0; i<c; i++){
        printf("%d   ", arr3[i]);
    }
	printf("\n\n");
}

int main() {
    int a, b, c;

    // First array
    printf("Enter the number of elements in the array:     ");
    scanf("%d", &a);
    
    int arr1[a];

    printf("\nEnter %d numbers:     \n");
    
    for(int i=0; i<a; i++) {
        printf("Number %d:    ", i+1);
        scanf("%d",&arr1[i]);
    }

    // Second array
    printf("Enter the number of elements in the array:     ");
    scanf("%d", &b);
    
    int arr2[b];

    printf("\nEnter %d numbers:     \n");
    
    for(int i=0; i<b; i++) {
        printf("Number %d:    ", i+1);
        scanf("%d",&arr2[i]);
    }

    c = a + b;
    int arr3[c];

    mergeAndSort(arr1, arr2, arr3, a, b, c);
    
    return 0;
}