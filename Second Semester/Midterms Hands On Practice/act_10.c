/*
Instructions:
Write a program in C to make such a pattern like a right angle triangle with a number which will repeat a number in a row. 
The pattern like : 
 1
 22
 333
 4444

*/

#include <stdio.h>

void rightAngle(){
    int i, j;

    for(i = 1; i<5; i++){
        for(j = 1; j<=i; j++){
            printf("%d", i);
        }
        printf("\n");
    }
}

int main(){
    rightAngle();

    return 0;
}