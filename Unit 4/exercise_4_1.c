#include <stdio.h>

// Create a program that will determiine wheter a person is a child(0-12), a teen-ager(13-19) or an adult(20 and above)

// 18
// You are a teen-ager

int main(){
    int age;
    char name[80];

    printf("Please input your name:    ");
    scanf("%s", name);
    printf("Please enter your age:    ");
    scanf("%d", &age);

    if (age <= 12)
        printf("\n%s, based on your age, you are a child.", name);

    if (age >= 13 && age <= 19)
        printf("\n%s, based on your age, you are a teen-ager.", name);
    
    if (age >= 20)
        printf("\n%s, based on your age, you are an adult.", name);
        
    return 0;
}
