#include<conio.h>
#include<stdio.h>
#include<string.h>

int main(){clrscr();
	typedef struct{
		int stID,month,day,year;
		char fName,mInitial,lName;
		}INFO;
	struct Subject{
		int Credit,tCredit;
		char cNumber;
		float Grade,tGrade,Average;
		};
int i,n;
INFO student1;
Subject student2[1],total;
total.tCredit=0;
total.Average=0;
printf("Enter number of courses to input: ");
scanf("%d",&n);


printf("\n Student ID: ");
scanf("%d",&student1.stID);
printf("\n Student Name: ");
scanf("%s %s %s",&student1.fName,&student1.mInitial,&student1.lName);
printf("\n Birthdate: ");
scanf("%d %d %d",&student1.month,&student1.day,&student1.year);



for (i=0;i<n;i++)
{
printf("\n Course Number: ");
scanf("%s",&student2[i].cNumber);
printf("\n Credit: ");
scanf("%d",&student2[i].Credit);
printf("\n Grade: ");
scanf("%f",&student2[i].Grade);
total.tCredit+=student2[i].Credit;
total.tGrade+=student2[i].Grade;
}
total.Average=total.tGrade/total.tCredit;
printf("\n\nStudent ID: %d",student1.stID);
printf("\nStudent first name: %s",student1.fName);
printf("\nCourse Number\tCredit\tGrade");
for(i=0;i<n;i++	){
	printf("%s\t %d\t %f");}
printf("\nTotal Units: %d",total.tCredit);
printf("\nGPA        : %f",total.Average);

getch();
return 0;
}
