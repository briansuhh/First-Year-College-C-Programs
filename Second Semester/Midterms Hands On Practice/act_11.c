/*
Instructions:
Write a program in C to make such a pattern like a right angle triangle with the number increased by 1. 
The pattern like : 
   1
   2 3
   4 5 6
   7 8 9 10

*/

#include <stdio.h>

void rightAngle(){
    int i, j;
    int num = 1;

    for(i = 1; i<5; i++){
        for(j = 1; j<=i; j++){
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}

int main(){
    rightAngle();

    return 0;
}