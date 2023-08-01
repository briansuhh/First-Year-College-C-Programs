/*
Instructions:
Write a program in C to print Floyd's Triangle. 
1 
01
101 
0101 
10101

*/

#include <stdio.h>

void floydsTriangle(){
    int i, j;
    int spaces = 3;
    int num = 1;

    for(i = 1; i<=5; i++){  
        for(j = 1; j<=i; j++){
            printf("%d", num);
            num = 1 - num;
        }
        printf("\n");
    }
}

int main(){
    floydsTriangle();

    return 0;
}