#include <stdio.h>
//addition Function
void addition(long int a,long int b)
{
    printf("%ld", a + b);
}
//subtraction function
void subtraction(long int a,long int b)
{
    printf("%ld", a - b);
}
//multiplication Function
void multiplication(long int a,long int b)
{
    printf("%ld", a * b);
}
//division Function
void division(long int a, long int b)
{
  if(b!=0){
      if (a % b != 0)
      {
        float c = a / (float)b;
        printf("%f", c);
      }
      else
      {
        printf("%ld", a / b);
      }
    }
  else{
    printf("division by 0 ERROR");
  }
}
int main(){
  printf("Enter num1:\n");
   long int num1;
   scanf("%ld", &num1);
   long int num2;
   printf("Enter num2:\n");
   scanf("%ld", &num2);
   printf("choose what operation you want to do:\n 1. Addition \t 2. Subtraction \t 3. Multipllication \t 4. Division\n");
   int n;
   scanf("%d", &n);
   switch (n)
   {
   case 1:
       addition(num1, num2);
       break;
   case 2:
       subtraction(num1, num2);
       break;
   case 3:
       multiplication(num1, num2);
       break;
   case 4:
       division(num1, num2);
       break;
   }
}
