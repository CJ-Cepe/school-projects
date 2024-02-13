#include<conio.h>
#include<stdio.h>
void main(){clrscr();
int player,team,max1,max2;
int list[2][10]={
	{22,33,5,5,10,9,7,98,9,100},
	{55,7,54,33,22,11,99,8,100,5}};


max1=list[0][0];
	for(player=0;player<10;player++)
		if(max1<list[0][player])
			max1=list[0][player];
printf("team 1\n");
	for(player=0;player<10;player++)
		if(list[0][player]==max1)
			printf("THE MVP IS PLAYER NUMBER %d = %d POINTS\n",player+1,max1);

max2=list[0][0];
	for(player=0;player<10;player++)
		if(max2<list[1][player])
			max2=list[1][player];
printf("team 2\n");
	for(player=0;player<10;player++)
		if(list[1][player]==max2)
			printf("THE MVP IS PLAYER NUMBER %d = %d POINTS\n",player+1,max2);
//COMPARING
printf("\n");
	if(max1>max2)
		printf("the winner is team 1");
	else if(max1<max2)
		printf("the winner is team 2");
	else
		printf("it is a tie");
getch();
}