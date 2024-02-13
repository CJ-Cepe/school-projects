//EATMORE
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#define CAPACITY 3
void gotoxy(short x, short y);
int compare(int E,int F,int G);
int Penqueue(int data);int Pdequeue();
int Senqueue(int data);int Sdequeue();
int Henqueue(int data);int Hdequeue();

struct CUSTOMER{
	int Pquant,Squant,Hquant,PopcornTime,HotdogTime,SodaTime,go,sdone,pdone,hdone,wait;
};

//****************VARIABLES**********************
int popcorn[CAPACITY],soda[CAPACITY],hotdog[CAPACITY];
int pfront=0,prear=2,psize=0,Pavailable=1;
int sfront=0,srear=2,ssize=0,Savailable=1;
int hfront=0,hrear=2,hsize=0,Havailable=1;
//*****************MAIN**************************
int main(){
struct CUSTOMER C1,C2,C3;
C1.go=1;C1.pdone=0;C1.sdone=0;C1.hdone=0;
C2.go=1;C2.pdone=0;C2.sdone=0;C2.hdone=0;
C3.go=1;C3.pdone=0;C3.sdone=0;C3.hdone=0;
int TotalTime,A=0,B=0,C=0,J=0,K=0,L=0,T=0,U,V,X=0;
int M=0,N=0,O=0,P,Z=0,E=0,F=0,G=0,Q,R=0,S=0,W;
C1.wait=0;C2.wait=0;C3.wait=0;
//***********PRINTTING***************
printf("--INPUT QUANTITY--\n");
printf("\n  Customer1");printf("\n    Popcorn:");scanf("%d",&C1.Pquant);printf("    Soda:");scanf("%d",&C1.Squant);printf("    Hotdog:");scanf("%d",&C1.Hquant);
printf("\n  Customer2");printf("\n    Popcorn:");scanf("%d",&C2.Pquant);printf("    Soda:");scanf("%d",&C2.Squant);printf("    Hotdog:");scanf("%d",&C2.Hquant);
printf("\n  Customer3");printf("\n    Popcorn:");scanf("%d",&C3.Pquant);printf("    Soda:");scanf("%d",&C3.Squant);printf("    Hotdog:");scanf("%d",&C3.Hquant);
//***********************************
C1.PopcornTime=1*C1.Pquant;C1.SodaTime=2*C1.Squant;C1.HotdogTime=4*C1.Hquant;
C2.PopcornTime=1*C2.Pquant;C2.SodaTime=2*C2.Squant;C2.HotdogTime=4*C2.Hquant;
C3.PopcornTime=1*C3.Pquant;C3.SodaTime=2*C3.Squant;C3.HotdogTime=4*C3.Hquant;
gotoxy(27,1);printf("POPCORN   SODA   HOTDOG ");
//***********************************
while(Z!=3){X++;
if(Pavailable==1){
     if(C1.go==1&&C1.pdone==0&&Pavailable==1){A=C1.PopcornTime;Pavailable=0;C1.pdone=1;C1.go=0;U=1;for(P=0;P<A;P++){gotoxy(30,2+E);E++;printf("1");}}
else if(C2.go==1&&C2.pdone==0&&Pavailable==1){A=C2.PopcornTime;Pavailable=0;C2.pdone=1;C2.go=0;U=2;for(P=0;P<A;P++){gotoxy(30,2+E);E++;printf("2");}}
else if(C3.go==1&&C3.pdone==0&&Pavailable==1){A=C3.PopcornTime;Pavailable=0;C3.pdone=1;C3.go=0;U=3;for(P=0;P<A;P++){gotoxy(30,2+E);E++;printf("3");}}
else {gotoxy(30,2+E);printf("");E++;}
}
if(Savailable==1){
	 if(C1.go==1&&C1.sdone==0&&Savailable==1){B=C1.SodaTime;Savailable=0;C1.sdone=1;C1.go=0;V=1;for(P=0;P<B;P++){gotoxy(38,2+F);F++;printf("1");}}
else if(C2.go==1&&C2.sdone==0&&Savailable==1){B=C2.SodaTime;Savailable=0;C2.sdone=1;C2.go=0;V=2;for(P=0;P<B;P++){gotoxy(38,2+F);F++;printf("2");}}
else if(C3.go==1&&C3.sdone==0&&Savailable==1){B=C3.SodaTime;Savailable=0;C3.sdone=1;C3.go=0;V=3;for(P=0;P<B;P++){gotoxy(38,2+F);F++;printf("3");}}
else {gotoxy(38,2+F);printf("");F++;}
}
if(Havailable==1){
     if(C1.go==1&&C1.hdone==0&&Havailable==1){C=C1.HotdogTime;Havailable=0;C1.hdone=1;C1.go=0;W=1;for(P=0;P<C;P++){gotoxy(46,2+G);G++;printf("1");}}
else if(C2.go==1&&C2.hdone==0&&Havailable==1){C=C2.HotdogTime;Havailable=0;C2.hdone=1;C2.go=0;W=2;for(P=0;P<C;P++){gotoxy(46,2+G);G++;printf("2");}}
else if(C3.go==1&&C3.hdone==0&&Havailable==1){C=C3.HotdogTime;Havailable=0;C3.hdone=1;C3.go=0;W=3;for(P=0;P<C;P++){gotoxy(46,2+G);G++;printf("3");}}
else {gotoxy(46,2+G);printf("");G++;}
}

if(Pavailable==0){
	if(Pavailable==0&&J==0){Penqueue(A);J++;}
	if(popcorn[pfront]==0){
			Pdequeue();
			Pavailable=1;J=0;		
		}
	else if(popcorn[pfront]!=0){
			popcorn[pfront]--;A--;
			if(popcorn[pfront]==0){
			Pdequeue();
			Pavailable=1;J=0;
	}}}
if(Savailable==0){
	if(Savailable==0&&K==0){Senqueue(B);K++;}
	if(soda[sfront]==0){
			Sdequeue();
			Savailable=1;K=0;		
		}
	else if(soda[sfront]!=0){
			soda[sfront]--;B--;
			if(soda[sfront]==0){
			Sdequeue();
			Savailable=1;K=0;
	}}}
if(Havailable==0){
	if(Havailable==0&&L==0){Henqueue(C);L++;}
	if(hotdog[hfront]==0){
			Hdequeue();
			Havailable=1;L=0;		
		}
	else if(hotdog[hfront]!=0){
			hotdog[hfront]--;C--;
			if(hotdog[hfront]==0){
			Hdequeue();
			Havailable=1;L=0;
	}}}
if(J==0&&A==0){
if(U==1)C1.go=1;
else if(U==2)C2.go=1;
else if(U==3)C3.go=1;
}
if(B==0){
if(V==1)C1.go=1;
else if(V==2)C2.go=1;
else if(V==3)C3.go=1;
}
if(C==0){
if(W==1)C1.go=1;
else if(W==2)C2.go=1;
else if(W==3)C3.go=1;
}
if(C1.pdone==1&&C1.sdone==1&&C1.hdone==1&&C1.go==1){M=1;}
if(C2.pdone==1&&C2.sdone==1&&C2.hdone==1&&C2.go==1){N=1;}
if(C3.pdone==1&&C3.sdone==1&&C3.hdone==1&&C3.go==1){O=1;}
if(C1.wait==0&&M==1){C1.wait=X;}
if(C2.wait==0&&N==1){C2.wait=X;}
if(C3.wait==0&&O==1){C3.wait=X;}
if(M==1&&N==1&&O==1)Z=M+N+O;
}//while
TotalTime=compare(E,F,G);
for(Q=1;Q<=TotalTime;Q++){gotoxy(20,1+Q);printf("min %d",Q);}
printf("\n\n\n\t\t\t    Total Time: %d",TotalTime);
printf("\n\t\t       ---time spend buying----");
printf("\n\t\t          Customer 1:  min");printf("\n\t\t          Customer 2:  min");printf("\n\t\t          Customer 3:  min");
printf("\n\n\n\n");printf("%d",X);printf(" %d",C1.wait);printf(" %d",C2.wait);printf(" %d",C3.wait);
}//main


//------------------------ENQUEUE/DEQUEUE----------------------------------------------------
//*********************************************************************
int Penqueue(int data)
{prear = (prear + 1) % CAPACITY; psize++; popcorn[prear] = data;return 1;}
int Pdequeue()
{int data;data = popcorn[pfront];pfront = (pfront + 1) % CAPACITY; psize--;return data;}
//********************************************************************
int Senqueue(int data)
{srear = (srear + 1) % CAPACITY; ssize++; soda[srear] = data;return 1;}
int Sdequeue()
{int data;data = soda[sfront];sfront = (sfront + 1) % CAPACITY; ssize--;return data;}
//*******************************************************************
int Henqueue(int data)
{hrear = (hrear + 1) % CAPACITY; hsize++; hotdog[hrear] = data;return 1;}
int Hdequeue()
{int data;data = hotdog[hfront];hfront = (hfront + 1) % CAPACITY; hsize--;return data;}
//------------------------GOTOXY------------------------------------------------------------
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//------------------------COMPARE----------------------------------------------------------
int compare(int E,int F,int G)
{int temp;if(E>F&&E>G)temp=E;
else if(F>E&&F>G)temp=F;
else if(G>E&&G>F)temp=G;
else temp=E;
return temp;
}
