//MACHINE PROBLEM : RECURSION

//Author: CEPE, CARL JOSEPH R.

//Date : AUGUST 30 2019

//Section: BSCS 2-1

#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

int POWER();
int FIBO();
int fibo(int n);
int power(int X, int n);
int GCD();
int gcd(int n1, int n2);
void EXIT();
void gotoxy(short x, short y);

int main()
{
int sagot;
while(sagot!=4){system("CLS");
	gotoxy(37,3);
printf("MENU");
	gotoxy(13,5);
printf("'Choose one function by typing the corresponding number'");
	gotoxy(20,9);
printf("(1). X^n using recursion. ");
	gotoxy(20,11);
printf("(2). nth fibonacci number using recursion. ");
	gotoxy(20,13);
printf("(3). greatest common divisor using recursion");
	gotoxy(20,17);
printf("(4). EXIT");
	gotoxy(20,20);
printf("Choose one: ");
	scanf("%d",&sagot);

switch(sagot){
case 1:
	POWER();
	break;
case 2:
	FIBO();
	break;
case 3:
	GCD();
	break;
case 4:
	EXIT();
	break;
default:
	gotoxy(31,20);
	printf("Invalid number try again"            );
	getch();
}    }
}


//-------------------X^n---------------------
int POWER(){A:
char ans='Y';
while(toupper(ans)=='Y'){
 system("CLS");		
 int X=0,result=0,n=0;
	printf("\n\t\tGiven a real number X and a non negative integer n");
	printf("\n\t\t\t     find X^n using recursion.");
	printf("\n\n\n\t\tINPUT Value of X: ");
	scanf("%d",&X);
	printf("\n\n\t\tINPUT Value of n: ");
	scanf("%d",&n);
	if(n<0)
		{printf("\n\n\t\tinvalid n value");
			getch();
			goto A;}
	result=power(X,n);
	printf("\n\n\t\tResult: %d",result);
printf("\n\n\t\tAgain(y/n): ");
scanf(" %c", &ans);	
}//while
main();
return 0;
}

int power(int X, int n)
{
    if (n!= 0)
        return (X*power(X,n-1));
    else
        return 1;
}

//--------------fibonacci---------------------
int FIBO(){A:
char ans='Y';
while(toupper(ans)=='Y'){
 system("CLS");		
 int result=0,n=0;
	printf("\n\t\t\tGiven a non negative integer n");
	printf("\n\t\tfind the nth fibonacci number using recursion");
	printf("\n\n\n\t\tINPUT nth: ");
	scanf("%d",&n);
	if(n<0)
		{printf("\n\n\t\tinvalid n value");
			getch();
			goto A;}
	result=fibo(n);
	printf("\n\n\t\tResult: %d",result);
printf("\n\n\t\tAgain(y/n): ");
scanf(" %c", &ans);	
}//while
main();
return 0;
}

int fibo(int n) 
{ 
   if (n <= 1) 
      return n; 
      
   return fibo(n-1) + fibo(n-2); 
} 

//------------greatest common divisor--------------
int GCD(){A:
char ans='Y';
while(toupper(ans)=='Y'){
 system("CLS");		
 int n2=0,result=0,n1=0;
	printf("\n\t\t      Given two intergers not both zero");
	printf("\n\t     find their greatest common divisor using recursion.");
	printf("\n\n\n\t\tINPUT Value of n1: ");
	scanf("%d",&n1);
	printf("\n\n\t\tINPUT Value of n2: ");
	scanf("%d",&n2);
	if(n1==0||n2==0)
		{printf("\n\n\t\tinvalid n value");
			getch();
			goto A;}
	result=gcd(n1,n2);
	printf("\n\n\t\tResult: %d",result);
printf("\n\n\t\tAgain(y/n): ");
scanf(" %c", &ans);	
}//while
main();
return 0;
}

int gcd(int n1, int n2)
{
    if (n2 != 0)
       return gcd(n2,n1%n2);
    else 
       return n1;
}

//----------EXIT------------------

void EXIT()
{
system("CLS");
gotoxy(35,3);
printf("BSCS 2-1");
gotoxy(23,4);
printf("Computer Programming - Recursion");
gotoxy(31,7);
printf("Carl Joseph Cepe");
gotoxy(29,1);
printf("Discrete Structures 2 ");
gotoxy(30,12);
printf(" >>> BYE BYE <<< ");
getch();
printf("\n\n\n\n\n\n\n\n");
exit(0);

}

//--------gotoXY---------------
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
