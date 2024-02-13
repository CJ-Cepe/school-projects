#include<stdio.h>
#include<conio.h>
#include<windows.h>
int power(int X, int n);
int main(){A:
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
return 0;
}

int power(int X, int n)
{
    if (n!= 0)
        return (X*power(X,n-1));
    else
        return 1;
}
