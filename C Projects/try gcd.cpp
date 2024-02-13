#include<stdio.h>
#include<conio.h>
#include<windows.h>
int GCD(int n1, int n2);

int main(){A:
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
	result=GCD(n1,n2);
	printf("\n\n\t\tResult: %d",result);
printf("\n\n\t\tAgain(y/n): ");
scanf(" %c", &ans);	
}//while
return 0;
}

int GCD(int n1, int n2)
{
    if (n2 != 0)
       return GCD(n2,n1%n2);
    else 
       return n1;
}

