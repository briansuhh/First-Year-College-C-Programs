#include <stdio.h>

// A Video Rental gives a fine to their customers who return the CDs of tape later than the due date. Input the number of days late and display the fine.  

int main() 
{

    int days, type, user_input;

    printf("Enter the number of days the recording has been passed the due date: ");
    scanf("%d", &days);

    if (days >= 0) 
    {
        if (days == 1 || days == 2) 
            printf("\nYou need to pay a fine of 10 pesos.\n");
        else if (days == 3 || days == 4) 
            printf("\nYou need to pay a fine of 15 pesos.\n");
        else if (days == 5 || days == 6) 
            printf("\nYou need to pay a fine of 20 pesos.\n");
        else if (days >= 7) 
        {
            printf("\nWhat is the type of media recordings did you borrow? (1 = CD) (2 = VHS): ");
            scanf("%d", &type);
            if (type == 1) 
                printf("\nYou need to pay a fine of 50 pesos.\n");
            else if (type == 2) 
                printf("\nYou need to pay a fine of 35 pesos.\n");
        }
    } 
    else if (days < 0)
        printf("\nEnter a positive number.\n");

    return 0;
}
