#include <stdio.h>
#define START 700
#define FINISH 1100

int start = START;

//Check if the number is a prime number or not
int isPrime(num){   
    if (num < 2)
        return 0;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return 0; 
    return 1; 
}

//Check for the goldbach conjecture of a number
void goldbachConjecture(){
    for (int i = 2; i <= 100; i++)
        if (isPrime(i) && isPrime(start - i)){ 
            printf("%d = %d + %d\n", start, i, start - i); 
            break;
        }
}

int main(){
    printf("This program evaluates the even numbers from 700 to 1100 for their goldbach conjecture.\n\n\n");
    while(start <= FINISH){
        goldbachConjecture();
        start+=2;
    }
    return 0;
}
