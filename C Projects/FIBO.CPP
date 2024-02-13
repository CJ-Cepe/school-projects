//Carl Joseph Cepe          1/11/2019
//BSCS 1-1                  fibonacci sequence using recursion(provided)
//Group 15
//Computer programming
#include<stdio.h>
#include<conio.h>
	long int fib(long int num);
int main(void){clrscr();
	int seriesSize,series;
printf("This program prints a fibonacci series.\n");
printf("How many numbers do you want? ");
scanf("%d", &seriesSize);
if(seriesSize < 2)
	seriesSize = 2;
printf("First %d fibonacci numbers: \n", seriesSize);
for(int looper =0; looper < seriesSize; looper++)
	{
		if (looper % 5)
			printf(", %81d", fib(looper));
		else
			printf("\n%81d", fib(looper));
	}
printf("\n");
getch();
return 0;
}

long int fib(long int num)
{
	if (num==0||num==1)
		return num;

		return (fib(num-1)+fib(num-2));
}