#include <stdio.h>

//Function that displays the proper divisors
int kompute(int num, int *result) {
    int sum = 0;
    for (int i = 1; i < num2
        ; i++) {
        if (num % i == 0) {
            sum += i;
            printf("%s%d", (i == 1) ? "" : ", ", i);
        }
    }
    *result = (sum < num) ? 0 : (sum == num) ? 1 : 2;
    return sum;
}
//Function that displays the proper divisor and their sum
void divisor(int num) {
    for (int i = 1; i < num; i++)
        if (num % i == 0) 
            printf("%s%d", (i == 1) ? "" : " + ", i);
}

int main() {
    int num, result;
    printf("This program displays the positive divisors of an integer and determines whether its sum is deficient, perfect, or abundant.\n\n");
    
    // This will loop if the user inputted an invalid input
    do {
        printf("Please enter a positive integer: ");
        scanf("%d", &num);
    } while (num <= 0 && printf("Invalid input. Please try again!\n\n"));
    
    printf("Proper divisors are ");
    int sum = kompute(num, &result);
    printf("\nSum of proper divisors: ");
    divisor(num);
    printf(" = %d\n", sum);
    printf("%d %s %d is %s\n", sum, (result == 0) ? "<" : (result == 1) ? "=" : ">", num, (result == 0) ? "DEFICIENT" : (result == 1) ? "PERFECT" : "ABUNDANT");
    return 0;
}
