#include <stdio.h>

void sum(int x[]) {
    int n = 0;

    int sum_even = 0;  // Initialize sum_even to zero
    int sum_odd = 0;   // Initialize sum_odd to zero

    // To know the size of the array using pointer
    int* pX = x;
    while (*(pX + n) != '\0') {
        pX++;
        n++;
    }

    // To determine the odd and even element of the array and get their sum
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 == 0) {  
            sum_even += x[i];
        }
        else if (x[i] % 2 != 0){
            sum_odd += x[i];
        }
    }

    printf("\nThe sum of the even element numbers is %d", sum_even);
    printf("\nThe sum of the odd element numbers is %d", sum_odd);
}

int main() {
    int x[] = {2, 1, 6, 3};
    sum(x);

    return 0;
}
