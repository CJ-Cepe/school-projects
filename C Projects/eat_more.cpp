/*
  Cepe,Carl Joseph R.                     
  Galindez,Christoper Elijah		
  BSCS 2-1
  Data structures
  EATMORE
  8/1/2019
  dev- c++
*/	
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<math.h>
void gotoxy(short x, short y);
struct Customer{int p,s,h,popcorn,soda,hotdog,go,hdone,sdone,pdone,done,time,finish;}c1,c2,c3;
int pServe=1,sServe=2,hServe=4;
int main(){
c1.pdone=0;c1.sdone=0;c1.hdone=0;c2.pdone=0;c2.sdone=0;c2.hdone=0;c3.pdone=0;c3.sdone=0;c3.hdone=0;c3.done=0;c1.time=0;c2.time=0;
int PopcornAvailable=1,SodaAvailable=1,HotdogAvailable=1,A,B,C,D,E,F,X=0,Z;c1.go=1;c2.go=1;c3.go=1;c1.done=0;c2.done=0;c3.time=0;
printf("--INPUT QUANTITY--\n");
printf("\n  Customer1");printf("\n    Popcorn:");scanf("%d",&c1.p);printf("    Soda:");scanf("%d",&c1.s);printf("    Hotdog:");scanf("%d",&c1.h);
printf("\n  Customer2");printf("\n    Popcorn:");scanf("%d",&c2.p);printf("    Soda:");scanf("%d",&c2.s);printf("    Hotdog:");scanf("%d",&c2.h);
printf("\n  Customer3");printf("\n    Popcorn:");scanf("%d",&c3.p);printf("    Soda:");scanf("%d",&c3.s);printf("    Hotdog:");scanf("%d",&c3.h);	
c1.popcorn=c1.p*pServe;c1.soda=c1.s*sServe;c1.hotdog=c1.h*hServe;
c2.popcorn=c2.p*pServe;c2.soda=c2.s*sServe;c2.hotdog=c2.h*hServe;
c3.popcorn=c3.p*pServe;c3.soda=c3.s*sServe;c3.hotdog=c3.h*hServe;
//***********************SOLUTION 1******************************************
gotoxy(27,1);printf("POPCORN   SODA   HOTDOG ");
while(Z!=3){
if(PopcornAvailable==1){
	         if(c2.go==1&&c2.pdone==0&&PopcornAvailable==1){A=c2.popcorn;B=2;PopcornAvailable=0;c2.go=0;c2.pdone=1;}
		else if(c1.go==1&&c1.pdone==0&&PopcornAvailable==1){A=c1.popcorn;B=1;PopcornAvailable=0;c1.go=0;c1.pdone=1;}
		else if(c3.go==1&&c3.pdone==0&&PopcornAvailable==1){A=c3.popcorn;B=3;PopcornAvailable=0;c3.go=0;c3.pdone=1;}
			}
if(SodaAvailable==1){
	         if(c3.go==1&&c3.sdone==0&&SodaAvailable==1){C=c3.soda;D=3;SodaAvailable=0;c3.go=0;c3.sdone=1;}
		else if(c2.go==1&&c2.sdone==0&&SodaAvailable==1){C=c2.soda;D=2;SodaAvailable=0;c2.go=0;c2.sdone=1;}
		else if(c1.go==1&&c1.sdone==0&&SodaAvailable==1){C=c1.soda;D=1;SodaAvailable=0;c1.go=0;c1.sdone=1;}
			}
if(HotdogAvailable==1){
	         if(c1.go==1&&c1.hdone==0&&HotdogAvailable==1){E=c1.hotdog;F=1;HotdogAvailable=0;c1.go=0;c1.hdone=1;}
		else if(c3.go==1&&c3.hdone==0&&HotdogAvailable==1){E=c3.hotdog;F=3;HotdogAvailable=0;c3.go=0;c3.hdone=1;}
		else if(c2.go==1&&c2.hdone==0&&HotdogAvailable==1){E=c2.hotdog;F=2;HotdogAvailable=0;c2.go=0;c2.hdone=1;}
		    }
if(PopcornAvailable==0){
	if(A!=0&&A>0){
		gotoxy(30,2+X);printf("%d",B);A--;
			if(A==0){
				PopcornAvailable=1;
					     if(B==1)
						c1.go=1;
					else if(B==2)
						c2.go=1;
					else if(B==3)
						c3.go=1;
			}
	}
	else if(A==0){
		gotoxy(30,2+X);printf("*");
		PopcornAvailable=1;
				if(B==1)
					c1.go=1;
				else if(B==2)
					c2.go=1;
				else if(B==3)
					c3.go=1;
	}
}
else{gotoxy(30,2+X);printf("*");}
if(SodaAvailable==0){
	if(C!=0&&C>0){
		gotoxy(38,2+X);printf("%d",D);C--;
			if(C==0){
				SodaAvailable=1;
					     if(D==1)
						c1.go=1;
					else if(D==2)
						c2.go=1;
					else if(D==3)
						c3.go=1;
			}
	}
	else if(C==0){
		gotoxy(38,2+X);printf("*");
		SodaAvailable=1;
				if(D==1)
					c1.go=1;
				else if(D==2)
					c2.go=1;
				else if(D==3)
					c3.go=1;
	}
}
else{gotoxy(38,2+X);printf("*");}
if(HotdogAvailable==0){
	if(E!=0&&E>0){
		gotoxy(46,2+X);printf("%d",F);E--;
			if(E==0){
				HotdogAvailable=1;
					if(F==1)
						c1.go=1;
					else if(F==2)
						c2.go=1;
					else if(F==3)
						c3.go=1;
			}
	}
	else if(E==0){
		gotoxy(46,2+X);printf("*");
		HotdogAvailable=1;
				if(F==1)
					c1.go=1;
				else if(F==2)
					c2.go=1;
				else if(F==3)
					c3.go=1;
	}
}
else{gotoxy(46,2+X);printf("*");}

if(c1.hdone==1&&c1.pdone==1&&c1.sdone==1&&c1.go==1)c1.done=1;
	if(c1.done==1)c1.time++;
if(c2.hdone==1&&c2.pdone==1&&c2.sdone==1&&c2.go==1)c2.done=1;
	if(c2.done==1)c2.time++;
if(c3.hdone==1&&c3.pdone==1&&c3.sdone==1&&c3.go==1)c3.done=1;
	if(c3.done==1)c3.time++;
X++;
if(c1.done==1&&c2.done==1&&c3.done==1)Z=3;
gotoxy(20,1+X);printf("min %d",X);
}c1.finish=X-(c1.time-1);c2.finish=X-(c2.time-1);c3.finish=X-(c3.time-1);
float Average1=float((c1.finish+c2.finish+c3.finish)/3);
gotoxy(28,3+X);printf("(1)Total Time: %d",X);
gotoxy(25,4+X);printf("---time spend buying----");
gotoxy(27,5+X);printf("Customer 1: %d min",c1.finish);
gotoxy(27,6+X);printf("Customer 2: %d min",c2.finish);
gotoxy(27,7+X);printf("Customer 3: %d min",c3.finish);
gotoxy(27,8+X);printf(">>>AVERAGE: %.0f min",Average1);


gotoxy(0,2*X);
}//main

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
