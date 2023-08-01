/*
Instructions:
Write a program in C to print a string in reverse using a pointer. 

Test Data : 
Input a string : w3resource 

Expected Output :
Pointer : Print a string in reverse order :                                                                  
------------------------------------------------                                                              
Input a string :w3resource                                                                                  
Reverse of the string is : ecruoser3w

*/

#include <stdio.h>
#include <string.h>

void reverseString(char *str){
    int i;
    int length = strlen(str);

    for(i = length - 1; i >= 0; i--)
        printf("%c", *(str + i));
}

int main(){
    char str[100];

    printf("Input a string: ");
    // gets(str);
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("\nPointer : Print a string in reverse order:\n");
    printf("------------------------------------------------\n");
    printf("Input a string: %s", str);

    printf("\nReverse of the string is: ");
    reverseString(str);

    return 0;
}