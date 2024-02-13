#include<stdio.h>
#include<conio.h>
void main(){clrscr();
int A[]={9,5,8,2,4};
int i,n=5;
printf("Unsorted\n");
for(i=0;i<n;i++)
	printf("%d,",A[i]);
/*
//SELECTION SORT
int pos,temp,c,d;
for(c=0;c<(n-1);c++){
	pos=c;
	for(d=c+1;d<n;d++){
		if(A[pos]>A[d])
			pos=d;
		}
	if(pos!=c){
	temp=A[c];
	A[c]=A[pos];
	A[pos]=temp;
	}
}
*/
/*
//BUBBLE SORT
int temp,c,d;
for(c=0;c<n;c++){
	for(d=0;d<n-c-1;d++)
	{
	 if(A[d]>A[d+1]){
		temp=A[d];
		A[d]=A[d+1];
		A[d+1]=temp;}
		}
	 }
*/
/*
//INSERTION SORT
int temp,c,d;
for(c=1;c<n;c++){
	d=c;
		while(d>0&&A[d-1]>A[d]){
			temp=A[d];
			A[d]=A[d-1];
			A[d-1]=temp;
		d--;
	  }
}
printf("\nsorted\n");
for(i=0;i<n;i++)
	printf("%d,",A[i]);
*/


getch();
}