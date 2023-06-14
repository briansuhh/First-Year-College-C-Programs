#include <stdio.h>
#include <stdlib.h>

void sum(double b[]) { 
    int n = 0, indexA = 1, indexB = 1;
    
    double *sum_even;
    double *sum_odd;
    
    // To know the size of the array using pointer
    double *pB = b;
    while (*(pB + n) != '\0') {
        pB++;
        n++;
    }

    // To allocate memory for arrays sum_even and sum_odd of size n
    sum_even = (double*) malloc(n * sizeof(double));
    sum_odd = (double*) malloc(n * sizeof(double));
    
    // To determine the odd and even index of the array and get their sum
    for (int i = 0; i < n; i++){
        if (i % 2 == 0) {
            *(sum_even + indexA) = *(b + i);
            *sum_even += *(sum_even + indexA);
            indexA++;
        }
        else {
            *(sum_odd + indexB) = *(b + i);
            *sum_odd += *(sum_odd + indexB);
            indexB++;
        }
    }

    printf("\n The sum of the even index numbers is %g", *sum_even);
    printf("\n The sum of the odd index numbers is %g", *sum_odd);
}

int main() {
    
    double b[] = {2.2, 4.5, 6.4, 3.407};
    sum(b);
    
    return 0;
}
