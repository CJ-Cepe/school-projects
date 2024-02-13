#include<conio.h>
#include<stdio.h>
#include<float.h>

extern void _floatconvert();
#pragma extref _floatconvert
struct INFO
{
	int ID,Day,Month,Year;
	char fName[20],mInitial[5],lName[20];
} st1;
struct SUB
{
	char Course[20];
	int Credit,tCredit;
	float Grade,tGrade,Average;

} st2[20],total;

void main(){clrscr();
int i,n;
total.tCredit=0;
total.tGrade=0;
printf("Enter number of courses to input: ");
scanf("%d",&n);


printf("\n Student ID: ");
scanf("%d",&st1.ID);
printf("\n Student Name: ");
scanf("%s %s %s",&st1.fName,&st1.mInitial,&st1.lName);
printf("\n Birthdate: ");
scanf("%d %d %d",&st1.Month,&st1.Day,&st1.Year);

for(i=0;i<n;i++)
{
printf("\n Course Number: ");
scanf(" %s", &st2[i].Course);
printf("\n Credit: ");
scanf(" %d", &st2[i].Credit);
printf("\n Grade: ");
scanf(" %f", &st2[i].Grade);
total.tCredit+=st2[i].Credit ;
total.tGrade+=st2[i].Grade ;
}
total.Average=total.tGrade/total.tCredit;
printf("\n\nStudent ID: %d", st1.ID);
printf("\nName: %s",st1.fName);
printf("\nCourse Number\tCredit\tGrade");

for(i=0;i<n;i++)
{
printf("\n%s\t %d\t %f",st2[i].Course,st2[i].Credit,st2[i].Grade);
}

printf("\nTotal Units: %d",total.tCredit);
printf("\nGPA        : %f",total.Average);

getch();
}