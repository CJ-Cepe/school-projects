#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void INPUT();
void OUTPUT();
void main();
static void force_fpf()
	  {
	      float x, *y;
	      y = &x;
	      x = *y;
	  }

typedef struct
	{
		int hour,minute;
		char shift[3];
	}TIME;
typedef struct
	{
		int TOTALH,TOTALM,Month,Day,Year;
		char Comp[20],ID[20],Fname[15],Lname[15],Minitial[15],Section[15];
		TIME Time_in,Time_out;
		float TOTALB,TOTAL;

	}INFO;


INFO A[30];
int i=0,n=0,price=15,j,u=0;
float PRICEM,minprice;

void COMPUTATION()
{            for (i=0;i<n;i++)
{
A[i].TOTALH=0;
A[i].TOTALM=0;
A[0].TOTAL=0;
	if (strcmp(A[i].Time_in.shift,A[i].Time_out.shift)==0)
		{
		if(A[i].Time_in.hour>A[i].Time_out.hour){
			A[i].TOTALH=12-A[i].Time_in.hour;
			A[i].TOTALH+=12;
			A[i].TOTALH+=A[i].Time_out.hour;}
		else if(A[i].Time_in.hour==A[i].Time_out.hour){
			A[i].TOTALH=24;}

		else
	       {A[i].TOTALH=A[i].Time_out.hour-A[i].Time_in.hour;}
		A[i].TOTALH--;

		if(A[i].Time_in.minute!=0){
			A[i].TOTALM=60-A[i].Time_in.minute;}
		else{
		A[i].TOTALH++;}
		A[i].TOTALM+=A[i].Time_out.minute;
		if(A[i].TOTALM==60){
			A[i].TOTALM=0;
			A[i].TOTALH++;
			}
		else if(A[i].TOTALM>60){
			A[i].TOTALM=A[i].TOTALM-60;
			A[i].TOTALH++;}
			   }


	else    {
		A[i].TOTALH=12-A[i].Time_in.hour;
		A[i].TOTALH+=A[i].Time_out.hour;
		A[i].TOTALH-=1;
		if(A[i].Time_in.minute!=0){
			A[i].TOTALM=60-A[i].Time_in.minute;}
		else    {
			A[i].TOTALH++;}
		A[i].TOTALM+=A[i].Time_out.minute;

		if(A[i].TOTALM==60){
			A[i].TOTALM=0;
			A[i].TOTALH++;}

		else if(A[i].TOTALM>60){
			A[i].TOTALM=A[i].TOTALM-60;
			A[i].TOTALH++;}
			}

minprice=price/60.0f;
A[i].TOTALB=A[i].TOTALH*price;
PRICEM=minprice*A[i].TOTALM;
A[i].TOTALB+=PRICEM;

  }
  for(i=0;i<n;i++)
	A[0].TOTAL+=A[i].TOTALB;
}
void INPUT1(){clrscr();
	textcolor(11);
	gotoxy(2,2);
	cprintf("STUDENT ID:");
	gets(A[0].ID);
	gotoxy(2,4);
	printf(" 	      First Name      MI     Surname");
	gotoxy(2,3);
	textcolor(15);
	cprintf("Student Name:  ");
	gets(A[0].Fname);
	gotoxy(31,3);
	gets(A[0].Minitial);
	gotoxy(40,3);
	gets(A[0].Lname);
	gotoxy(2,5);
	textcolor(WHITE);
	cprintf("Class/Yr/Section: ");
	gets(A[0].Section);
	gotoxy(1,6);
	textcolor(GREEN);
	cprintf("----------------------------------------------");
	gotoxy(1,7);
	printf("set %d",++u);
	INPUT();
}
void INPUT2(){
	textcolor(11);
	gotoxy(2,2);
	cprintf("STUDENT ID: %s",A[0].ID);
	gotoxy(2,4);
	printf(" 	      First Name      MI     Surname");
	gotoxy(2,3);
	textcolor(15);
	cprintf("Student Name:   %s          %s       %s",A[0].Fname,A[0].Minitial,A[0].Lname);
	gotoxy(2,5);
	textcolor(WHITE);
	cprintf("Class/Yr/Section: %s",A[0].Section);
	gotoxy(1,6);
	textcolor(GREEN);
	cprintf("----------------------------------------------");
	gotoxy(1,7);
	textcolor(LIGHTGRAY);
	cprintf("set %d",++u);
	INPUT();
}
void INPUT(){
char ans;
int p=0,k=0,o;
do
{
	if(p==2)
	       {clrscr(); INPUT2(); u++;}
	textcolor(CYAN);
	gotoxy(2,8+k);
	cprintf("Computer Code: ");
	gets(A[i].Comp);
	if(i!=0)
		gets(A[i].Comp);
	gotoxy(2,9+k);
	textcolor(15);
	cprintf("Time in:");
	gotoxy(3,10+k);
	printf("Hour  :");
	scanf("%d",&A[i].Time_in.hour);
	gotoxy(3,11+k);
	printf("Minute:");
	scanf("%d",&A[i].Time_in.minute);
	gotoxy(3,12+k);
	printf("Shift :");
	scanf("%s",A[i].Time_in.shift);
	gotoxy(14,9+k);
	cprintf("Time out:");
	gotoxy(15,10+k);
	printf("Hour  :");
	scanf("%d",&A[i].Time_out.hour);
	gotoxy(15,11+k);
	printf("Minute:");
	scanf("%d",&A[i].Time_out.minute);
	gotoxy(15,12+k);
	printf("Shift :");
	scanf("%s",A[i].Time_out.shift);
	gotoxy(26,9+k);
	cprintf("Date:  ");
	gotoxy(27,10+k);
	printf("Month(1-12):");
	scanf("%d",&A[i].Month);
	gotoxy(27,11+k);
	printf("Day(1-30)  :");
	scanf("%d",&A[i].Day);
	gotoxy(27,12+k);
	printf("Year       :");
	scanf("%d",&A[i].Year);
	n++; i++; p++;
	gotoxy(1,14+k);
	textcolor(GREEN);
	cprintf("--------------------------------------------");
	textcolor(CYAN);
	gotoxy(2,13+k);
	o=k;
	cprintf("Input another record?(y/n): ");
	scanf("%c",&ans);
	scanf("%c",&ans);
	k+=7;
	COMPUTATION();
}while( ans=='y'|| ans=='Y');
	gotoxy(1,14+o);
	textcolor(YELLOW);
	cprintf("--------------------------------------------");
	gotoxy(2,14+o);
printf("\nYour bill for computer usage: %.02f",A[0].TOTAL);
OUTPUT();
}

void OUTPUT(){

gotoxy(51,6);
textcolor(LIGHTCYAN);
cprintf(" Summary of Computer Usage");
gotoxy(45,7);
textcolor(3);
cprintf("    Date        Duration      Amount");


for(i=0;i<n;i++)
       {gotoxy(45,8+i);
	textcolor(WHITE);
	cprintf("  %d/ %d/ %d        %d:%d       %.02f  ", A[i].Month,A[i].Day,A[i].Year,A[i].TOTALH,A[i].TOTALM,A[i].TOTALB);}
gotoxy(59,10+i);
printf("TOTAL %.02f",A[0].TOTAL);
getch();
exit(0);
}

void main(){clrscr();
INPUT1();
getch();
}