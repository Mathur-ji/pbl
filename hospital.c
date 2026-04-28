#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int captcha() {
   int captcha, user;
   srand(time(0));  // random seed
   captcha = rand() % 9000 + 1000;  // generates 4-digit number
   printf("CAPTCHA: %d\n", captcha);
   printf("Enter CAPTCHA: ");
   scanf("%d", &user);
   if (captcha == user){
        printf("KINDLY SELECT SERVICE : \n");
        return 1;
   }
   else{
       printf("Wrong CAPTCHA!\n");
   }
   return 0;
}
