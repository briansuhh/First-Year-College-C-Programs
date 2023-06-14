#include <stdio.h>

// Make a program that tells you if you are accepted to the Jedi Knight Academy
// If you are recommended by Master Obi Wan, you will pass regardless of your
// height, age, and citizenship If not, you need to pass the 3 test (height,
// age, and citizenship)

int main() {
  int recommended, height, age, citizenship;
  char name [80];

  // Entering the information of the applicant
  printf("What is your name? ");
  scanf("%s", name);
  printf("Are you recommended by Master Obi Wan? (1=yes, 0=no): ");
  scanf("%d", &recommended);


  // Process
  if (recommended == 1)
    printf("Congratulations %s! Your application is accepted.", name);


  else if (recommended == 0)
  {
    printf("What is your height? ");
    scanf("%d", &height);
    
    //1st nested if
    if (height >= 200)
    {
      printf("What is your age? ");
      scanf("%d", &age);
      //2nd nested if
      if (age >= 21 && age <= 25)
      {
        printf("Are you a citizen of Planet Endor? (1=yes, 0=no) ");
        scanf("%d", &citizenship);
        //3rd nested if
        if (citizenship == 1)
        {
          printf("Your application is accepted.");
        }
        else printf("%s, try again next time. You are rejected because your citizenship is not qualified on the standard of Jedi Knight Academy.", name);
      }
      else printf("%s, try again next time. You are rejected because your age is not qualified on the standard of Jedi Knight Academy.", name);
    }
    else printf("%s, try again next time. You are rejected because your height is not qualified on the standard of Jedi Knight Academy.", name);
  }
    
  return 0;
}

