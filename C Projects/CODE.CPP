#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
void BORDER();
void FASTBORDER();
void INPUTBORDER();
void EXIT();

typedef struct
	{
	int hour,minute;
	char shift[3];
	}TIME;
typedef struct
	{
	int TOTALH,TOTALM;
	char Code[15],Search[15];
	TIME Time_in,Time_out;
	float TOTALB,TOTAL;
	}INFO;
INFO A;
FILE *sfile,*tfile;
int i;

//////////////////////////////////computation
void COMPUTATION()
{           /* for (i=0;i<n;i++)
{          */
A.TOTALH=0;
A.TOTALM=0;
A.TOTAL=0;
	if (strcmp(A.Time_in.shift,A.Time_out.shift)==0)
		{
		if(A.Time_in.hour>A.Time_out.hour){
			A.TOTALH=12-A.Time_in.hour;
			A.TOTALH+=12;
			A.TOTALH+=A.Time_out.hour;}
		else if(A.Time_in.hour==A.Time_out.hour){
			A.TOTALH=0;}

		else
	       {A.TOTALH=A.Time_out.hour-A.Time_in.hour;}
		A.TOTALH--;

		if(A.Time_in.minute!=0){
			A.TOTALM=60-A.Time_in.minute;}
		else{
		A.TOTALH++;}
		A.TOTALM+=A.Time_out.minute;
		if(A.TOTALM==60){
			A.TOTALM=0;
			A.TOTALH++;
			}
		else if(A.TOTALM>60){
			A.TOTALM=A.TOTALM-60;
			A.TOTALH++;}
			   }


	else    {
		A.TOTALH=12-A.Time_in.hour;
		A.TOTALH+=A.Time_out.hour;
		A.TOTALH-=1;
		if(A.Time_in.minute!=0){
			A.TOTALM=60-A.Time_in.minute;}
		else    {
			A.TOTALH++;}
		A.TOTALM+=A.Time_out.minute;

		if(A.TOTALM==60){
			A.TOTALM=0;
			A.TOTALH++;}

		else if(A.TOTALM>60){
			A.TOTALM=A.TOTALM-60;
			A.TOTALH++;}
			}

/*minprice=price/60.0f;
A[i].TOTALB=A[i].TOTALH*price;
PRICEM=minprice*A[i].TOTALM;
A[i].TOTALB+=PRICEM;*/

/*  }
  for(i=0;i<n;i++)
	A.TOTAL+=A.TOTALB;*/
}//end of computation
/////////////////////////////////input
void INPUT(){
char ans='Y';
sfile=fopen("data.txt","a+");
int d=0;
while(toupper(ans)=='Y')
{
FASTBORDER();
INPUTBORDER();
gotoxy(34,3);
textcolor(WHITE);
cprintf("INPUT RECORD");
textcolor(DARKGRAY);
gotoxy(19,23);
cprintf("input %d",1+d);
gotoxy(12,7);
textcolor(LIGHTCYAN);
cprintf("Computer Code:");
scanf("%s",A.Code);
//////////time in
gotoxy(12,9);
cprintf("Time in");
textcolor(DARKGRAY);
gotoxy(11,10);
cprintf("(0-11)");
textcolor(CYAN);
gotoxy(18,10);
cprintf("Hour:");
scanf("%d",&A.Time_in.hour);
textcolor(DARKGRAY);
gotoxy(11,11);
cprintf("(0-59)");
gotoxy(18,11);
textcolor(CYAN);
cprintf("Minute:");
scanf("%d",&A.Time_in.minute);
textcolor(DARKGRAY);
gotoxy(11,12);
cprintf("(AM/PM)");
textcolor(CYAN);
gotoxy(18,12);
cprintf("Shift:");
scanf("%s",A.Time_in.shift);
/// time out
gotoxy(12,14);
textcolor(LIGHTCYAN);
cprintf("Time out");
textcolor(DARKGRAY);
gotoxy(11,15);
cprintf("(0-11)");
gotoxy(18,15);
textcolor(CYAN);
cprintf("Hour:");
scanf("%d",&A.Time_out.hour);
textcolor(DARKGRAY);
gotoxy(11,16);
cprintf("(0-59)");
textcolor(CYAN);
gotoxy(18,16);
cprintf("Minute:");
scanf("%d",&A.Time_out.minute);
textcolor(DARKGRAY);
gotoxy(11,17);
cprintf("(AM/PM)");
textcolor(CYAN);
gotoxy(18,17);
cprintf("Shift:");
scanf("%s",A.Time_out.shift);
COMPUTATION();
gotoxy(12,19);
textcolor(LIGHTCYAN);
cprintf("Time Consumed:%d:%d",A.TOTALH,A.TOTALM);
fprintf(sfile,"%s %d %d %s %d %d %s %d %d\n",A.Code,A.Time_in.hour,A.Time_in.minute,A.Time_in.shift,A.Time_out.hour,A.Time_out.minute,A.Time_out.shift,A.TOTALH,A.TOTALM);
d++;
gotoxy(55,9);
textcolor(RED);
cprintf("RECORD");
gotoxy(55,10);
cprintf("ADDED!");
gotoxy(50,15);
textcolor(WHITE);
cprintf("\nCONTINUE(y/n)?:");
scanf(" %c",&ans);
clrscr();
}
fclose(sfile);
}//end of input

////////////////////////////////////////////////////search
void SEARCH()
{
LOOP:
clrscr();
FASTBORDER();
char ans='Y';
int u=0,i=0,q=0,w=0,e=0;
gotoxy(34,3);
textcolor(WHITE);
cprintf("S E A R C H");
textcolor(LIGHTCYAN);
gotoxy(29,4);
cprintf("Input computer code");
do
{ sfile=fopen("data.txt","r");
  i=0;u=0;
  gotoxy(29,5);
  textcolor(CYAN);
  cprintf("COMPUTER CODE:");
  scanf(" %s",A.Search);
  while(fscanf(sfile,"%s %d %d %s %d %d %s %d %d\n",&A.Code,&A.Time_in.hour,&A.Time_in.minute,&A.Time_in.shift,&A.Time_out.hour,&A.Time_out.minute,&A.Time_out.shift,&A.TOTALH,&A.TOTALM)!=EOF)
	{
	if( strcmp(A.Search,A.Code)==0){
	gotoxy(6+e,7+q);
	textcolor(DARKGRAY);
	cprintf("record %d",1+i);
	gotoxy(6+e,8+q);
	textcolor(CYAN);
	cprintf("Time in:  %d %d %s",A.Time_in.hour,A.Time_in.minute,A.Time_in.shift);
	gotoxy(6+e,9+q);
	cprintf("Time out: %d %d %s",A.Time_out.hour,A.Time_out.minute,A.Time_out.shift);
	gotoxy(6+e,10+q);
	cprintf("Time Consumed: %d:%d",A.TOTALH,A.TOTALM);
	u=1;i++;q+=5;
	if(q==15)
	{q=0;w+=1;}
	if(w==1)
	       { e=0;e+=23;}
	if(i==6)
	{e=0;e+=47;}
	gotoxy(1,1);
	}
	}//while scanf
//fflush(stdin);
if(u==0){
	gotoxy(22,10);
	textcolor(RED);
	cprintf(">>R E C O R D  N O T  F O U N D<<");}
textcolor(LIGHTCYAN);
gotoxy(30,22);
cprintf("CONTINUE(y/n)?:");
scanf(" %c",&ans);
fclose(sfile);
if(toupper(ans)=='Y'){
    goto LOOP; }
}while(toupper(ans)=='Y');
clrscr();
}//end
//////////////////////////////////EDIT
void EDIT()
{
LOOP:
clrscr();
FASTBORDER();
char ans='Y',anse;
int u=0,i=0;
gotoxy(34,3);
textcolor(WHITE);
cprintf("E D I T");
textcolor(CYAN);
gotoxy(29,4);
cprintf("Input computer code");
do
{ sfile=fopen("data.txt","r");
  tfile=fopen("newdata.txt","w	");
  i=0;u=0;
  gotoxy(12,7);
  textcolor(LIGHTCYAN);
  cprintf("COMPUTER CODE:");
  scanf(" %s",A.Search);
  while(fscanf(sfile,"%s %d %d %s %d %d %s %d %d\n",&A.Code,&A.Time_in.hour,&A.Time_in.minute,&A.Time_in.shift,&A.Time_out.hour,&A.Time_out.minute,&A.Time_out.shift,&A.TOTALH,&A.TOTALM)!=EOF)
	{
	//LOOP2:
	if( strcmp(A.Search,A.Code)==0)
	{
	gotoxy(16,9);
	textcolor(LIGHTGRAY);
	cprintf("record %d",1+i);
	textcolor(CYAN);
	gotoxy(12,10);
	cprintf("Time in:  %d %d %s",A.Time_in.hour,A.Time_in.minute,A.Time_in.shift);
	gotoxy(12,11);
	cprintf("Time out: %d %d %s",A.Time_out.hour,A.Time_out.minute,A.Time_out.shift);
	gotoxy(12,12);
	cprintf("Time Consumed: %d:%d\n",A.TOTALH,A.TOTALM);
	u=1,i++;
		gotoxy(30,22);
		printf("EDIT this(y/n)?:");
		scanf(" %c",&anse);
		if(toupper(anse)=='Y'){
			//inputing
			      //	printf("\t\tINPUT");
				gotoxy(47,7);
				printf("Computer Code:");
				scanf("%s",A.Code);
				gotoxy(47,9);
				printf("Time in:");
				gotoxy(49,10);
				printf("Hour:");
				scanf("%d",&A.Time_in.hour);
				gotoxy(49,11);
				printf("Minute:");
				scanf("%d",&A.Time_in.minute);
				gotoxy(49,12);
				printf("Shift:");
				scanf("%s",A.Time_in.shift);
				gotoxy(47,13);
				printf("Time out:");
				gotoxy(49,14);
				printf("Hour:");
				scanf("%d",&A.Time_out.hour);
				gotoxy(49,15);
				printf("Minute:");
				scanf("%d",&A.Time_out.minute);
				gotoxy(49,16);
				printf("Shift:");
				scanf("%s",A.Time_out.shift);
				COMPUTATION();
				gotoxy(47,18);
				printf("Time Consumed: %d:%d",A.TOTALH,A.TOTALM);
					fprintf(tfile,"%s %d %d %s %d %d %s %d %d\n",A.Code,A.Time_in.hour,A.Time_in.minute,A.Time_in.shift,A.Time_out.hour,A.Time_out.minute,A.Time_out.shift,A.TOTALH,A.TOTALM);
				getch();
				textcolor(YELLOW);
				gotoxy(66,13);
				cprintf("RECORD");
				gotoxy(66,14);
				cprintf("EDITED");
				getch();
				gotoxy(47,7);
				printf("                        ");
				gotoxy(47,9);
				printf("                        ");
				gotoxy(47,10);
				printf("                        ");
				gotoxy(47,11);
				printf("                        ");
				gotoxy(47,12);
				printf("                        ");
				gotoxy(47,13);
				printf("                          ");
				gotoxy(47,14);
				printf("                          ");
				gotoxy(47,15);
				printf("                        ");
				gotoxy(47,16);
				printf("                        ");
				gotoxy(47,17);
				printf("                        ");
				gotoxy(47,18);
				printf("                        ");
				gotoxy(46,22);
				printf(" ");
					}
		else{
		fprintf(tfile,"%s %d %d %s %d %d %s %d %d\n",A.Code,A.Time_in.hour,A.Time_in.minute,A.Time_in.shift,A.Time_out.hour,A.Time_out.minute,A.Time_out.shift,A.TOTALH,A.TOTALM);}
	}
	else
	{
	fprintf(tfile,"%s %d %d %s %d %d %s %d %d\n",A.Code,A.Time_in.hour,A.Time_in.minute,A.Time_in.shift,A.Time_out.hour,A.Time_out.minute,A.Time_out.shift,A.TOTALH,A.TOTALM);}
	gotoxy(46,22);
	printf(" ");
	}//while scanf
if(u==0){
	gotoxy(30,22);
	printf("record not found");}
gotoxy(27,23);
printf("CONTINUE SEARCH(y/n)?:");
scanf(" %c",&ans);
fclose(sfile);
fclose(tfile);
remove("data.txt");
rename("newdata.txt","data.txt");
if(toupper(ans)=='Y')
	{goto LOOP;}
}while(toupper(ans)=='Y');
clrscr();
}//end




void DELETE()
{
char ans='Y',anse;
int u=0,i=0;
gotoxy(34,3);
textcolor(WHITE);
cprintf("D E L E T E");
gotoxy(30,4);
textcolor(CYAN);
cprintf("Input computer code");
do
{ sfile=fopen("data.txt","r");
  tfile=fopen("newdata.txt","w	");
  i=0,u=0;
  gotoxy(42,8);
  printf("          ");
  gotoxy(28,8);
  textcolor(LIGHTCYAN);
  cprintf("COMPUTER CODE:");
  scanf(" %s",A.Search);
  while(fscanf(sfile,"%s %d %d %s %d %d %s %d %d\n",&A.Code,&A.Time_in.hour,&A.Time_in.minute,&A.Time_in.shift,&A.Time_out.hour,&A.Time_out.minute,&A.Time_out.shift,&A.TOTALH,&A.TOTALM)!=EOF)
	{
	if( strcmp(A.Search,A.Code)==0)
	{
	textcolor(LIGHTGRAY);
	gotoxy(32,10);
	cprintf("record %d",1+i);
	textcolor(LIGHTCYAN);
	gotoxy(28,11);
	cprintf("Time in:  %d %d %s",A.Time_in.hour,A.Time_in.minute,A.Time_in.shift);
	gotoxy(28,12);
	cprintf("Time out: %d %d %s",A.Time_out.hour,A.Time_out.minute,A.Time_out.shift);
	gotoxy(28,13);
	cprintf("Time Consumed: %d:%d\n",A.TOTALH,A.TOTALM);
	u=1,i++;
		gotoxy(48,19);
		printf("     ");
		gotoxy(30,19);
		printf("DELETE this(y/n)?:");
		scanf(" %c",&anse);
		if(toupper(anse)=='Y'){
		   gotoxy(35,16);
		   textcolor(YELLOW);
		   cprintf("RECORD");
		   gotoxy(35,17);
		   cprintf("DELETED");
		   getch();
		   gotoxy(34,16);
		   printf("              ");
		   gotoxy(34,17);
		   printf("              ");
			}
		else{
		fprintf(tfile,"%s %d %d %s %d %d %s %d %d\n",A.Code,A.Time_in.hour,A.Time_in.minute,A.Time_in.shift,A.Time_out.hour,A.Time_out.minute,A.Time_out.shift,A.TOTALH,A.TOTALM);}
		}
	else
	{
	fprintf(tfile,"%s %d %d %s %d %d %s %d %d\n",A.Code,A.Time_in.hour,A.Time_in.minute,A.Time_in.shift,A.Time_out.hour,A.Time_out.minute,A.Time_out.shift,A.TOTALH,A.TOTALM);}
	}//while scanf
if(u==0){
	gotoxy(30,19);
	textcolor(RED);
	cprintf("RECORD NOT FOUND");
	}
gotoxy(29,20);
printf("CONTINUE SEARCH(y/n)?:");
scanf(" %c",&ans);
gotoxy(27,19);
printf("                           ");
gotoxy(27,20);
printf("                           ");
gotoxy(32,10);
printf("                           ");
gotoxy(28,11);
printf("                           ");
gotoxy(28,12);
printf("                           ");
gotoxy(28,13);
printf("                           ");

fclose(sfile);
fclose(tfile);
remove("data.txt");
rename("newdata.txt","data.txt");
}while(toupper(ans)=='Y');
clrscr();
}//end

///////////////////////////////////////printing table
/*void TABLE()
{
char ans='Y';
int i=0;
printf("\t\tTABLE");
sfile=fopen("data.txt","r");
while(fscanf(sfile,"%s %d %d %s %d %d %s %d %d\n",&A.Code,&A.Time_in.hour,&A.Time_in.minute,&A.Time_in.shift,&A.Time_out.hour,&A.Time_out.minute,&A.Time_out.shift,&A.TOTALH,&A.TOTALM)!=EOF)
{
	printf("\COMPUTER CODE: %s",A.Code);
	printf("\nTime in:  %d %d %s",A.Time_in.hour,A.Time_in.minute,A.Time_in.shift);
	printf("\nTime out: %d %d %s",A.Time_out.hour,A.Time_out.minute,A.Time_out.shift);
	printf("\nTime Consumed: %d:%d\n",A.TOTALH,A.TOTALM);

	if(i=5)
		{getch,clrscr();FASTBORDER;,table;i=0;
	else
		i++;
}

	       // use i for gotoxy and next page
}//while fscanf
fclose(sfile);
}//end
*/

void MENU()
{clrscr();
FASTBORDER();
int sagot;
while(sagot!=5){
textcolor(YELLOW);
gotoxy(37,3);
cprintf("MENU");
textcolor(CYAN);
gotoxy(13,5);
cprintf("'Choose one function by typing the corresponding number'");
textcolor(WHITE);
gotoxy(29,9);
cprintf("(1). Input Record");
gotoxy(29,11);
cprintf("(2). Search Record");
gotoxy(29,13);
cprintf("(3). Edit Record");
gotoxy(29,15);
cprintf("(4). Delete Record");
gotoxy(29,17);
cprintf("(5). Exit");
gotoxy(29,21);
cprintf("Choose one: ");
	scanf("%d",&sagot);
switch(sagot){
case 1:
	clrscr();
	INPUT();
	FASTBORDER();
	break;
case 2:
	clrscr();
	FASTBORDER();
	SEARCH();
	FASTBORDER();
	break;
case 3:
	clrscr();
	FASTBORDER();
	EDIT();
	FASTBORDER();
	break;
case 4:
	clrscr();
	FASTBORDER();
	DELETE();
	FASTBORDER();
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
void main(){
clrscr();
FASTBORDER();     ////////to edit back
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
void INPUTBORDER()
{
int a,b,c,d,e,f,g;
  gotoxy(38,6);
		textcolor(LIGHTGRAY);
		cprintf(" %c",191);
		delay(0);
 gotoxy(9,6);
	for(a=1;a<=30;a++)
	{
		textcolor(LIGHTGRAY);
		cprintf("%c",196);
		delay(0);
	}

  gotoxy(9,6);
		textcolor(LIGHTGRAY);
		cprintf(" %c",218);
		delay(0);

 gotoxy(10,7);
	for(a=1;a<=15;a++)
	{
		textcolor(LIGHTGRAY);
		cprintf("%c",179);
		gotoxy(10,7+a);
		printf("");
		delay(0);
	}
gotoxy(9,22);
		textcolor(LIGHTGRAY);
		cprintf(" %c",192);
		delay(0);
gotoxy(38,22);
		textcolor(LIGHTGRAY);
		cprintf(" %c",217);
		delay(0);
gotoxy(11,22);
	for(c=1;c<=28;c++)
	{
		textcolor(LIGHTGRAY);
		cprintf("%c",196);
		delay(0);
	}
	for(d=1;d<=15;d++)
	{
		textcolor(LIGHTGRAY);
		gotoxy(39,6+d);
		cprintf("%c",179);
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
cprintf("Project:FILE");
getch();
}
//end of the prog
