	#include<conio.h>
	#include<stdio.h>
	void main(){clrscr();
	int cur,last=5,walk,temp,i,located,false,true;
	int list[]={0,15,10,5,19};
	printf("\nbefore");
	for(i=0;i<=last;i++)
		printf("\n%d",list[i]);


	for(cur=1;cur<last;cur++)
	  {	located=0;
		temp=list[cur];
		walk=cur-1;
		while(walk>=0&&temp<list[walk]){
			 list[walk+1]=list[walk];
			 walk--;
			 located=1;
			 list[walk+1]=temp;
			 }

	  }
	printf("\nafter");
	for(i=0;i<last;i++)
		printf("\n%d",list[i]);
getch();
return;
}