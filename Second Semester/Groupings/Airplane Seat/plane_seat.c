/*
Instructions:
Using the concept of structures, write a program to assign passenger seats in an 
airplane. Assume a small airplane with seats numbered as follows:
1 A B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D
The program should display the seat pattern, marking with an ‘X’ the seats already 
assigned. For example, after seats 1A, 2B, and 4C are taken, the display should look like:
1 X B C D
2 A X C D
3 A B C D
4 A B X D
5 A B C D
Seats are assigned by specifying a number and a letter. If the user types in a seat 
that is already assigned, the program should say that the seat is occupied and ask for 
another choice. The program should run until all seats are filled, or the user signals that 
the program should end.
*/

#include <stdio.h>
#include <ctype.h>

struct SeatAvailability {
    int taken;
};

struct SeatAvailability seats[5][4];

// To print the available seats and check availability
void printAirplaneSeats(int *allOccupied) {
    *allOccupied = 1; // Assume all seats are occupied

    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d      ", i + 1);
        for (int j = 0; j < 4; j++) {
            if (seats[i][j].taken) 
                printf("X      ");
            else {
                printf("%c      ", 'A' + j);
                *allOccupied = 0; // Set to 0 if any seat is available
            }
        }
        printf("\n");
    }
}

int main() {
    int row, col;
    char seatCol;
    int allOccupied;
    char userInput;

    // Initialize the whole array to zero
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 4; j++) 
            seats[i][j].taken = 0;

    printf("These are the available seats.\n");
    printAirplaneSeats(&allOccupied);

    // To loop the questions until all seats are taken or the user wants to exit
    while (!allOccupied) {
        printf("\nWhat seat would you like to take?\n");
        printf("Seat number (1-5): ");
        while (scanf("%d", &row) != 1 || row > 5 || row < 1)	{
            printf("\nInvalid input. Please enter numbers from 1 to 5.\n\n");
            printf("Seat number (1-5): ");
            while (getchar() != '\n');
	    }

        printf("Seat letter (A-D): ");
        while (scanf(" %c", &seatCol) != 1 || (seatCol < 'A' || seatCol > 'D'))	{
            printf("\nInvalid input. Please enter capital letters from A to D.\n\n");
            printf("Seat letter (A-D): ");
            while (getchar() != '\n');
	    }
        
        // To convert the seat letter to its index comparison
        col = seatCol - 'A';

        // To check if the seat is already occupied
        if (seats[row - 1][col].taken)
            printf("Seat is already occupied. Please choose another seat.\n");
        else {
            seats[row - 1][col].taken = 1;
            printf("\nCongratulations! Your seat has been assigned.\n"); 
            printf("Please print your ticket for seat %d%c and present it before boarding.\n", row, seatCol);
            printAirplaneSeats(&allOccupied);
        }

        if(!allOccupied){
            printf("\n--------------------------\n");
            printf("      MENU OPTIONS\n");
            printf("--------------------------\n");
            printf("[Y] - Book Again\n");
            printf("[C] - Cancel\n");
            printf("[any other key] - Exit\n");
            printf("--------------------------\n");
            printf("Enter your choice: ");
            scanf(" %c", &userInput);
            if (userInput == 'y' || userInput == 'Y')
                continue;
            else if (userInput == 'c' || userInput == 'C') {
                seats[row - 1][col].taken = 0;
                printf("\nYour seat has been cancelled\n");
                printAirplaneSeats(&allOccupied);
            }
            else
                break;
        }
        
    }

    if (allOccupied)
        printf("\nAll seats are occupied. \n\n");

    if(userInput != 'y' && userInput != 'Y' && userInput != 'c' && userInput != 'C')
        printf("\nOn behalf of Philippine Airlines.\nMaraming Salamat!\n\n");

    return 0;
}

/*
Additional features:
-none at the moment
*/ 
