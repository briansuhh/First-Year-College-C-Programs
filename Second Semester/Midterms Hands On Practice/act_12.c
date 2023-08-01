/*
Instructions:
Write a program in C to make a pyramid pattern with numbers increased by 1. 
   1 
  2 3 
 4 5 6 
7 8 9 10 

*/

#include <stdio.h>

void pyramid(){
    int i, j;
    int num = 1;
    int spaces = 3;
    // int rows = 5;
    // int spacing = rows - 1;

    for(i = 1; i<5; i++){
        printf("%*s", spaces, "");
        spaces--;

        // for (int a = spacing--; a >= 1; a--)
        //     printf(" ");
        
        for(j = 1; j<=i; j++){
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}

int main(){
    pyramid();

    return 0;
}