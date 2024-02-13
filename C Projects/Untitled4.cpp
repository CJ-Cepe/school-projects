#include <stdio.h>
#include <math.h>

int BIRTHDAY(double p){
	int result=ceil(sqrt(2*365*log(1/(1-p)))); 
		printf("%f = %d\n",p,result);
}//birthday

int main(){
	BIRTHDAY(0.70);
	BIRTHDAY(0.80);
	BIRTHDAY(0.90);
	BIRTHDAY(0.95);
	BIRTHDAY(0.98);
	BIRTHDAY(0.99);
}
