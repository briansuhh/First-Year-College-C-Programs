#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Account {
    int accountNumber;
    int PIN;
    float balance;
};

struct Account account;

void addAccountToFile();
float getBalance(int accountNumber);
void depositMoney(int accountNumber);
void withdrawMoney(int accountNumber);
void updateBalance(int accountNumber, float newBalance);
void deleteAccountFromFile(int accountNumber);
void menu(int accountNumber);

int main() {
    int accountNumber, PIN;
    char accountNumberStr[10], PINStr[10];
    int exit = 0, found = 0, userChoice;

    while(1){
        FILE* file = fopen("account.dat", "r");

        printf("\nWelcome to PUP-On-Line Banking Systems\n");
        printf("\n1. Log-in\n2. Create Account\n3. Exit\nEnter the number of your choice: ");
        while (scanf("%d", &userChoice) != 1 || userChoice < 1 || userChoice > 3) {
            printf("\nInvalid input. Please enter any number within 1 and 3\n");
            printf("\nEnter the number of your choice: ");
            while (getchar() != '\n');
        }

        switch (userChoice) {
            case 1:
                printf("\nEnter account number: ");
                while (scanf("%s", accountNumberStr) != 1 || strlen(accountNumberStr) != 5) {
                    printf("\nInvalid input. Please enter a valid 5-digit account number.\n\n");
                    printf("Enter the new account number: ");
                    while (getchar() != '\n');
                }

                int accountNumber = atoi(accountNumberStr); // Convert the string to an integer

                while (fscanf(file, "Account Number: %d | PIN: %d | Balance: %f\n",
                        &account.accountNumber, &account.PIN, &account.balance) == 3) {
                    if (account.accountNumber == accountNumber) {
                        found = 1;
                        printf("Enter PIN: ");
                        while (scanf("%s", PINStr) != 1 || strlen(PINStr) != 4) {
                            printf("\nInvalid input. Please enter a valid 4-digit PIN number.\n\n");
                            printf("Enter PIN: ");
                            while (getchar() != '\n');
                        }
                        
                        int PIN = atoi(PINStr); // Convert the string to an integer

                        if (account.PIN == PIN) {
                            fclose(file);
                            menu(accountNumber);
                        }
                        else {
                            fclose(file);
                            printf("Incorrect PIN.\n");
                        }   
                    }
                }
                if(!found)
                    printf("\nAccount number not found\n");
                break;
            case 2:
                addAccountToFile(); 
                main();
                break;
            case 3:
                printf("\nThank you for putting your trust on our company.\n");
                return 0;
        }    
    }
    return 0;
}

void addAccountToFile() {
    FILE* file = fopen("account.dat", "r");
    int accountNumber, PIN;
    float balance;
    char accountNumberStr[10], PINStr[10];

    printf("\nEnter new account number: ");
    while (scanf("%s", accountNumberStr) != 1 || strlen(accountNumberStr) != 5) {
        printf("\nInvalid input. Please enter a valid 5-digit account number.\n\n");
        printf("Enter new account number: ");
        while (getchar() != '\n');
    }

    accountNumber = atoi(accountNumberStr);

    while (fscanf(file, "Account Number: %d | PIN: %d | Balance: %f\n",
                  &account.accountNumber, &account.PIN, &account.balance) == 3) {
        if (account.accountNumber == accountNumber) {
            printf("\nInvalid account number. An account with the same account number already exists.\n");
            fclose(file);
            return;
        }
    }

    printf("Enter new PIN: ");
    while (scanf("%s", PINStr) != 1 || strlen(PINStr) != 4) {
        printf("\nInvalid input. Please enter a valid 4-digit PIN number.\n\n");
        printf("Enter new PIN: ");
        while (getchar() != '\n');
    }
    
    PIN = atoi(PINStr);

    printf("Enter initial balance: ");
    while (scanf("%f", &balance) != 1) {
        printf("\nInvalid input. Please enter a valid amount.\n\n");
        printf("Enter new balance: ");
        while (getchar() != '\n');
    }

    fclose(file);

    file = fopen("account.dat", "a");

    fprintf(file, "Account Number: %05d | PIN: %04d | Balance: %.2f\n", accountNumber, PIN, balance);
    printf("\nAccount added successfully.\n");

    fclose(file);
}

float getBalance(int accountNumber) {
    FILE* file = fopen("account.dat", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    while (fscanf(file, "Account Number: %d | PIN: %d | Balance: %f\n",
                  &account.accountNumber, &account.PIN, &account.balance) == 3) {
        if (account.accountNumber == accountNumber) {
            fclose(file);
            return account.balance;
        }
    }

    fclose(file);
}

void depositMoney(int accountNumber) {
    float balance = getBalance(accountNumber);
    float amount;

    printf("\nEnter amount to deposit: ");
    while (scanf("%f", &amount) != 1) {
        printf("\nInvalid input. Please enter a valid amount to deposit.\n");
        printf("\nEnter amount to deposit: ");
        while (getchar() != '\n');
    }
    updateBalance(accountNumber, balance + amount);
    printf("\nBalance updated successfully. You now have %.2f in your account\n", balance + amount);
}

void withdrawMoney(int accountNumber) {
    float balance = getBalance(accountNumber);
    float amount; 

    if (amount > balance) {
        printf("Insufficient balance. Transaction canceled.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    while (scanf("%f", &amount) != 1) {
        printf("\nInvalid input. Please enter a valid amount to withdraw.\n\n");
        printf("\nEnter amount to withdraw: ");
        while (getchar() != '\n');
    }
    updateBalance(accountNumber, balance - amount);
    printf("\nBalance updated successfully. You now have %.2f in your account\n", balance - amount);
}

void updateBalance(int accountNumber, float newBalance) {
    FILE* file = fopen("account.dat", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE* tempFile = fopen("tempFile.dat", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    int found = 0;
    while (fscanf(file, "Account Number: %d | PIN: %d | Balance: %f\n",
                  &account.accountNumber, &account.PIN, &account.balance) == 3) {
        if (account.accountNumber == accountNumber) {
            found = 1;
            account.balance = newBalance;
        }

        fprintf(tempFile, "Account Number: %05d | PIN: %04d | Balance: %.2f\n",
                account.accountNumber, account.PIN, account.balance);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("\nAccount not found. No changes made.\n");
        remove("tempFile.dat");
        return;
    }

    remove("account.dat");
    rename("tempFile.dat", "account.dat");
}

void deleteAccountFromFile(int accountNumber) {
    char userChoice;
    FILE* file = fopen("account.dat", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE* tempFile = fopen("tempFile.dat", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    int found = 0;
    while (fscanf(file, "Account Number: %d | PIN: %d | Balance: %f\n",
                   &account.accountNumber, &account.PIN, &account.balance) == 3) {
        if (account.accountNumber == accountNumber) 
            found = 1;
        else 
            fprintf(tempFile, "Account Number: %05d | PIN: %04d | Balance: %.2f\n",
                    account.accountNumber, account.PIN, account.balance);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("Account not found. No changes made.\n");
        remove("tempFile.dat");
        return;
    }

    printf("\nAccount Number %d has been found. Enter [Y] for DELETE and [C] for CANCEL: ", accountNumber);
    while (scanf(" %c", &userChoice) != 1 || (userChoice != 'Y' && userChoice != 'C')) {
        printf("\nInvalid input. Please enter only [Y] and [C]\n");
        printf("\nAccount Number %d has been found. Enter [Y] for DELETE and [C] for CANCEL: ", accountNumber);
        while (getchar() != '\n');
    }

    if (userChoice == 'Y') {
        remove("account.dat");
        rename("tempFile.dat", "account.dat");
        printf("\nAccount deleted successfully.\n");
        main();
    } else {
        remove("tempFile.dat");
        printf("\nAccount deletion cancelled.\n");
    }
}

void menu(int accountNumber) {
    int userChoice;

    while (1) {
        printf("\n\nWelcome to PUP-On-Line Banking Systems\n");
        printf("\n1. Show balance\n2. Deposit\n3. Withdraw\n4. Delete account\n5. Logout\nEnter the number of your choice: ");
        while (scanf("%d", &userChoice) != 1 || userChoice < 1 || userChoice > 5) {
            printf("\nInvalid input. Please enter any number from 1 to 5\n");
            printf("\nEnter the number of your choice: ");
            while (getchar() != '\n');
        }

        switch (userChoice) {
            case 1:
                printf("\nYour balance is: %.2f", getBalance(accountNumber));
                break;
            case 2:
                depositMoney(accountNumber);
                break;
            case 3:
                withdrawMoney(accountNumber);
                break;   
            case 4:
                deleteAccountFromFile(accountNumber);
                break;
            case 5:
                printf("\nDo you really want to log out?");
                printf("\nEnter [Y] for YES and [N] for NO: ");
                while (scanf(" %c", &userChoice) != 1 || (userChoice != 'Y' && userChoice != 'N')) {
                    printf("\nInvalid input. Please enter only [Y] and [N]\n");
                    printf("\nEnter [Y] for YES and [N] for NO: ");
                    while (getchar() != '\n');
                }

                if (userChoice == 'Y'){
                    printf("\nYou have successfully logged out of your account.\n");
                    return;
                }
        }
    }
}

/*
notes:
login and create account - done
remove the part where we login first before creating an account - done
menu validation from 1 to 7 - done
debug show balance (Account number not found.
                    Your balance is: -1.00) - done
validation for duplicate account number in creating an account - done
validation error for 5 digit pin and 4-digit pin - done
*/

// void displayAllAccounts() {
//     FILE* file = fopen("account.dat", "r");
//     if (file == NULL) {
//         printf("Error opening file!\n");
//         return;
//     }

//     int count = 0;
//     while (count < 100 &&
//             fscanf(file, "Account Number: %d | PIN: %d | Balance: %f\n",
//                     &account.accountNumber, &account.PIN, &account.balance) == 3) {
//         printf("Account %d:\n", count + 1);
//         printf("Account Number: %d\n", account.accountNumber);
//         printf("PIN: %d\n", account.PIN);
//         printf("Balance: %.2f\n\n", account.balance);
//         count++;
//     }
    
//     fclose(file);
// }

// if(userChoice == 1){
        //     printf("\nEnter account number: ");
        //     while (scanf("%s", accountNumberStr) != 1 || strlen(accountNumberStr) != 5) {
        //         printf("\nInvalid input. Please enter a valid 5-digit account number.\n\n");
        //         printf("Enter the new account number: ");
        //         while (getchar() != '\n');
        //     }

        //     int accountNumber = atoi(accountNumberStr); // Convert the string to an integer

        //     while (fscanf(file, "Account Number: %d | PIN: %d | Balance: %f\n",
        //             &account.accountNumber, &account.PIN, &account.balance) == 3) {
        //         if (account.accountNumber == accountNumber) {
        //             found = 1;
        //             printf("Enter PIN: ");
        //             while (scanf("%s", PINStr) != 1 || strlen(PINStr) != 4) {
        //                 printf("\nInvalid input. Please enter a valid 4-digit PIN number.\n\n");
        //                 printf("Enter PIN: ");
        //                 while (getchar() != '\n');
        //             }
                    
        //             int PIN = atoi(PINStr); // Convert the string to an integer

        //             if (account.PIN == PIN) {
        //                 fclose(file);
        //                 menu(accountNumber);
        //             }
        //             else{
        //                 fclose(file);
        //                 printf("Incorrect PIN.\n");
        //             }   
        //         }
        //     }
        //     if(!found)
        //         printf("\nAccount number not found\n");
        // }
        // else if(userChoice == 2){
        //     addAccountToFile(); 
        //     main();
        // }
        // else{
        //     printf("\nThank you for putting your trust on our company.\n");
        //     break;
        // }  