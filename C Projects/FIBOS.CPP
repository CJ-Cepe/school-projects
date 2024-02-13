//Carl Joseph Cepe          1/11/2019
//BSCS 1-1                  fibonacci sequence using for loop without function
//Group 15
//Computer programming

#include <stdio.h>
#include <conio.h>
int main()
{ clrscr();
  int n, first = 0, second = 1;
  int NxtNum, i;
  printf("\t\t\t\tFibonacci sequence\n");
  printf("\n\t\tEnter the number of terms: ");
  scanf("%d", &n);

		printf("\n\t\tThe first %d terms of Fibonacci series are:\n", n);
		printf("\n");

  for (i = 0; i <= n; i++)
  {
	 if (i <= 1)
		  NxtNum = i;
	 else
	 {
	   NxtNum = first+second;
	   first = second;
	   second = NxtNum;
	 }

	printf("  term %d is %d\n  -> ", i,NxtNum);
  }
  getch();
  return 0;
}

