#include <stdio.h>
#include <stdlib.h>

int main() {
    int searchElement, insertElement, deleteValue, temp, arrayLength, ascendDescend, elementDelete;
    int searchCount, deleteCount, sortCount;
    int menuChoice, insertChoice;
    int X[5] = {-1, -1, -1, -1, -1};
    char userDecision, insertDecision, deleteDecision; 
    // ONE Emman

    // Get the number of elements to be inserted by the user
    // Loop runs until the user inputs a valid number of elements
    do {
        printf("Enter the number of values in the array [Min - 2 | Max - 3]: ");
        scanf("%d", &arrayLength);

        if (arrayLength < 2 || arrayLength > 3) {

        printf("Length %d is an invalid input!\n", arrayLength);
    }

    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    } while (arrayLength < 2 || arrayLength > 3); 
    // TWO Elli

    // Get the values from the user
    for (int i = 0; i < arrayLength; i++) {
        printf("Enter an integer for element %d: ", i + 1);
        scanf("%d", &X[i]);
    }

    // Label for jumping back to the MAIN MENU
    menu:
    do {
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
        // Display the main menu options for the user
        printf("[1] Searching\n[2] Insertion\n[3] Deletion\n[4] Sorting\n[5] Exit");
        printf("\nEnter 1 - 5 to proceed: ");
        scanf("%d", &menuChoice);

        // Check if the user input is valid, and loop again if not
        if (menuChoice > 5 || menuChoice < 1)
            printf("Menu %d is an invalid input! Pleasde, try again.\n", menuChoice);
            
    } while (menuChoice > 5 || menuChoice < 1); 
    // THREE Nhil

    // Switch statement for the MAIN MENU options
    choice:
    switch (menuChoice) {
    case 1: { // SEARCHING
        searchCount = 0;
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>\n\n");
        
        printf("Enter the value you want to search: ");
        scanf("%d", &searchElement);

        // Loop through the array to search for the given element
        for (int i = 0; i < 5; i++) {
            if (searchElement == X[i]) {
            printf("%d is X[%d] or %s element.\n", searchElement, i, (i == 0   ? "FIRST" : i == 1 ? "SECOND" : i == 2 ? "THIRD" : i == 3 ? "FOURTH" : "FIFTH"));
            searchCount++;
            break;
            }
        }

        // If the search count has a value of 0, the element was not found
        if (searchCount == 0)
            printf("%d is not present in the array!\n", searchElement);
        goto prompt;
        break;
        // FOUR Jiro
    }         
    case 2: { // INSERTION
        insertChoice = 0;
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

        // Display the elements of the array before insertion
        printf("Here are the elements in the array X[5] = {");
        for (int i = 0; i < 5; i++)
            printf("%d%s", (X[i] == -1) ? 0 : X[i], (i == 4) ? "" : ", ");
        printf("}");

        printf("\n\nEnter the value you want to insert: ");
        scanf("%d", &insertElement);

        // Ask the user to enter a position to insert the element
        // Repeat through the process if the input is not valid
        do {
            printf("\nEnter the position of the element (1 - 5): ");
            scanf("%d", &insertChoice);

            if (insertChoice > 5 || insertChoice < 1)
            printf("Element %d is a invalid input! Please, try again.\n", insertChoice);

            printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        } while (insertChoice > 5); 
        // FIVE MC

        // Check if the selected position in the array is occupied
        // If occupied, ask the user for permission to replace the value
        if (X[insertChoice - 1] != -1)
            printf("\nElement %d has a value of %d\n", insertChoice, X[insertChoice - 1]);

        printf("ENTER [C] TO CONTINUE: ");
        scanf(" %c", &insertDecision);

        if (insertDecision != 'C' && insertDecision != 'c')
            printf("\nThe insertion process has been terminated!\n");

        if (insertDecision == 'C' || insertDecision == 'c'){
            X[insertChoice - 1] = insertElement;
            printf("\nThe value of %d has been inserted in element %d.\n", insertElement, insertChoice);
        }
        goto prompt;
        break;
        // SIX Cy
    }
    case 3: { // DELETION
        do {
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

        // Display the elements of the array before deletion
        printf("Here are the elements in the array X[5] = {");
        for (int i = 0; i < 5; i++)
            printf("%d%s", (X[i] == -1) ? 0 : X[i], (i == 4) ? "" : ", ");
        printf("}");

        deleteCount = 0;
        printf("\n\nEnter the value that you want to delete: ");

        // Check if the input is a letter
        int input_check = scanf("%d", &deleteValue); // scanf("%d", &deleteValue);
        if (input_check != 1) {
            printf("Invalid input! Please, enter a number.\n");
            // Flush the input buffer to avoid the next scanf call reading the same
            // invalid value Discard any characters in the input buffer until a
            // newline character is reached
            while ((getchar()) != '\n');
            continue;
        }
        
        // Search for the value in the array
        for (elementDelete = 0; elementDelete < 5; elementDelete++) {
            if (deleteValue == X[elementDelete]) {
                deleteCount++;
                break;
            }
        }

        if (deleteCount == 0)
            printf("Value %d is not present in the array!\n", deleteValue);

        // Repeat this loop if there is an invalid value
        } while (deleteCount == 0); 
        // SEVEN Kyle

        // Ask the user for confirmation on deleting the element
        printf("\nEnter [C] to delete element %d with value of %d: ", elementDelete + 1, deleteValue);
        scanf(" %c", &deleteDecision);

        if (deleteDecision == 'C' || deleteDecision == 'c') {
            X[elementDelete] = -1;
            printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf("\nElement %d with the value of %d has been deleted.\n",
            elementDelete + 1, deleteValue);
        } 

        else {
            printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf("\nThe deletion process has been terminated!\n");
        }
        goto prompt;
        break; 
        // EIGHT Kenzo
    }
    case 4: { // SORTING
        // Count the element inside of the array
        sortCount = 0;
        for (int i = 0; i < 5; i++)
            if (X[i] != -1)
                sortCount++;

        // Check if the array has less than or equal to 1 element
        if (sortCount <= 1) {
            printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
            printf("The array cannot be sorted because it only contains %d element.", sortCount);
        } 

        else {
            ascendDescend = 0;
            do { // Ask the user for the order of sorting
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
                printf("Enter [1] for ascending or [2] for descending: ");
                scanf("%d", &ascendDescend);

                if (ascendDescend != 1 && ascendDescend != 2)
                    printf("Invalid input!\n");

            } // Repeat the question if there is an invalid input from the user
            while (ascendDescend != 1 && ascendDescend != 2);

            // Process for sorting
            for (int i = 0; i < 5 - 1; i++) {
                for (int j = 0; j < 5 - i - 1; j++) {
                    if (X[j] != -1 && X[j + 1] != -1) {
                        if ((ascendDescend == 1 && X[j] > X[j + 1]) || (ascendDescend == 2 && X[j] < X[j + 1])) {
                            temp = X[j];
                            X[j] = X[j + 1];
                            X[j + 1] = temp;
                        }
                    }
                }
            }
            // NINE Brian

            // Display the value of the sorted array
            printf("\nThe sorted array for %s is: ", (ascendDescend == 1 ? "ASCENDING" : "DESCENDING"));
            for (int i = 0; i < 5; i++)
            if (X[i] != -1)
                printf("%d ", X[i]);
                printf("\n");

            goto prompt;
            break;
            // TEN Xian
        }
    }
    case 5: {}// EXIT        
            //ELEVEN Eizhel
    }
    
    while (menuChoice != 5) {
        prompt:
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
        printf("\nDo you want to continue?\n");
        printf("\t[\'Y\'] YES\n\t[\'M\'] GO BACK to Menu\n");
        printf("Enter the letter of your choice: ");
        scanf(" %c", &userDecision);
        if (userDecision == 'Y' || userDecision == 'y')
            goto choice;
        else if (userDecision == 'M' || userDecision == 'm')
            goto menu;
        else
            printf("Invalid input! Please, try again!\n");
    }

    printf("\nThank you for using our program! ");
    return 0;
}
