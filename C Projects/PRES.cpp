#include<conio.h>
#include<stdio.h>
//PRESIDENT"S ADVISER
int main(){//system(cls);
//*************Variables******************
int n=13;
int start,adviser[n]={1,2,3,4,5,6,7,8,9,10,11,12,13},interval,z=5,i,nextposition;
printf("PRESIDENT'S ADVISER");
printf("\nEnter where to start: ");
scanf("%d",&start);start--;
printf("\nEnter the interval: ");
scanf("%d",&interval);interval--;
nextposition=start+interval;
for(i=0;i<z;i++)
{ 	int a=n-1;
	if(nextposition>a){
		while(nextposition>a){
		nextposition=nextposition-n;
		}
	printf("%d,", adviser[nextposition]);
	}
	else
	{printf("%d,", adviser[nextposition]);}
//********** deleting array ***************	
	  for (int j=nextposition; j<a; j++) 
      	 {adviser[j] = adviser[j+1];}
    n = n - 1;
	nextposition+=interval;
}
}
