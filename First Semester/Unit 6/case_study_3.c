#include <stdio.h>

//Create a program that converts a 24hour notation to 12 hour notation

//Function to convert to 24hour notation
void convertTime(int time) {
    int hour = time / 100;
    int minute = time % 100;
    char *suffix = "PM";
    
    if (hour == 24 || hour < 12) 
        suffix = "AM";
    if (hour == 0)
        hour = 12;
    if (hour > 12) 
        hour -= 12;

    printf("%02d:%02d %s\n", hour, minute, suffix);
}

int main() {
    int time;
    printf("This program converts a 24hour notation to 12hour notation.\n\n");

    //Looping that will only stop if the user entered an invalid input
    while(1){
        printf("\nEnter time in 24-hour notation: ");
        scanf("%d", &time);
        if (time < 0 || time > 2400){
            printf("Invalid input. Please try again.\n\n");
            break;
        }
        printf("The 12 hour notation of %d is ", time);
        convertTime(time);
    }
    return 0;
}
