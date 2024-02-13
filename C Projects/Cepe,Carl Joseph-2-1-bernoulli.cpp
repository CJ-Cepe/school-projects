// MACHINE PROBLEM : PROBABILITY (1) Bernoulli distribution
// Cepe, Carl Joseph R.    BSCS 2-1		Discrete Structures 2         
// 10/4/2019 	

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <windows.h>

int bernoulli(float p){
    if(p < 0 || p > 1) 
			return -1;
			
    float  number= (float)rand()/(float)(RAND_MAX/1);
    printf("\n\t\t\tRandom Number: %f",number);
    
    if(p < number) 
		return 1;
    
    return 0;
}

int main(){
	char Ans='Y';
while(toupper(Ans)=='Y'){
	system("cls");
	printf("\n\t\t\t __Bernoulli Distribution__");
	float P;
	printf("\n\n\t\t\tInput P: ");
	scanf("%f",&P);
	int I=bernoulli(P);
	if (I==-1)
		printf("\n\t\t\t----Please input 1 or 0 only----\n\n");
		
	printf("\n\t\t\tReturn Value: %d",I);
	printf("\n\n\n\n\t\t\t\tAgain(y/n): ");
	scanf(" %c",&Ans);
}
}
