#include<conio.h>
#include<stdio.h>
//PRESIDENT"S ADVISER
int main(){//system(cls);
//*************Variables******************
int start,adviser[]={1,2,3,4,5,6,7,8,9,10,11,12,13},interval,z=5,i,nextposition;

printf("PRESIDENT'S ADVISER");
printf("\nEnter where to start: ");
scanf("%d",&start);start--;
printf("\nEnter the interval: ");
scanf("%d",&interval);
nextposition=start+interval;
for(i=0; i<z;i++)
{ 
	if(nextposition>12){
		while(nextposition>12){
		nextposition=nextposition-13;
		}
	printf("%d, ", adviser[nextposition-1]);
	}
	else
	{	
		printf("%d, ", adviser[nextposition-1]);
		
	}
	nextposition+=interval;
}
}
