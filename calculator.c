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
