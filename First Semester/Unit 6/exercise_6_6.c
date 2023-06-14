#include <stdio.h>

// Create a program that takes 2 non-negative integer as an input and evaluate if they are relatively prime or not.

//Recursive function to get the gcd of the 2 numbers inputted
int gcd(a, b){
    if (b == 0)
        return a;
    else 
        return gcd(b, a % b);
}

//Check if the returned value is 1, then it is relatively prime
int rel_prime(a, b){return gcd(a, b) == 1;}

int main() {
    int i, j;

    printf("This program will evaluate any two non-negative numbers to determine if they are relatively prime or not.\n\n\n");
    printf("Please enter two positive integers separated by space:    ");
    scanf("%d %d", &i, &j);

    printf("\nThe numbers %d and %d are %s", i, j, (rel_prime(i, j)) ? "relatively prime" : "not relatively prime.");
    printf("\nTheir greatest common divisor is %d.", gcd(i, j));
    
    return 0;
}
