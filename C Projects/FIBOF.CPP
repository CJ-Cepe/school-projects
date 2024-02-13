//Carl Joseph Cepe          1/11/2019
//BSCS 1-1                  fibonacci sequence using for loop and function
//Group 15
//Computer programming

#include <stdio.h>
#include <conio.h>

int fibo(int n);

void main()
{ clrscr();
  int n;
  printf("\t\t\t\tFibonacci sequence\n");
  printf("\n\t\tEnter the number of terms: ");
  scanf("%d", &n);

		printf("\n\t\tThe first %d terms of Fibonacci series are:\n", n);
		printf("\n");

      fibo(n);
      getch();
      return;
}
// function with for loop
int fibo(int n)
{
   int  first = 0, second = 1;
   int NxtNum, i;

   for (i = 0; i<= n; i++)
  {
	 if (i <= 1)
		  NxtNum = i;
	 else
	 {
	   NxtNum = first+second;
	   first = second;
	   second = NxtNum;
	 }
	printf("  term %d is %d\n- ", i,NxtNum);
   }
}