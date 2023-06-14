#include <stdio.h>

//Make a program converting inputted seconds to hour:minute:seconds format

// 3665 
// 01:01:05 

int main(){
  int hour, minute, second, num;
  char name[80];
  
  printf("Your name please:  ");
  scanf("%s", name);
  printf("Please enter number of seconds:  ");
  scanf("%d", &num);
  
  // Let's say the inputted number is 3665
  hour = num / 3600; // The answer is 1
  minute = (num - (hour * 3600)) / 60; // The answer is 1
  second = (num - (hour * 3600)) % 60 ; // The answer is 5
  printf("\n%s, %d second/s is %02d:%02d:%02d in hour:minute:second format.", name, num, hour, minute, second); //name, num second/s is  in hour:minute: second format
  return 0;
}



// int main(void){
//   int hour, minute, second, num, input;
//   float minute_f;
//   char name[80];
//   printf("Your name please:  ");
//   scanf("%s", name);
//   printf("Please enter number of seconds:  ");
//   scanf("%d", &num);
  
//   // Let's say the inputted number is 3665
  
//   hour = num / 3600; // The answer is 1
//   minute = (num - (hour * 3600)) / 60; // The answer is 1
//   //minute_f is the combination of minutes and seconds
//   minute_f = (num - (hour * 3600)) / 60.0; // The answer is 1.083333
//   second = (minute_f * 60) - (minute * 60); // The answer is 5
//   printf("\n%d second/s is %02d:%02d:%02d in hour:minute:second format.", num, hour, minute, second);
// }
