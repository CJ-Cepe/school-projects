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
//---------------------FUNCTION DECLARATION-----------------------------
void BORDER();
void FASTBORDER();
void MENU();
void EXPONENT();
void CONVERSION();
void DECIMAL();
void OCTAL();
void RAILROAD();
void EXIT();
void TELEPHONE();
void FINDTELEPHONE();
void NEWTELEPHONE();
//-----------------------MAIN FUNCTION----------------------------------
int main()
{
clrscr();
BORDER();
MENU();
getch();
return 0;
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
//----------------------EXPONENT FUNCTION--------------------------------
//Function that computes the total answer base from the inputed base and exponent values
void EXPONENT()
{
    long long int base, exponent;
    long long power;
    int i;
    char sagot;
do{//Reading base & exponent
    clrscr();
    FASTBORDER();
    textcolor(CYAN);
    gotoxy(30,3);
    cprintf("EXPONENT CALCULATOR");
    gotoxy(13,5);
    textcolor(GREEN);
    cprintf("'Written as X^n, involving the base X and an exponent n'");
    textcolor(WHITE);
    gotoxy(27,9);
    cprintf("Enter Base (X): ");
    scanf("%lld",&base);
    gotoxy(27,11);
    cprintf("Enter Exponent (n): ");
    scanf("%lld", &exponent);
    power=1;
    //caculating power
    for(i=1; i<=exponent; i++)
	power = power * base;
    gotoxy(27,13);
    cprintf("Answer : %lld", power);
    gotoxy(29,17);
    cprintf("Continue? Y/N: ");
    scanf(" %c",&sagot);
    }
    while(sagot=='y'||sagot=='Y');
    clrscr();
    FASTBORDER();
    MENU();
}
//-------------------CONVERSION MENU FUNCTION----------------------------
//This function serves as the menu for the conversion of decimal <---> octal
void CONVERSION()
{
int sagot;
clrscr();
FASTBORDER();
textcolor(CYAN);
gotoxy(24,3);
cprintf("CONVERSION: Decimal <--->  Octal");
textcolor(GREEN);
gotoxy(17,5);
cprintf("'Choose one by typing the corresponding number'");
textcolor(WHITE);
gotoxy(25,10);
cprintf("(1). Decimal --->  Octal");
gotoxy(25,12);
cprintf("(2). Octal --->  Decimal");
gotoxy(25,14);
cprintf("(3). Go back");
gotoxy(29,18);
cprintf("Choose one: ");
scanf("%d",&sagot);

switch(sagot){
case 1:
	DECIMAL();
	break;
case 2:
	OCTAL();
	break;
case 3:
	clrscr();
	FASTBORDER();
	MENU();
	break;
default:
	textcolor(RED);
	gotoxy(25,18);
	cprintf("Invalid number try again");
	getch();
	clrscr();
	FASTBORDER();
	CONVERSION();
}
}
//---------------------DECIMAL TO OCTAL FUNCTION-----------------------
//     Function that converts the inputed decimal numbers into octal
void DECIMAL()
{   char sagot;
 do{long long decimal,octal= 0,
    i = 1;
    clrscr();
    FASTBORDER();
    textcolor(CYAN);
    gotoxy(31,3);
    cprintf("Decimal To Octal");
    textcolor(GREEN);
    gotoxy(20,5);
    cprintf("'Decimal numbers are: 0,1,2,3,4,5,6,7,8,9'");
    textcolor(WHITE);
    gotoxy(29,10);
    cprintf("Decimal: ");
    scanf("%lld", &decimal);
    while (decimal != 0)
    {
	octal+= (decimal % 8) * i;
	decimal /= 8;
	i *= 10;
    }
    gotoxy(29,13);
    cprintf("Octal= %lld",octal);
    gotoxy(29,18);
    cprintf("Continue Y/N: ");
    scanf(" %c",&sagot);
    }
    while(sagot=='y'||sagot=='Y');
    clrscr();
    FASTBORDER();
    CONVERSION();
}
//-----------------------OCTAL TO DECIMAL FUNCTION----------------------
//     Function that converts the inputed octal numbers into decimal
void OCTAL()
{    char sagot;
do {long long octal,decimal = 0;
    int i = 0;
    clrscr();
    FASTBORDER();
    textcolor(CYAN);
    gotoxy(31,3);
    cprintf("Octal to Decimal");
    textcolor(GREEN);
    gotoxy(21,5);
    cprintf("'Octal numbers are: 0,1,2,3,4,5,6,7'");
    textcolor(WHITE);
    gotoxy(29,10);
    cprintf("Octal: ");
    scanf("%lld", &octal);

    while(octal != 0)
    {
	decimal += (octal%10) * pow(8,i);
	++i;
	octal/=10;
    }

    i = 1;
    gotoxy(29,13);
    cprintf("Decimal= %lld", decimal);
    gotoxy(29,18);
    cprintf("Continue Y/N: ");
    scanf(" %c",&sagot);
    }
    while(sagot=='y'||sagot=='Y');
    clrscr();
    FASTBORDER();
    CONVERSION();

}
//-----------------------RAILROAD FUNCTION-------------------------------
//Function for computing the distance between origin and destination station
void RAILROAD()
{  char sagot='y';

while(sagot=='y'||sagot=='Y')
{  float array[] = {12.7,18.1,11.2,14.6,9.3,20.7,13.4,12.1,15.9};
   int i;
   float x,y;
   float ANSWER=0;
   clrscr();
   FASTBORDER();
   textcolor(CYAN);
   gotoxy(30,3);
   cprintf("RAILROAD DISTANCE");
   textcolor(GREEN);
   gotoxy(27,5);
   cprintf("| 1st and 2nd : 12.7K |");
   gotoxy(27,6);
   cprintf("| 2nd and 3rd : 18.1K |");
   gotoxy(27,7);
   cprintf("| 3rd and 4th : 11.2K |");
   gotoxy(27,8);
   cprintf("| 4th and 5th : 14.6K |");
   gotoxy(27,9);
   cprintf("| 5th and 6th :  9.3K |");
   gotoxy(27,10);
   cprintf("| 6th and 7th : 20.7K |");
   gotoxy(27,11);
   cprintf("| 7th and 8th : 13.4K |");
   gotoxy(27,12);
   cprintf("| 8th and 9th : 12.1K |");
   gotoxy(27,13);
   cprintf("| 9th and 10th: 15.9K |");
   textcolor(WHITE);
   gotoxy(25,15);
   cprintf("ORIGIN STATION: ");
   scanf("%f",&x);
   gotoxy(25,17);
   cprintf("DESTINATION STATION: ");
   scanf("%f",&y);
if(x<10.1&&y<10.1){
	if(x<=0&&y<=0){
	textcolor(RED);
	gotoxy(23,20);
	cprintf("'Invalid Station, try again'");
	getch();
	continue;
	}
	else if(x<y){
	for(i=0;i<y-x;i++)
	ANSWER=ANSWER+array[x-1+i];
	textcolor(WHITE);
	gotoxy(25,19);
	cprintf("TOTAL DISTANCE = %.2f",ANSWER);
	gotoxy(29,21);
	cprintf("Continue Y/N: ");
	scanf(" %c",&sagot);
	}
	else{
	for(i=0;i<x-y;i++)
	ANSWER=ANSWER+array[x-2-i];
	textcolor(WHITE);
	gotoxy(25,19);
	cprintf("TOTAL DISTANCE = %.2f",ANSWER);
	gotoxy(29,21);
	cprintf("Continue Y/N: ");
	scanf(" %c",&sagot);
	}
	}
else{
    textcolor(RED);
    gotoxy(23,20);
    cprintf("'Invalid Station, try again'");
    getch();
    continue;
    }
}
    clrscr();
    FASTBORDER();
    MENU();
}
//-----------------------TELEPHONE MENU FUNCTION-------------------------
//                   Menu function for the telephone
void TELEPHONE()
{
int sagot;
clrscr();
FASTBORDER();
textcolor(CYAN);
gotoxy(35,3);
cprintf("TELEPHONE");
textcolor(GREEN);
gotoxy(13,5);
cprintf("'Choose one function by typing the corresponding number'");
textcolor(WHITE);
gotoxy(28,10);
cprintf("(1). Add Name and Number");
gotoxy(28,12);
cprintf("(2). Find Name");
gotoxy(28,14);
cprintf("(3). Go back");
gotoxy(29,18);
cprintf("Choose one: ");
scanf("%d",&sagot);

switch(sagot){
case 1:
	NEWTELEPHONE();
	break;
case 2:
	FINDTELEPHONE();
	break;
case 3:
	clrscr();
	FASTBORDER();
	MENU();
	break;
default:
	textcolor(RED);
	gotoxy(25,18);
	cprintf("Invalid number try again");
	getch();
	clrscr();
	FASTBORDER();
	TELEPHONE();
}
}
//-----------------------EXIT FUNCTION----------------------------------
//This function appears when closing the program.It contains the programmer's name and section
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
//--------------STRUCTURE ARRAY FOR TELEPHONE---------------------------
struct person{
     char name[20];
     long number;
};
//--------------ADD NAME AND NUMBER FUNCTION-----------------------------
//           Function for adding name and number
void NEWTELEPHONE(){
char sagot='y';

while(sagot=='y'||sagot=='Y')
  {   FILE *fp;
      struct person obj;
      clrscr();
      FASTBORDER();
      fp=fopen("data.txt","a");
      textcolor(CYAN);
      gotoxy(34,3);
      cprintf("Add Record");
      gotoxy(30,5);
      cprintf("Use __ for spacing");
      textcolor(WHITE);
      gotoxy(24,10);
      cprintf("Enter Name : ");
      scanf(" %[^\n]",obj.name);
      gotoxy(24,12);
      cprintf("Enter Telephone No. : ");
      scanf(" %ld",&obj.number);
      fprintf(fp," %20s %8ld",obj.name,obj.number);
      fclose(fp);
      textcolor(GREEN);

      gotoxy(33,18);
      cprintf("==ADDED==");
      textcolor(WHITE);
      gotoxy(31,21);
      cprintf("Continue Y/N: ");
      scanf(" %c",&sagot);
}     clrscr();
      TELEPHONE();
}
//-------------------FIND NAME FUNCTION----------------------------------
//          Function for locating/finding a name
void FINDTELEPHONE(){
char sagot='y';
int i;
while(sagot=='y'||sagot=='Y')
  {   FILE *fp;
      struct person obj;
      char name[20];
      int totrec=0;
      clrscr();
      FASTBORDER();
      fp=fopen("data.txt","r");
      textcolor(CYAN);
      gotoxy(35,3);
      cprintf("==FIND==");
      textcolor(WHITE);
      gotoxy(24,7);
      cprintf("Enter Name : ");
      scanf(" %[^\n]",&name);
      while(!feof(fp))
      {
      fscanf(fp," %20s %8ld",obj.name,&obj.number);
	 if(strcmpi(obj.name,name)==0){
	printf("\t\tName   :  %s",obj.name);
	printf("\t\tTelephone No : %ld\n",obj.number);
	totrec++;
	 }
      }
      if(totrec==0)
	{
	 textcolor(RED);
	 gotoxy(30,19);
	 cprintf("No Data Found");
	 }
      else{
	 textcolor(GREEN);
	 gotoxy(27,19);
	 cprintf("___Total %d Record found___",totrec);
      }
      FASTBORDER();
      fclose(fp);
      textcolor(WHITE);
      gotoxy(30,21);
      cprintf("Continue Y/N: ");
      scanf(" %c",&sagot);
   }
   clrscr();
   TELEPHONE();
}

//-------------------------------END-------------------------------------
