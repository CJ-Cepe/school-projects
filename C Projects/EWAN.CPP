/*  GROUP 9                   Project program
    Carl Joseph Cepe          Oct 16,2018
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
//---------------------FUNCTION DECLARATION-----------------


//-----------------------MAIN FUNCTION----------------------------------
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
{
int sagot;
int list[2][12]={0};
int max1,max2;
textcolor(YELLOW);
gotoxy(37,3);
cprintf("MENU");
textcolor(CYAN);
gotoxy(13,5);
cprintf("'Choose one function by typing the corresponding number'");
textcolor(WHITE);
gotoxy(29,9);
cprintf("(1). CONVERSION");
gotoxy(29,11);
cprintf("(2). EXPONENT");
gotoxy(29,13);
cprintf("(3). RAILROAD");
gotoxy(29,15);
cprintf("(4). TELEPHONE");
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
//----------------INPUT------------------
void INPUT(int list[2][12])
{
  int i,j,temp;
	clrscr();
	printf("Input the scores of each player per team");
	for(i=0;i<2;i++){
		printf("\nTeam %d",i+1);
			for(j=0;j<12;j++)
			       {printf("\n\tplayer %d:",j+1);
				scanf("%d",&temp);
				list[i][j]=temp;
				       }
			 }
	printf("\nokay done inputing going back now to the menu");
	for(i=0;i<2;i++)
		for(j=0;j<12;j++)
			printf("\n\tplayer %d:",list[i][j]);
 getch();
 clrscr();
 FASTBORDER();
 MENU();
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
