// MACHINE PROBLEM : PROBABILITY (3) SAME BIRTHDAY
// Cepe, Carl Joseph R.    BSCS 2-1		Discrete Structures 2         
// 10/4/2019 	


#include <stdio.h>
#include <math.h>
#include <ctype.h> 
#include <windows.h>

int BIRTHDAY(double p){
	int result=ceil(sqrt(2*365*log(1/(1-p)))); 
		printf("\n\n\t\t\t      %.02f    =     %d\n",p,result);
}//birthday

int main(){
	
char Ans='n';
while(toupper(Ans)!='Y'){
	system("cls");
	printf("\n\t\t\t       __Same Birthday__");
printf("\n\n\t\t\t   PERCENTAGE   # of people    ");

	BIRTHDAY(0.70);
	BIRTHDAY(0.80);
	BIRTHDAY(0.90);
	BIRTHDAY(0.95);
	BIRTHDAY(0.98);
	BIRTHDAY(0.99);
	
	printf("\n\n\n\n\t\t\t\tExit(y/n): ");
	scanf(" %c",&Ans);
}
}
