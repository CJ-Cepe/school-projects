#include<conio.h>
#include<stdio.h>
#include<string.h>
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
		char ID[20],Fname[15],Lname[15],Minitial[15],Section[15];
		TIME Time_in,Time_out;
		float TOTALB,TOTAL;

	}INFO;


INFO A[30];
int i=0,n=0,price=15;
float PRICEM,minprice;
void COMPUTATION()
{            for (i=0;i<n;i++)
{
A[i].TOTALH=0;
A[i].TOTALM=0;
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
A[0].TOTAL+=A[i].TOTALB;

  }
}
void INPUT(){clrscr();
char ans;
	printf("STUDENT ID:");
	gets(A[0].ID);
	printf("\nStudent Name");
	printf("\n\tfirst name:");
	gets(A[0].Fname);
	printf("\n\tmiddle initial:");
	gets(A[0].Minitial);
	printf("\n\tlast name:");
	gets(A[0].Lname);
	printf("\n class/yr/section: ");
	gets(A[0].Section);
	printf("------------------------");
do
{
	printf("\n Time in");
	printf("\n\thour:");
	scanf("%d", &A[i].Time_in.hour);
	printf("\n\tminute:");
	scanf("%d",&A[i].Time_in.minute);
	printf("\n\tshift(am/pm):");
	scanf("%s",A[i].Time_in.shift);
	printf("\n Time out");
	printf("\n\thour:");
	scanf("%d",&A[i].Time_out.hour);
	printf("\n\tminute:");
	scanf("%d",&A[i].Time_out.minute);
	printf("\n\tshift(am/pm):");
	scanf("%s",A[i].Time_out.shift);
	printf("\ndate");
	printf("\n\tMonth(1-12): ");
	scanf("%d",&A[i].Month);
	printf("\n\tDay(1-30): ");
	scanf("%d",&A[i].Day);
	printf("\n\tYear: ");
	scanf("%d",&A[i].Year);
	printf("\nInput another record?(y/n): ");
	scanf("%c",&ans);
	scanf("%c",&ans);
	n++;
	i++;
	printf("\n-----------------");
}while( ans=='y'|| ans=='Y');

COMPUTATION();
printf("\nYour bill for computer usage: %.02f\n",A[0].TOTAL);
}

void OUTPUT(){

printf("\nSummary of Computer Usage");
printf("\n   Date          Duration           Amount");
for(i=0;i<n;i++)
	printf("\n %d %d  %d     %d: %d               %.02f  ", A[i].Month,A[i].Day,A[i].Year,A[i].TOTALH,A[i].TOTALM,A[i].TOTALB);
printf("\n TOTAL %.02f",A[0].TOTAL);
}

void main(){clrscr();
INPUT();
OUTPUT();
getch();
}