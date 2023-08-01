/*
Instructions:
Write a program in C to find the number and sum of all integers between 100 and 200 which are divisible by 9. 

Expected Output :
Numbers between 100 and 200, divisible by 9 : 
108 117 126 135 144 153 162 171 180 189 198 
The sum : 1683 

*/

#include <stdio.h>

void findDivisorAndSum(){
    int start = 100, end = 200;
    int i, sum;

    printf("Numbers between 100 and 200, divisible by 9 : \n");

    for(i = start; i <= end; i++){
        if (i % 9 == 0){
            printf("%d ", i);
            sum += i;
        }
    }

    printf("\nThe sum : %d", sum);

}

int main(){
    findDivisorAndSum();

    return 0;
}