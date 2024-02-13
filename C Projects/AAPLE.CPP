#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){system("cls");
/*// number 1
int a,i;
printf("\n 1)");printf(" TERMS: 2,6,10,14,18...n = (An=A[n-1]+4)");
printf("\n Up to how many terms you want to solve?: ");
scanf("%d",&a);
int A[a]; A[0]=2; 
//number 1 formula
for(i=0;i<a;i++){
		if(i==0)
			printf("\n\tA[%d]= %d",i+1,A[i]);
		else {
			A[i]=A[i-1]+4;
			printf("\n\tA[%d]= %d",i+1,A[i]);}
				}
}*/
/*//number 2
system ("cls");int b,i;
printf("\n 2)");printf(" TERMS: 0,2,0,2,0...n = (An=A[n-2])");
printf("\n Up to how many terms you want to solve?: ");
scanf("%d",&b);
int B[b],z; B[0]=0; B[1]=2; 
//number 2 formula
for(i=0;i<b;i++){
		if(i==0)
			printf("\n\tA[%d]= %d",i+1,B[i]);
		else if(i==1)
			printf("\n\tA[%d]= %d",i+1,B[i]);
		else {
			z=i%2;
				if(z==1)
				printf("\n\tA[%d]= %d",i+1,B[1]);
				else
				printf("\n\tA[%d]= %d",i+1,B[0]);}
}*//*
//Number 3
system("cls");int c,i;
printf("\n 3)");printf(" TERMS: 2,6,12,20,30,42...n = (An=A[n-1]+2*n)");
printf("\n Up to how many terms you want to solve?: ");
scanf("%d",&c);c++;
int C[c]; C[1]=2;  
//number 3 formula
for(i=1;i<c;i++){
		if(i==1)
			printf("\n\tA[%d]= %d",i,C[i]);
		else {
				C[i]=C[i-1]+(2*i);
				printf("\n\tA[%d]= %d",i,C[i]);}}
*/

//number 4
int d,i;
printf("\n 4)");printf(" TERMS: 1,4,9,16,25,36,49,...n = (An=A[n-1]+2*N-1)");
printf("\n Up to how many terms you want to solve?: ");
scanf("%d",&d);d++;
int D[d]; D[1]=1;  
//number 4 formula
for(i=1;i<d;i++){
		if(i==1)
			printf("\n\tA[%d]= %d",i,D[i]);
		else {
			D[i]=D[i-1]+(2*i-1);
			printf("\n\tA[%d]= %d",i,D[i]);}}
}
