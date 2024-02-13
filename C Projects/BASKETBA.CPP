/*  GROUP 15                   Project program
    Carl Joseph Cepe          January ,2019
    Emmanuel Tuazon
    BSCS 1-1
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#include<string.h>
//------------------function declaration-------------------
void WIN(int max1, int max2);
void BORDER();
void FASTBORDER();
void INPUT(int list[2][12]);
void MENU();
void EXIT();
void MVP(int list[2][12],int max1,int max2);
void HIGH(int list[2][12]);
//------------------main function--------------------------
int main()
{
clrscr();
BORDER();
MENU();
getch();
return 0;
}
//---------------------MENU FUNCTION-----------------------------------
//This is the function for the main menu with diferent other function choices
void MENU()
{clrscr();
FASTBORDER();
int sagot;
int list[2][12]={0};
int max1,max2;
while(sagot!=5){
textcolor(YELLOW);
gotoxy(37,3);
cprintf("MENU");
textcolor(CYAN);
gotoxy(13,5);
cprintf("'Choose one function by typing the corresponding number'");
textcolor(WHITE);
gotoxy(29,9);
cprintf("(1). INPUT SCORES");
gotoxy(29,11);
cprintf("(2). MVP IN EVERY TEAM");
gotoxy(29,13);
cprintf("(3). WINNING TEAM");
gotoxy(29,15);
cprintf("(4). HIGHEST POINTER");
gotoxy(29,17);
cprintf("(5). EXIT");
gotoxy(29,20);
cprintf("Choose one: ");
	scanf("%d",&sagot);

switch(sagot){
case 1:
	clrscr();
	FASTBORDER();
	INPUT(list);
	break;
case 2:
	MVP(list,max1,max2);
	break;
case 3:
	WIN( max1, max2);
	break;

case 	4:
	HIGH(list);
	break;
case 5:
	clrscr();
	EXIT();
	break;
default:
	textcolor(RED);
	gotoxy(25,20);
	cprintf("Invalid number try again");
	getch();
	clrscr();
	FASTBORDER();
	MENU();
}
}
}
//------------INPUT SCORES-----------------
void INPUT(int list[2][12])
{
 int sagot;

 textcolor(CYAN);
 gotoxy(23,5);
 cprintf("'Do you want to input scores?'");
 textcolor(WHITE);
 gotoxy(29,9);
 cprintf("    (1).       YES");
 gotoxy(29,11);
 cprintf("(any number).  NO");
 gotoxy(29,20);
 cprintf("Choose one: ");
	scanf("%d",&sagot);

 switch(sagot){
 case 1:{
	do
	{
	int i,j,temp1,temp2;
	clrscr();
	FASTBORDER();
	textcolor(WHITE);
	gotoxy(21,5);
	cprintf("Input the scores of each player per team");
		textcolor(GREEN);
		gotoxy(20,7);
		cprintf("\nTeam A");
			for(j=0;j<12;j++)
			       {gotoxy(22,9+j);
				cprintf("\n\tplayer %d:",j+1);
				scanf("%d",&temp1);
				list[0][j]=temp1;
				       }

		textcolor(YELLOW);
		gotoxy(39,7);
		cprintf("\nTeam B");
			for(j=0;j<12;j++)
			       {gotoxy(41,9+j);
				cprintf("\n\tplayer %d:",j+1);
				scanf("%d",&temp2);
				list[1][j]=temp2;
				       }
	gotoxy(25,24);
	printf("Input Score again?(y/n)");
	scanf(" %c",&sagot);
    }while (sagot=='y'||sagot=='Y');
	    clrscr();
    }
 default:
	return;
}


 getchar();

}
//----------MVP IN EVERY TEAM--------------
void MVP(int list[2][12],int max1,int max2)
{clrscr();
int player,team;

max1=list[0][0];
	for(player=1;player<12;player++)
		if(max1<list[0][player])
			max1=list[0][player];
printf("team 1\n");
	for(player=0;player<12;player++)
		if(list[0][player]==max1)
			printf("THE MVP IS PLAYER NUMBER %d = %d POINTS\n",player+1,max1);

max2=list[1][0];
	for(player=1;player<12;player++)
		if(max2<list[1][player])
			max2=list[1][player];
printf("team 2\n");
	for(player=0;player<12;player++)
		if(list[1][player]==max2)
			printf("THE MVP IS PLAYER NUMBER %d = %d POINTS\n",player+1,max2);
getch();
}
//----------HIGHEST POINT------------------
void HIGH(int list[][12])
{clrscr();
int player,team,max;
max=list[0][0];
for(team=0;team<2;team++)
	for(player=0;player<10;player++)
		if(max<list[team][player])
			max=list[team][player];


printf("HIGHEST POINT=%d\n",max);
for(team=0;team<2;team++){
	for(player=0;player<10;player++){
		if(list[team][player]==max){
			printf("team %d player number %d\n",team+1,player+1);
		}
	}
}

getch();
}

//----------WINNING TEAM-------------------
void WIN(int max1, int max2)
{clrscr();

printf("\n");
	if(max1>max2)
		printf("the winner is team A");
	else if(max1<max2)
		printf("the winner is team B");
	else
		printf("it is a tie");
getch();
}


//-----------------------BORDER FUNCTION--------------------------------
//        This function will create the border with delay
void BORDER()
{
int a,b,c,d,e,f,g;
 gotoxy(1,1);
	for(a=1;a<=79;a++)
	{
		textcolor(GREEN);
		cprintf("%c",219);
		delay(20);
	}
 gotoxy(1,1);
	for(a=1;a<=24;a++)
	{
		textcolor(GREEN);
		cprintf("%c",219);
		printf("\n");
		delay(20);
	}
	for(c=1;c<=79;c++)
	{
		textcolor(GREEN);
		cprintf("%c",219);
		delay(20);
	}
	for(d=1;d<=24;d++)
	{
		textcolor(GREEN);
		gotoxy(79,d);
		cprintf("%c",219);
		delay(20);
	}

}
//----------------------FAST BORDER FUNCTION---------------------------
//        This function will create the border without delay
void FASTBORDER()
{
int a,b,c,d,e,f,g;
 gotoxy(1,1);
	for(a=1;a<=79;a++)
	{
		textcolor(GREEN);
		cprintf("%c",219);
		delay(0);
	}
 gotoxy(1,1);
	for(a=1;a<=24;a++)
	{
		textcolor(GREEN);
		cprintf("%c",219);
		printf("\n");
		delay(0);
	}
	for(c=1;c<=79;c++)
	{
		textcolor(GREEN);
		cprintf("%c",219);
		delay(0);
	}
	for(d=1;d<=24;d++)
	{
		textcolor(GREEN);
		gotoxy(79,d);
		cprintf("%c",219);
		delay(0);
	}
 }
/*
//---------------------MENU FUNCTION-----------------------------------
//This is the function for the main menu with diferent other function choices
void MENU()
{
int sagot;
textcolor(YELLOW);
gotoxy(37,3);
cprintf("MENU");
textcolor(CYAN);
gotoxy(13,5);
cprintf("'Choose one function by typing the corresponding number'");
textcolor(WHITE);
gotoxy(29,9);
cprintf("(1). INPUT SCORES");
gotoxy(29,11);
cprintf("(2). MVP IN EVERY TEAM");
gotoxy(29,13);
cprintf("(3). WINNING TEAM");
gotoxy(29,15);
cprintf("(4). HIGHEST POINTER");
gotoxy(29,17);
cprintf("(5). EXIT");
gotoxy(29,20);
cprintf("Choose one: ");
scanf("%d",&sagot);

switch(sagot){
case 1:
	CONVERSION();
	break;
case 2:
	EXPONENT();
	break;
case 3:
	RAILROAD();
	break;
case 4:
	TELEPHONE();
	break;
case 5:
	clrscr();
	EXIT();
	break;
default:
	textcolor(RED);
	gotoxy(25,20);
	cprintf("Invalid number try again");
	getch();
	clrscr();
	FASTBORDER();
	MENU();

}
}
//------------INPUT SCORES-----------------
void input()
{
	printf("Input the scores of each player per team");


//----------MVP IN EVERY TEAM--------------
/*
//----------HIGHEST POINT------------------
void main(){clrscr();
int player,team,max;
int list[2][10]={
	{22,33,11,5,10,9,7,100,9,5},
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
		//----------WINNING TEAM-------------------
*/
void EXIT()
{
clrscr();
FASTBORDER();
textcolor(YELLOW);
gotoxy(30,12);
cprintf(" >>> BYE BYE <<< ");
textcolor(WHITE);
gotoxy(10,3);
cprintf("BSCS 1-1");
gotoxy(10,4);
cprintf("Emmanuel Tuazon");
gotoxy(10,5);
cprintf("Carl Joseph Cepe");
gotoxy(45,3);
cprintf("Computer Programming 1");
gotoxy(45,4);
cprintf("Project");
}