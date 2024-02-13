#include <stdio.h>
#include <stdlib.h>
int bernoulli(float p){
    if(p < 0 || p > 1) 
			return -1;
			
    float  number= (float)rand()/(float)(RAND_MAX/1);
    printf("\n\t\tRandom Number: %f",number);
    
    if(p < number) 
		return 1;
    
    return 0;
}

int main(){
	system("cls");
	float P;
	printf("\n\n\t\tInput P: ");
	scanf("%f",&P);
	int I=bernoulli(P);
	if (I==-1)
		printf("\n\t\t\t----Please input 1 or 0 only----\n\n");
		
	printf("\n\t\t\tReturn Value: %d",I);
	
}
