#include<stdio.h>
#include<conio.h>
#include<windows.h>
int fibo(int n);

int main(){A:
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
return 0;
}

int fibo(int n) 
{ 
   if (n <= 1) 
      return n; 
      
   return fibo(n-1) + fibo(n-2); 
} 
