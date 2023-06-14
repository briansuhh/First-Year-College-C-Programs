
#include <stdio.h>

// Make a program that gets the largest number from the inputted 3 numbers
// 5 1 9
// 9 is the largest number

int main() {
  int a, b, c;
  char name[80];

  printf("Please enter your name:  ");
  scanf("%s", name);
  printf("Please enter 3 different numbers:  ");
  scanf("%d %d %d", &a, &b, &c);

  // Checks if a is the largest number
  if (a > b && a > c) {
    printf("\n%s, %d is the largest number", name, a);
  }
  // Checks if b is the largest number
  else if (b > a && b > c) {
    printf("\n%s, %d is the largest number", name, b);
  }
  // Checks if b is the largest number
  else {
    printf("\n%s, %d is the largest number.", name, c);
  }
  printf("\nThank you.");
  return 0;
}
