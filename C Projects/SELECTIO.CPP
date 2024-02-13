//Cepe,Carl Joseph R.            Selection sort
//Emmanuel Tuazon                Group
//BSCS 1-1                       computer programming

#include<stdio.h>
#include<conio.h>
//function decl////////////
void swapping(int *curr, int *smlst);
//main function///////////
int main()
{clrscr();
int curr,last=5,smlst,i,walk;
int list[]={44,33,22,11,22};

//print before sorting//
for(i=0;i<last;i++)
	printf("%d\n",list[i]);
/////sorting/////////////////
for(curr=0;curr<last;curr++)
   {	smlst=curr;
	for(walk=curr+1;walk<last;walk++)
		if(list[walk]<list[smlst])
			smlst=walk;
	swapping(&list[curr], &list[smlst]);
   }
//print after sorting//
for(i=0;i<last;i++)
	printf("\n%d",list[i]);
getch();
return 0;
}

//swap function//////////////////////////////////
void swapping(int *curr, int *smlst)
{
int temp;
temp = *curr;
*curr = *smlst;
*smlst = temp;
}



