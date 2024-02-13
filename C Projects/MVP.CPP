#include<conio.h>
#include<stdio.h>
void main(){clrscr();
int player,team,max;
int list[2][10]={
	{22,33,11,5,10,9,7,99,9,5},
	{55,7,54,33,22,11,99,8,99,5}};


max=list[0][0];
for(team=0;team<2;team++)
	for(player=0;player<10;player++)
		if(max<list[team][player])
			max=list[team][player];


printf("HIGHEST POINT=%d\n",max);
for(team=0;team<2;team++){
	for(player=0;player<10;player++){
		if(list[team][player]==max){
			printf("team %d player number %d\n	",team+1,player+1);
		}
	}
}

getch();
}






