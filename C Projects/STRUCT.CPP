//Carl Joseph R. Cepe
//BSCS 1-1
//GROUP 15
//Structures
//Feb 14,2019
#include<stdio.h>
#include<conio.h>
struct INFO
{
	int ID,Day,Month,Year;
	char fName[20],mInitial[5],lName[20];
} st1;
struct SUB
{
	char Course[20];
	int Credit,tCredit;
	float Grade,tGrade,Average,ttotal,serve;

} st2[20],total;
static void force_fpf()
	  {
	      float x, *y;
	      y = &x;
	      x = *y;
	  }
int main(){clrscr();
int i,n;
total.tCredit=0;
total.tGrade=0;
total.ttotal=0;
printf("Enter number of courses to input: ");
scanf("%d",&n);


printf("\n Student ID: ");
scanf("%d",&st1.ID);
gotoxy(5,4);
cprintf("\n           First Name     MI     Last Name");
gotoxy(5,3);
printf("\n Student Name:  ");
scanf("%s",&st1.fName);
gotoxy(31,4);
scanf("%s",&st1.mInitial);
gotoxy(40,4);
scanf("%s",&st1.lName);
gotoxy(5,6);
printf("\n\               Month          Day     Year");
gotoxy(5,5);
printf("\n Birthdate:     ");
scanf("%d",&st1.Month);
gotoxy(31,6);
scanf("%d",&st1.Day);
gotoxy(40,6);
scanf("%d",&st1.Year);
int j=0;
for(i=0;i<n;i++)
{
gotoxy(1,9+j);
printf(" Course Number: ");
scanf(" %s", &st2[i].Course);
gotoxy(0,10+j);
printf(" Credit       : ");
scanf(" %d", &st2[i].Credit);
gotoxy(0,11+j);
printf(" Grade        : ");
scanf(" %f", &st2[i].Grade);
total.tCredit=total.tCredit+st2[i].Credit;
total.tGrade=total.tGrade+st2[i].Grade;
total.serve=st2[i].Grade*st2[i].Credit;
total.ttotal=total.ttotal+total.serve;
j+=4;
}
for(i=0;i<j;i++)
	{gotoxy(25,9+i);
	printf("|");}
int k;
for(k=0;k<1;k++)
	{gotoxy(25,9+i+k);
	printf("|"); }

total.Average=total.ttotal/total.tCredit;
gotoxy(28,10);
printf("Student ID: %d",st1.ID);
gotoxy(28,11);
printf("Student First Name: %s",st1.fName);
gotoxy(28,13);
printf("Course Number  Credit   Grade");

for(i=0;i<n;i++)
{
gotoxy(34,14+i);
printf("%s",st2[i].Course);
gotoxy(45,14+i);
printf("%d",st2[i].Credit);
gotoxy(52,14+i);
printf("%.02f",st2[i].Grade);
}
gotoxy(28,16+i);
printf("Total Units: %d",total.tCredit);
gotoxy(28,17+i);
printf("GPA        : %.02f",total.Average);

getch();
return 0;
}
