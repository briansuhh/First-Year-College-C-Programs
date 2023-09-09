#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

struct Shoe {
    int stockNumber;
    int styleNumber;
    int sizes[12];
    float price;
};

struct Shoe shoeRecord;

void createRecord();
void displayRecord();
void updateRecord();
void deleteRecord();
int ifExisting(int stockNumber, int styleNumber);

int main() 
{
    int userChoice;

    while (1) {
        printf("SHOE INVENTORY MENU:\n");
        printf("\t1: ENTER A NEW SHOE RECORD\n");
        printf("\t2: DISPLAY A SHOES RECORD\n");
        printf("\t3: UPDATE PRICE AND STOCK ON HAND\n");
        printf("\t4: DELETE A SHOE RECORD\n");
        printf("\t5: EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                createRecord();
                break;
            case 2:
                displayRecord();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("\nDo you want to continue the exit?\n");
                printf("\tEnter Y for YES and N for NO: ");
                while (scanf(" %c", &userChoice) != 1 || (userChoice != 'Y' && userChoice != 'N')) {
                    printf("\nInvalid input. Please enter only [Y] and [N].\n");
                    printf("Enter [Y] for YES and [N] for NO: ");
                    while (getchar() != '\n');
                }

                if (userChoice == 'Y'){
                    printf("\nThank you for using our program!");
                    return 1;
                }

                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
}

void createRecord(){ 
    FILE *file = fopen("inventory.txt", "a"); 
    int i;
    char userChoice;
    int stockNumber, styleNumber;

    while (1) {
        printf("\nEnter the stock number: ");
        while (scanf("%d", &stockNumber) != 1 || stockNumber < 0 || stockNumber > 50) {
            printf("\nInvalid input. Please enter a valid stock number.\n\n");
            printf("Enter the stock number: ");
            while (getchar() != '\n');
        }

        printf("Enter the style number: ");
        while (scanf("%d", &styleNumber) != 1 || styleNumber < 0 || styleNumber > 50) {
            printf("\nInvalid input. Please enter a valid style number.\n\n");
            printf("Enter the style number: ");
            while (getchar() != '\n');
        }

        if (ifExisting(stockNumber, styleNumber))
            printf("(%d, %d) is already used, please enter another stock number and style number.\n", stockNumber, styleNumber);
        else
            break;
    }

    shoeRecord.stockNumber = stockNumber;
    shoeRecord.styleNumber = styleNumber;
    
    printf("Enter the price: ");
    while (scanf("%f", &shoeRecord.price) != 1) {
        printf("\nInvalid input. Please enter a valid amount.\n\n");
        printf("Enter the price: ");
        while (getchar() != '\n');
    }

    printf("Enter the number on hand for each size [3 - 14]:\n");
    for (i = 0; i < 12; i++) {
        printf("Size %d: ", i + 3);
        while (scanf("%d", &shoeRecord.sizes[i]) != 1 || shoeRecord.sizes[i] < 1 || shoeRecord.sizes[i] > 50) {
            printf("Invalid input. Stock should range from 1 to 50.\n");
            while (getchar() != '\n');
            printf("Size %d: ", i + 3);
        }
    }

    printf("\nDo you want to continue the insertion?\n");
    printf("\tEnter [Y] for YES and [N] for NO: ");
    while (scanf(" %c", &userChoice) != 1 || userChoice != 'Y' && userChoice != 'N') {
    	printf("\nInvalid input. Please enter only [Y] and [N].\n");
        printf("Enter [Y] for YES and [N] for NO: ");
        while (getchar() != '\n');
    }

    if (userChoice == 'Y') {
        fprintf(file, "STOCK NUMBER: %d | STOCK STYLE: %d | PRICE: %.2f | SIZE:", shoeRecord.stockNumber, shoeRecord.styleNumber, shoeRecord.price);
        
        for (i = 0; i < 12; i++)
            fprintf(file, " %d", shoeRecord.sizes[i]);

        fprintf(file, "\n");

        fclose(file);
        printf("\nSuccessfully inserted.\n");
    }

    else
        printf("\nRecord insertion cancelled.\n");
    
    printf("\nPress enter to proceed to the MENU: ");
    getch();
    printf("\n\n");
}

void displayRecord() {
    FILE *file = fopen("inventory.txt", "r");

    int i, userChoice, counter = 1;
    bool ifFound = false;

    printf("\nMENU FOR DISPLAYING THE RECORD/S\n");
    printf("\t1: DISPLAY ALL SHOES RECORD\n");
    printf("\t2: DISPLAY SPECIFIC SHOE\n");
    printf("ENTER YOUR CHOICE: ");
    while (scanf("%d", &userChoice) != 1 || (userChoice < 1 || userChoice > 2)) {
        printf("\nInvalid input. Please enter any number from 1 to 2\n");
        printf("\nEnter the number of your choice: ");
        while (getchar() != '\n');
    }

    if (userChoice == 1) {
        while (fscanf(file, "STOCK NUMBER: %d | STOCK STYLE: %d | PRICE: %f | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d\n",
                      &shoeRecord.stockNumber, &shoeRecord.styleNumber, &shoeRecord.price,
                      &shoeRecord.sizes[0], &shoeRecord.sizes[1], &shoeRecord.sizes[2], &shoeRecord.sizes[3],
                      &shoeRecord.sizes[4], &shoeRecord.sizes[5], &shoeRecord.sizes[6], &shoeRecord.sizes[7],
                      &shoeRecord.sizes[8], &shoeRecord.sizes[9], &shoeRecord.sizes[10], &shoeRecord.sizes[11]) == 15) {

            printf("\nSHOE #%d\n", counter++);
            printf("\tSTOCK NUMBER: %d\n", shoeRecord.stockNumber);
            printf("\tSTYLE NUMBER: %d\n", shoeRecord.styleNumber);
            printf("\tSHOE PRICE: %.2f\n\n", shoeRecord.price);

            for (i = 0; i < 12; i++)
                printf("\tSIZE %d: %d\n", i + 3, shoeRecord.sizes[i]);
        }
    } else if (userChoice == 2) {
        int stockNumber, styleNumber;

        printf("\nEnter the stock number: ");
        while (scanf("%d", &stockNumber) != 1 || stockNumber < 0 || stockNumber > 50) {
            printf("\nInvalid input. Please enter a valid stock number.\n\n");
            printf("Enter the stock number: ");
            while (getchar() != '\n');
        }

        printf("Enter the style number: ");
        while (scanf("%d", &styleNumber) != 1 || styleNumber < 0 || styleNumber > 50) {
            printf("\nInvalid input. Please enter a valid style number.\n\n");
            printf("Enter the style number: ");
            while (getchar() != '\n');
        }

        while (fscanf(file, "STOCK NUMBER: %d | STOCK STYLE: %d | PRICE: %f | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d\n",
                      &shoeRecord.stockNumber, &shoeRecord.styleNumber, &shoeRecord.price,
                      &shoeRecord.sizes[0], &shoeRecord.sizes[1], &shoeRecord.sizes[2], &shoeRecord.sizes[3],
                      &shoeRecord.sizes[4], &shoeRecord.sizes[5], &shoeRecord.sizes[6], &shoeRecord.sizes[7],
                      &shoeRecord.sizes[8], &shoeRecord.sizes[9], &shoeRecord.sizes[10], &shoeRecord.sizes[11]) == 15) {

            if (shoeRecord.stockNumber == stockNumber && shoeRecord.styleNumber == styleNumber) {
                printf("\nSHOE #%d\n", counter);
                printf("\tSTOCK NUMBER: %d\n", shoeRecord.stockNumber);
                printf("\tSTYLE NUMBER: %d\n", shoeRecord.styleNumber);
                printf("\tSHOE PRICE: %.2f\n\n", shoeRecord.price);

                for (i = 0; i < 12; i++)
                    printf("\tSIZE %d: %d\n", i + 3, shoeRecord.sizes[i]);

                ifFound = true;
                break;
            }
        }

        if (!ifFound)
            printf("\nInvalid: No record found for stock number %d and style number %d.\n", stockNumber, styleNumber);
    }

    fclose(file);

    printf("\nPress enter to proceed to the MENU: ");
    getch();
    printf("\n\n");
}

void updateRecord() {
    FILE *file = fopen("inventory.txt", "r");
    FILE *tempFile = fopen("tempFile.txt", "w");

    int i, stockNumber, styleNumber, size;
    float tempPrice;
    int tempNumber;
    char userChoice;
    bool ifFound = false;

    printf("\nEnter the stock number: ");
    while (scanf("%d", &stockNumber) != 1 || stockNumber < 0 || stockNumber > 50) {
        printf("\nInvalid input. Please enter a valid stock number.\n\n");
        printf("Enter the stock number: ");
        while (getchar() != '\n');
    }

    printf("Enter the style number: ");
    while (scanf("%d", &styleNumber) != 1 || styleNumber < 0 || styleNumber > 50) {
        printf("\nInvalid input. Please enter a valid style number.\n\n");
        printf("Enter the style number: ");
        while (getchar() != '\n');
    }

    while (fscanf(file, "STOCK NUMBER: %d | STOCK STYLE: %d | PRICE: %f | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d\n",
                      &shoeRecord.stockNumber, &shoeRecord.styleNumber, &shoeRecord.price,
                      &shoeRecord.sizes[0], &shoeRecord.sizes[1], &shoeRecord.sizes[2], &shoeRecord.sizes[3],
                      &shoeRecord.sizes[4], &shoeRecord.sizes[5], &shoeRecord.sizes[6], &shoeRecord.sizes[7],
                      &shoeRecord.sizes[8], &shoeRecord.sizes[9], &shoeRecord.sizes[10], &shoeRecord.sizes[11]) == 15) {

        if (shoeRecord.stockNumber == stockNumber && shoeRecord.styleNumber == styleNumber) {
            printf("\nPrevious details of the stock number %d and style number %d:\n", stockNumber, styleNumber);
            printf("SHOE PRICE: %.2f\n", shoeRecord.price);
            printf("SHOE SIZES:\n");
            for (i = 0; i < 12; i++) {
                printf("\tSIZE %d: %d\n", i + 3, shoeRecord.sizes[i]);
            }

            printf("\nSelect an option:\n");
            printf("\t1. Change the price of the stock item\n");
            printf("\t2. Change the number on hand\n");
            printf("Enter your choice: ");
            while (scanf(" %c", &userChoice) != 1 || (userChoice < '1' || userChoice > '2')) {
                printf("\nInvalid input. Please enter either 1 or 2\n");
                printf("Enter your choice: ");
                while (getchar() != '\n');
            }

            switch (userChoice) {
                case '1':
                    printf("\nEnter the new price for stock number %d: ", shoeRecord.stockNumber);
                    while (scanf("%f", &tempPrice) != 1) {
                        printf("\nInvalid input. Please enter a valid new price\n");
                        printf("Enter the new price for stock number %d: ", shoeRecord.stockNumber);
                        while (getchar() != '\n');
                    }

                    printf("\nDo you want to continue changing the stock item price from %.2f to %.2f?\n", shoeRecord.price, tempPrice);
                    printf("\tEnter [Y] for YES and [N] for NO: ");
                    while (scanf(" %c", &userChoice) != 1 || (userChoice != 'Y' && userChoice != 'N')) {
                        printf("\nInvalid input. Please enter only [Y] and [N].\n");
                        printf("Enter [Y] for YES and [N] for NO: ");
                        while (getchar() != '\n');
                    }

                    if (userChoice == 'N')
                        tempPrice = shoeRecord.price;

                    shoeRecord.price = tempPrice;
                    break;

                case '2':
                    printf("\nEnter the size you want to change the number on hand [3-14]: ");
                    while (scanf("%d", &size) != 1 || size < 3 || size > 14) {
                        printf("\nInvalid input. Please enter valid input\n");
                        printf("\nEnter the size you want to change the number on hand [3-14]: ");
                        while (getchar() != '\n');
                    }
                    size -= 3;

                    printf("Current number on hand for size %d: %d\n", size + 3, shoeRecord.sizes[size]);
                    printf("Enter the new number on hand for size %d of stock number %d: ", size + 3, shoeRecord.stockNumber);
                    while (scanf("%d", &tempNumber) != 1) {
                        printf("\nInvalid input. Please enter valid number on hand\n");
                        printf("Enter the new number on hand for size %d of stock number %d: ", size + 3, shoeRecord.stockNumber);
                        while (getchar() != '\n');
                    }

                    printf("\nDo you want to continue changing the number on hand of size %d from %d to %d?\n", size + 3, shoeRecord.sizes[size], tempNumber);
                    printf("\tEnter Y for YES and N for NO: ");
                    while (scanf(" %c", &userChoice) != 1 || (userChoice != 'Y' && userChoice != 'N')) {
                        printf("\nInvalid input. Please enter only [Y] and [N].\n");
                        printf("Enter [Y] for YES and [N] for NO: ");
                        while (getchar() != '\n');
                    }

                    if (userChoice == 'N')
                        tempNumber = shoeRecord.sizes[size];

                    shoeRecord.sizes[size] = tempNumber;
                    break;

                default:
                    printf("\nInvalid option, the record won't be updated.\n");
                    continue;
            }

            ifFound = true;
        }

        fprintf(tempFile, "STOCK NUMBER: %d | STOCK STYLE: %d | PRICE: %.2f | SIZE:",
                shoeRecord.stockNumber, shoeRecord.styleNumber, shoeRecord.price);

        for (i = 0; i < 12; i++)
            fprintf(tempFile, " %d", shoeRecord.sizes[i]);

        fprintf(tempFile, "\n");
    }

    if (!ifFound)
        printf("\nRecord not found.\n");
    else
        printf("\nSuccessfully updated the record of stock number %d and style number %d.\n", stockNumber, styleNumber);

    fclose(file);
    fclose(tempFile);

    remove("inventory.txt");
    rename("tempFile.txt", "inventory.txt");

    printf("\nPress enter to proceed to the MENU: ");
    getchar();
    printf("\n\n");
}

void deleteRecord() {
    FILE *file = fopen("inventory.txt", "r");
    FILE *tempFile = fopen("tempFile.txt", "w");

    char userChoice;
    int i, stockNumber, styleNumber;
    int ifFound = 0;

    printf("\nEnter the stock number: ");
    while (scanf("%d", &stockNumber) != 1 || stockNumber < 0 || stockNumber > 50) {
        printf("\nInvalid input. Please enter a valid stock number.\n\n");
        printf("Enter the stock number: ");
        while (getchar() != '\n');
    }

    printf("Enter the style number: ");
    while (scanf("%d", &styleNumber) != 1 || styleNumber < 0 || styleNumber > 50) {
        printf("\nInvalid input. Please enter a valid style number.\n\n");
        printf("Enter the style number: ");
        while (getchar() != '\n');
    }

    while (fscanf(file, "STOCK NUMBER: %d | STOCK STYLE: %d | PRICE: %f | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d\n",
                      &shoeRecord.stockNumber, &shoeRecord.styleNumber, &shoeRecord.price,
                      &shoeRecord.sizes[0], &shoeRecord.sizes[1], &shoeRecord.sizes[2], &shoeRecord.sizes[3],
                      &shoeRecord.sizes[4], &shoeRecord.sizes[5], &shoeRecord.sizes[6], &shoeRecord.sizes[7],
                      &shoeRecord.sizes[8], &shoeRecord.sizes[9], &shoeRecord.sizes[10], &shoeRecord.sizes[11]) == 15) {

        if (shoeRecord.stockNumber == stockNumber && shoeRecord.styleNumber == styleNumber) {
            printf("\nPrevious details of the stock number %d and style number %d:\n", stockNumber, styleNumber);
            printf("SHOE PRICE: %.2f\n", shoeRecord.price);
            printf("SHOE SIZES:\n");
            for (i = 0; i < 12; i++) {
                printf("\tSIZE %d: %d\n", i + 3, shoeRecord.sizes[i]);
            }

            ifFound = true;
        } else {
            fprintf(tempFile, "STOCK NUMBER: %d | STOCK STYLE: %d | PRICE: %.2f | SIZE: %d %d %d %d %d %d %d %d %d %d %d %d\n", shoeRecord.stockNumber, shoeRecord.styleNumber, shoeRecord.price, shoeRecord.sizes[0], shoeRecord.sizes[1], shoeRecord.sizes[2], shoeRecord.sizes[3], shoeRecord.sizes[4], shoeRecord.sizes[5], shoeRecord.sizes[6], shoeRecord.sizes[7], shoeRecord.sizes[8], shoeRecord.sizes[9], shoeRecord.sizes[10], shoeRecord.sizes[11]);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!ifFound) {
        printf("Account not found. No changes made.\n");
        remove("tempFile.txt");
        return;
    } 
        
    printf("\nDo you want to continue the deletion?\n");
    printf("\tEnter [Y] for YES and [N] for NO: ");
    while (scanf(" %c", &userChoice) != 1 || userChoice != 'Y' && userChoice != 'N') {
    	printf("\nInvalid input. Please enter only [Y] and [N].\n");
        printf("Enter [Y] for YES and [N] for NO: ");
        while (getchar() != '\n');
    }

    if(userChoice == 'Y'){
        remove("inventory.txt");
        rename("tempFile.txt", "inventory.txt");
        printf("\nSuccessfully deleted stock number %d and style number %d.\n", stockNumber, styleNumber);
    }
    else{
        remove("tempFile.txt");
        printf("\nRecord deletion cancelled.\n");
    }

    printf("\nPress enter to proceed to the MENU: ");
    getchar();
    printf("\n\n");
}

int ifExisting(int stockNumber, int styleNumber) {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        return false; // File not found or unable to open
    }

    int fileStockNumber, fileStyleNumber;
    while (fscanf(file, "STOCK NUMBER: %d | STOCK STYLE: %d | PRICE: %*f | SIZE:", &fileStockNumber, &fileStyleNumber) == 2) {
        char c;
        for (int i = 0; i < 12; i++) {
            fscanf(file, "%*d"); // Read and discard the size values
        }
        while ((c = fgetc(file)) != '\n') {
            if (c == EOF) {
                break;
            }
        }

        if (stockNumber == fileStockNumber && styleNumber == fileStyleNumber) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}
