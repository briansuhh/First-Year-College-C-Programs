#include <stdio.h>

// Create a program that converts hours to minutes
// IPO
// 4
// 4 * 60
// 4 hours is equal to 240 minutes

int main(){
    int hour, result;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Enter the number of hours you want to convert:    ");
    scanf("%d", &hour);
    
    result = hour * 60;
    
    printf("\n%s, %d hour/s is equal to %d minute/s", name, hour, result);
    
  return 0;
}
