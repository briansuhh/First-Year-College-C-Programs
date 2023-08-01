/*
Instructions:
Write a program in C to count the number of vowels and consonants in a string using a pointer. 

Test Data : 
Input a string: string 

Expected Output :
Number of vowels : 1                                                                                         
Number of constant : 5

*/

#include <stdio.h>
#include <ctype.h>

void vowelsAndConsonants(char *ptr, int *vowel, int *consonant){
    while (*ptr != '\0'){
        char ch = toupper(*ptr);

        if (ch >= 'A' && ch <= 'Z'){
            if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
                (*vowel)++;
            else
                (*consonant)++;
        }
        ptr++;
    }
    
}

int main(){
    char str[100];
    char *ptr = str;

    int vowelCount = 0, consonantCount = 0;

    printf("Input a string: ");
    scanf("%s", str);

    vowelsAndConsonants(ptr, &vowelCount, &consonantCount);

    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);

    return 0;
}