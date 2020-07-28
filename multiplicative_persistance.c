/*
This code is meant to calculate the number that satisfies the multiplicative presistence 12. At least
I hope so.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define nines 1  //this is how many digits must be equal to 9
char digits[] = {'0','1','2','3','4','5','6','7','8','9'};

void copy (int a[], int b[]) //this function just copies the elements of an array into another one (a->b)
{
  if(sizeof(a)==sizeof(b))
  {
    for(int i=0; i<sizeof(a); i++)
    {
      b[i] = a[i];
    }
  }
  else
  {
    printf("error: array of different size");
  }
}
/*This persistence function is meant to do the recursive multiplication. It takes an array as an input.
That's the array generated from the other function (calc()). All the elements of the array are just the digits
of the number, so this function will do a simple multiplication between all the elements. The result is just
an integer number, so it is converted again into an array of digits in order to do the multiplication again, until
it becomes a number of a single digit
*/
int persistence (int num[])
{
  int pers, step, length=sizeof(num);
  int temp[length];
  copy(num, temp);
  do
  {
    int c=0, less=0;
    for(int i=0; i<length-less; i++)
    {
      step*=temp[i];
    }
    /*
    conversion to array: count number of digits */  
    /* extract each digit */
    while (step != 0)
    {
      temp[c] = step % 10;
      step /= 10;
      c++;
    }
    less++;
  } while (sizeof(temp)>1);
  return pers;
}

/*This function will generate the number that wil be put in the persistence function.
At the beginning of the entire code, there is a #define nines. So that number will be used
to set how many 9's will be in the number. The first two digits will be generated with the for cycle
with the sequence: 22,23,24,...,32,33,34,...,97,98,99 in order to get all the possible combinations.
The remaining digits will be either 7,8 or 9. The 9's are already set at the beginning, as said before.
The for with the variable "se" is responsible of setting the amount of 7's in the number, so the remaining
digits will be all 8's.
*/
int calc (int l)
{
  int num[l]; //number of l digits
  int a,b, N=l-2, result; //a=counts the 7's
  for(int se=0; se<l-2-nines; se++) //At least, can be l-2(=N by definition) digits equals to 7
  {                               //but there are also the digits that are equale to nine (nines)
    for(int one=2; one<10; one++)
    {
      num[0] = one;
      for(int two=2; two<10; two++)
      {
        num[1] = two;
        a=0;
        for(int i=2; i<l; i++)   //the code starts entering number from the first cell of the array
        {
          if(a<se)  //it puts 7's in the first "se" cells, then it puts 8's and finally 9's
          {
            num[i]=7;
          }
          else
          {
            if(i<l-nines)
            {
              num[i] = 8;
            }
            else
            {
              num[i] = 9;
            }
          }
        } //all the digits have been entered
        for(int i=0; i<l; i++)
        {
          printf("%d", num[i]);
        }
        printf("\n");
        result = num; //it refers to the function that gives the multiplicative persistence of the number
      }
    }
  }
  return result;
}

int main()
{
  int input;
  printf("Enter the number of digits:\n");
  scanf(" %d", &input);
  persistence(calc(input));
  system("PAUSE");
  return 0;
}