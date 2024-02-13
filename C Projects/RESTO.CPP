//CARL JOSEPH R. CEPE         COMPUTER PROGRAMMING     STRUCTURES-RESTAURANT
//BSCS1-1                     2/24/2019
#include<conio.h>
#include<stdio.h>
#include<string.h>
typedef struct
{
	int hour,minute;
	char shift[3];
}TIME;

typedef struct
{
	char building[20],city[20],street[20];
}ADDRESS;

typedef struct
{
	char Name[30],Specialty[40];
	TIME OpeningT,ClosingT;
	ADDRESS Building;
	int TOTALH,TOTALM;
}RESTAURANT;
RESTAURANT A[30];
char SAGOT;
int n=3,i;


void COMPUTATION()
{
for (i=0;i<n;i++)
{
A[i].TOTALH=0;
A[i].TOTALM=0;
	if (strcmp(A[i].OpeningT.shift,A[i].ClosingT.shift)==0)
		{
		if(A[i].OpeningT.hour>A[i].ClosingT.hour){
			A[i].TOTALH=12-A[i].OpeningT.hour;
			A[i].TOTALH+=12;
			A[i].TOTALH+=A[i].ClosingT.hour;}
		else if(A[i].OpeningT.hour==A[i].ClosingT.hour){
			A[i].TOTALH=24;}

		else
		A[i].TOTALH=A[i].ClosingT.hour-A[i].OpeningT.hour;
		A[i].TOTALH--;

		if(A[i].OpeningT.minute!=0){
			A[i].TOTALM=60-A[i].OpeningT.minute;}
		else{
			A[i].TOTALH++;}
		A[i].TOTALM+=A[i].ClosingT.minute;
		if(A[i].TOTALM==60){
			A[i].TOTALM=0;
			A[i].TOTALH++;
			}
		else if(A[i].TOTALM>60){
			A[i].TOTALM=A[i].TOTALM-60;
			A[i].TOTALH++;}
			   }


	else    {
		A[i].TOTALH=12-A[i].OpeningT.hour;
		A[i].TOTALH+=A[i].ClosingT.hour;
		A[i].TOTALH-=1;
		if(A[i].OpeningT.minute!=0){
			A[i].TOTALM=60-A[i].OpeningT.minute;}
		else    {
			A[i].TOTALH++;}
		A[i].TOTALM+=A[i].ClosingT.minute;

		if(A[i].TOTALM==60){
			A[i].TOTALM=0;
			A[i].TOTALH++;}

		else if(A[i].TOTALM>60){
			A[i].TOTALM=A[i].TOTALM-60;
			A[i].TOTALH++;}
			}  }
}

void INPUT()
{clrscr();
int k=0;
textcolor(WHITE);
gotoxy(31,2);
cprintf("INPUT INFORMATION");
for(i=0;i<n;i++){
	gotoxy(6+k+i,4);
	textcolor(YELLOW);
	cprintf("RESTAURANT [%d]",i+1);
	gotoxy(3+k+i,5);
	textcolor(GREEN);
	cprintf("NAME: ");
	gets(A[i].Name);
	gotoxy(3+k+i,6);
	cprintf("ADDRESS");
	gotoxy(5+k+i,7);
	printf("BLDG: ");
	gets(A[i].Building.building);
	gotoxy(5+k+i,8);
	printf("STREET: ");
	gets(A[i].Building.street);
	gotoxy(5+k+i,9);
	printf("CITY: ");
	gets(A[i].Building.city);
	gotoxy(3+k+i,10);
	cprintf("OPENING TIME");
	textcolor(WHITE);
       do{gotoxy(5+k+i,11);
	cprintf("HOUR(1-12): ");
	scanf("%d",&A[i].OpeningT.hour);
	textcolor(RED);
	}while(A[i].OpeningT.hour>12);
	textcolor(WHITE);
       do{gotoxy(5+k+i,12);
	cprintf("MINUTE(1-59): ");
	scanf("%d",&A[i].OpeningT.minute);
	textcolor(RED);
	}while(A[i].OpeningT.minute>59);
	gotoxy(5+k+i,13);
	printf("SHIFT(AM/PM): ");
	scanf(" %s",A[i].OpeningT.shift);
	gotoxy(3+k+i,14);
	textcolor(GREEN);
	cprintf("CLOSING TIME");
	textcolor(WHITE);
       do{gotoxy(5+k+i,15);
	cprintf("HOUR(1-12): ");
	scanf("%d",&A[i].ClosingT.hour);
	textcolor(RED);
	}while(A[i].ClosingT.hour>12);
	textcolor(WHITE);
       do{gotoxy(5+k+i,16);
	cprintf("MINUTE(1-59): ");
	scanf("%d",&A[i].ClosingT.minute);
	textcolor(RED);
	}while(A[i].ClosingT.minute>59);
	gotoxy(5+k+i,17);
	printf("SHIFT(AM/PM): ");
	scanf(" %s",A[i].ClosingT.shift);
	gotoxy(3+k+i,18);
	textcolor(GREEN);
	cprintf("SPECIALTY: ");
	gets(A[i].Specialty);
	gets(A[i].Specialty);
	k*=i;
	k+=26;

}
}
void PRINT()
{clrscr();
int k=0;
textcolor(WHITE);
gotoxy(31,2);
cprintf("OUTPUT INFORMATION");
for (i=0;i<n;i++)
{ if(i<2){
 gotoxy(7,3+k);
 textcolor(YELLOW);
 cprintf("RESTAURANT [%d]",i+1);
 gotoxy(5,4+k);
 textcolor(GREEN);
 cprintf("NAME: %s",A[i].Name);
 gotoxy(5,5+k);
 cprintf("ADDRESS");
 gotoxy(6,6+k);
 textcolor(WHITE);
 cprintf("building: %s",A[i].Building.building);
 gotoxy(6,7+k);
 cprintf("street: %s",A[i].Building.street);
 gotoxy(6,8+k);
 cprintf("city: %s",A[i].Building.city);
 gotoxy(5,9+k);
 textcolor(GREEN);
 cprintf("OPENING TIME: %d/%d/%s",A[i].OpeningT.hour,A[i].OpeningT.minute,A[i].OpeningT.shift);
 gotoxy(5,10+k);
 cprintf("CLOSING TIME: %d/%d/%s",A[i].ClosingT.hour,A[i].ClosingT.minute,A[i].ClosingT.shift);
 gotoxy(5,11+k);
 cprintf("SPECIALTY: %s",A[i].Specialty);
 gotoxy(5,12+k);
 textcolor(MAGENTA);
 cprintf("TOTAL WORKING TIME:hr=%d:min=%02d",A[i].TOTALH,A[i].TOTALM);
 k+=12;}
 else
 { gotoxy(47,3);
 textcolor(YELLOW);
 cprintf("RESTAURANT [%d]",i+1);
 gotoxy(45,4);
 textcolor(GREEN);
 cprintf("NAME: %s",A[i].Name);
 gotoxy(45,5);
 cprintf("ADDRESS");
 gotoxy(46,6);
 textcolor(WHITE);
 cprintf("building: %s",A[i].Building.building);
 gotoxy(46,7);
 cprintf("street: %s",A[i].Building.street);
 gotoxy(46,8);
 cprintf("city: %s",A[i].Building.city);
 gotoxy(45,9);
 textcolor(GREEN);
 cprintf("OPENING TIME: %d/%d/%s",A[i].OpeningT.hour,A[i].OpeningT.minute,A[i].OpeningT.shift);
 gotoxy(45,10);
 cprintf("CLOSING TIME: %d/%d/%s",A[i].ClosingT.hour,A[i].ClosingT.minute,A[i].ClosingT.shift);
 gotoxy(45,11);
 cprintf("SPECIALTY: %s",A[i].Specialty);
 gotoxy(45,12);
 textcolor(MAGENTA);
 cprintf("TOTAL WORKING TIME:hr=%d:min=%02d",A[i].TOTALH,A[i].TOTALM);
}
}
}
void main(){clrscr();
printf("\n\n\t\tINPUT INFORMATION ABOUT 3 RESTAURANT");
textcolor(WHITE);
INPUT();
COMPUTATION();
textcolor(WHITE);
PRINT();
getch();
getch();
}
