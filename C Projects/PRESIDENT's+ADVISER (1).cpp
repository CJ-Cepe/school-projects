/*Data structures
  President's Adviser
  bscs 2-1
  7/25/2019
  Galindez, Christopher Elijah.
  Cepe,Carl Joseph R.
*/


//#include<iostream.h>
#include<stdio.h>
#include<windows.h>
void gotoxy(short x, short y);

//PRESIDENT"S ADVISER
int main(){
bool cont= true;	
while (cont){
system("CLS");
//*************Variables******************
int n=13,k;
int start,adviser[n]={1,2,3,4,5,6,7,8,9,10,11,12,13},interval,z=5,i,nextposition;

//printing
printf("\n\t\t    P R E S I D E N T 'S   A D V I S E R");
gotoxy(11,5);printf("\t   i n p u t");
gotoxy(13,8);printf("  START :");
gotoxy(13,12);printf("INTERVAL:");
gotoxy(46,5);printf("o u t p u t");
gotoxy(48,7);printf("ADVISORS");
gotoxy(21,19);printf("'input 0 to the START to stop'");
//----border
for(k=0;k<58;k++){gotoxy(9+k,4);printf("%c",196);}for(k=0;k<58;k++){gotoxy(9+k,15);printf("%c",196);}
for(k=0;k<10;k++){gotoxy(9,5+k);printf("%c",179);}for(k=0;k<10;k++){gotoxy(66,5+k);printf("%c",179);}
gotoxy(9,4);printf("%c",218);gotoxy(66,4);printf("%c",191);gotoxy(9,15);printf("%c",192);gotoxy(66,15);printf("%c",217);
for(k=0;k<10;k++){gotoxy(36,5+k);printf("%c",179);}

//scanning
gotoxy(22,8);scanf("%d",&start); if(start==0){cont=false;} start--;
	
if(cont!=false){
gotoxy(22,12);scanf("%d",&interval);interval--;
nextposition=start+interval;
for(i=0;i<z;i++)
{ 	int a=n-1;
 	if(nextposition>a){
		while(nextposition>a){
		nextposition=nextposition-n;
		}
	gotoxy(51,9+i );printf("%d", adviser[nextposition]);
	}
	else
	{gotoxy(51,9+i);printf("%d", adviser[nextposition]);}
//********** deleting array ***************	
	  for (int j=nextposition; j<a; j++) 
      	 {adviser[j] = adviser[j+1];}
    n = n - 1;
	nextposition+=interval;
	
}gotoxy(22,17);system("pause");
}//if
}//while
gotoxy(0,21);
}//main

void gotoxy(short x, short y) {//gotoxy function ********padagdag(copy/paste) nalang!!!
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/* solution without design
	
	//PRESIDENT"S ADVISER
int main(){//system(cls);
//*************Variables******************
int n=13;
int start,adviser[n]={1,2,3,4,5,6,7,8,9,10,11,12,13},interval,z=5,i,nextposition;
printf("PRESIDENT'S ADVISER");
printf("\nEnter where to start: ");
scanf("%d",&start);start--;
printf("\nEnter the interval: ");
scanf("%d",&interval);interval--;
nextposition=start+interval;
for(i=0;i<z;i++)
{ 	int a=n-1;
	if(nextposition>a){
		while(nextposition>a){
		nextposition=nextposition-n;
		}
	printf("%d,", adviser[nextposition]);
	}
	else
	{printf("%d,", adviser[nextposition]);}
//********** deleting array ***************	
	  for (int j=nextposition; j<a; j++) 
      	 {adviser[j] = adviser[j+1];}
    n = n - 1;
	nextposition+=interval;
}
}

*/



	
