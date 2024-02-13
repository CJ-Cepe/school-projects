// MACHINE PROBLEM : PROBABILITY (2) Coin Flip
// Cepe, Carl Joseph R.    BSCS 2-1		Discrete Structures 2         
// 10/4/2019 	



#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<windows.h>
//#define RAND_MAX 1
int main(){
	
	char Ans='Y';
while(toupper(Ans)=='Y'){
	system("cls");
		int N=0,heads=0,tails=0,cnt=1;
       	int holder=0;
	    double bias=0;
        double numb;/////
        printf("\n\t\t\t\t --Coin Flip--");
        printf("\n\n\tInput the number of times the coin will be tossed: ");
        scanf("%d",&N);
        printf("\n\n\tHow biased will be if it is heads(0-100):");
        scanf("%d",&holder);
        bias=(double)holder/100;
        printf("\n\t\t number     random #      result\n");
		while(N>0)
        {
		
		numb=((double) rand()/(RAND_MAX));
            printf("\t\t   %d\t     %.02lf\t",cnt,numb);//cnt+"\t"+numb);
            
            if(numb < bias)
		{
		    heads++;
		    printf("  Heads");
		}
            else
		{
		    tails++;
		    printf("  Tails");
		}
            N--;  
            cnt++;
			printf("\n");		   
    }
    
   printf("\n\t\t\tNumber of Heads=%d",heads);
    printf("\n\t\t\tNumber of Tails=%d",tails);
    
    printf("\n\n\n\n\t\t\t\tAgain(y/n): ");
	scanf(" %c",&Ans);
}
}
