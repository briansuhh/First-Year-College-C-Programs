#include <stdio.h>

// Make a program that calculates weekly wages for hourly employees

// Regular hours (0-40) are paid at $10 per hour
// Overtime (>40 hours) is paid at 150%

// 42
// 430 dollars

int main(void) {
    int hours, regular, overtime, bonus;
    char name[80];

    
    printf("Please enter your name:  ");
    scanf("%s", name);
    printf("Please enter the number of hours you worked in one week:  ");
    scanf("%d", &hours);
    
    if (hours <= 40){
    regular = hours * 10;
    printf("\n%s, your total wage for the week is %d dollars.", name, regular);
    }
    
    else{
    // Subtract 40 from the inputted hours and multiply it by 15 and add 400
    overtime = 400 + (hours-40) * 15; 
    // Subtract 400 from the total wage with overtime
    bonus = overtime - 400;
    printf("\n%s, your total wage for the week is %d dollars.\n", name, overtime);
    printf("Your overtime bonus is %d dollars.", bonus);
    }

}
