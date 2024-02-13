/*  GROUP 15                   Project program
    Carl Joseph Cepe           January ,2019
    Emmanuel Tuazon
    BSCS 1-1
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
//------------------function declaration-------------------
void WIN(int list[][12]);
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
	INPUT(list);
	break;
case 2:
	MVP(list,max1,max2);
	break;
case 3:
	WIN(list);
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
 int sagot,player,number,score,c;
 char team;
 clrscr();
 FASTBORDER();
 textcolor(CYAN);
 gotoxy(37,3);
 cprintf("'SCOREBOARD'");
   //printing scoreboard
 textcolor(WHITE);
 gotoxy(10,5);
 cprintf("\nTeam A");
 for(player=0;player<12;player++)
	{ textcolor(GREEN);
		gotoxy(8,7+player);
		    cprintf("PLAYER %d = %d \n",player+1,list[0][player]); }

 textcolor(WHITE);
 gotoxy(30,5);
 cprintf("\nTeam B");
 for(player=0;player<12;player++)
	{ textcolor(YELLOW);
		gotoxy(28,7+player);
		    cprintf("PLAYER %d = %d \n",player+1,list[1][player]); }
  //inputting score
  do {
  textcolor(WHITE);
  gotoxy(49,8);
  cprintf("SELECT TEAM  [A or B]: ");
  scanf(" %c",&team);
	if ( team=='A'||team=='a'){
	   gotoxy(49,10);
	   cprintf("A-player number : ");
	   scanf("%d",&number);
	   if(number>=0&&number<=12){
		gotoxy(49,12);
		cprintf("Input score ");
		gotoxy(51,13);
		cprintf("Player %d: ",number);
		scanf("%d",&score);
		switch(score){
		case 1:
		   { list[0][number-1]+=1;
		    INPUT(list);
		    break;}
		case 2:
		   { list[0][number-1]+=2;
		    INPUT(list);
		    break; }
		case 3:
		   { list[0][number-1]+=3;
		    INPUT(list);
		    break; }
		default:{
			textcolor(RED);
			gotoxy(52,14);
			cprintf("INVALID TRY AGAIN");
			getch();
			INPUT(list);}
			}
			}
		else    {
			textcolor(RED);
			gotoxy(52,14);
			cprintf("INVALID TRY AGAIN");
			getch();
			INPUT(list); }
			}
	else if ( team=='B'||team=='b'){
	   gotoxy(49,10);
	   cprintf("B-player number: ");
	   scanf("%d",&number);
	   if(number>=0&&number<=12){
		gotoxy(49,12);
		cprintf("Input score ");
		gotoxy(51,13);
		cprintf("Player %d: ",number);
		scanf("%d",&score);
		switch(score){
		case 1:
		    {list[1][number-1]+=1;
		    INPUT(list);
		    break; }
		case 2:
		    {list[1][number-1]+=2;
		    INPUT(list);
		    break; }
		case 3:
		   { list[1][number-1]+=3;
		    INPUT(list);
		    break; }
		default:{
			textcolor(RED);
			gotoxy(52,14);
			cprintf("INVALID TRY AGAIN");
			getch();
			INPUT(list);}
			}
			}
		else    {
			textcolor(RED);
			gotoxy(52,14);
			cprintf("INVALID TRY AGAIN");
			getch();
			INPUT(list);}
			}
	else if ( team=='E'||team=='e'){
		c==2;}
	else{
			textcolor(RED);
			gotoxy(52,14);
			cprintf("INVALID TRY AGAIN");
			getch();
			INPUT(list);
			}
} while(c==1);
  clrscr();
}
//----------MVP IN EVERY TEAM--------------
void MVP(int list[2][12],int max1,int max2)
{clrscr();
FASTBORDER();
int player,team;

max1=list[0][0];
	for(player=1;player<12;player++)
		if(max1<list[0][player])
			max1=list[0][player];
textcolor(WHITE);
gotoxy(38,4);
cprintf("MVP");
gotoxy(36,5);
cprintf("per team");

textcolor(GREEN);
gotoxy(23,7);
cprintf("TEAM - 1\n");
	for(player=0;player<12;player++)
		if(list[0][player]==max1)
		     { textcolor(WHITE);
		      gotoxy(18,9+player);
		      cprintf("PLAYER %d = %d POINTS\n",player+1,max1); }

max2=list[1][0];
	for(player=1;player<12;player++)
		if(max2<list[1][player])
			max2=list[1][player];
printf("\n");
textcolor(YELLOW);
gotoxy(48,7);
cprintf("TEAM - 2\n");
	for(player=0;player<12;player++)
		if(list[1][player]==max2)
			{ textcolor(WHITE);
			  gotoxy(43,9+player);
			  cprintf("PLAYER %d = %d POINTS\n",player+1,max2); }
getch();
clrscr();
FASTBORDER();
}
//----------HIGHEST POINT------------------
void HIGH(int list[][12])
{clrscr();
FASTBORDER();
int player,team,max;
max=list[0][0];
for(team=0;team<2;team++)
	for(player=0;player<12;player++)
		if(max<list[team][player])
			max=list[team][player];

textcolor(YELLOW);
gotoxy(33,5);
cprintf("HIGHEST POINT=%d\n",max);
for(team=0;team<2;team++){
	for(player=0;player<12;player++){
		if(list[team][player]==max){
			textcolor(WHITE);
			gotoxy(28,7+player);
			cprintf("team %d player number %d",team+1,player+1);
		      }
		}
}
getch();
clrscr();
}


//----------WINNING TEAM-------------------
void WIN(int list[][12])
{clrscr();
FASTBORDER();
int add1=0,add2=0,player;

for(player=0;player<12;player++)
	add1=add1+list[0][player];
for(player=0;player<12;player++)
	add2=add2+list[1][player];

printf("\n");
textcolor(YELLOW);
gotoxy(37,5);
cprintf("RESULT");
	if(add1>add2)
	       {textcolor(WHITE);
		gotoxy(32,10);
		printf("the Winner is Team A");}
	else if(add1<add2)
	       {textcolor(WHITE);
		gotoxy(32,10);
		printf("the Winner is Team B");}
	else
		{textcolor(WHITE);
		gotoxy(34,10);
		printf("it is a TIE"); }
getch();
clrscr();
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
//----------------EXIT FUNCTION-----------
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
cprintf("Computer Programming ");
gotoxy(45,4);
cprintf("Project");
}