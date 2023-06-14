#include <stdio.h>
#define MILE_TO_FEET 5280.00
#define MILE_TO_METER 1609.34

// Create a program that calculates the feet per second and meters per second based on the inputted time of the race.
// 1 minute and 30 seconds
// The speed is 58 feet per second and 17.88 meters per second.

float feet_per_sec(seconds){return MILE_TO_FEET / seconds;}
float meter_per_sec(seconds){return MILE_TO_METER / seconds;}

int main()
{
    int minutes, seconds;
    printf("This program calculates the feet per second and meters per second based on the inputted time of the race. \n\n\n");
    printf("Please, enter the minutes and seconds of the race separated by space: ");
    scanf("%d %d", &minutes, &seconds);
    
    seconds += minutes * 60;

    printf("\nThe speed is %.2f feet per second and %.2f meters per second.\n", feet_per_sec(seconds), meter_per_sec(seconds));
    return 0;
}
