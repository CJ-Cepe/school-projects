//EATMORE
#include<conio.h>
#include<stdio.h>
#define CAPACITY 3
int Penqueue(int data);
int Pdequeue();
int Senqueue(int data);
int Sdequeue();
int Henqueue(int data);
int Hdequeue();

struct CUSTOMER{
	int Pquant,Squant,Hquant,PopcornTime,HotdogTime,SodaTime,TransactionTime,Time,Buying,go,sdone,pdone,hdone;
};
struct Queue{
	int front,rear,size,available;
};
int main(){
//****************VARIABLES**********************
struct Queue popcorn[CAPACITY],soda[CAPACITY],hotdog[CAPACITY];
popcorn[0].front=0;popcorn[0].rear=2;popcorn[0].size=0,popcorn[0].available=1;
soda[0].front=0;soda[0].rear=2;soda[0].size=0,soda[0].available=1;
hotdog[0].front=0;hotdog[0].rear=2;hotdog[0].size=0,hotdog[0].available=1;
struct CUSTOMER C1,C2,C3;
C1.go=1,C1.pdone=0,C1.sdone=0,C1.hdone=0;
C2.go=1,C2.pdone=0,C2.sdone=0,C2.hdone=0;
C3.go=1,C3.pdone=0,C3.sdone=0,C3.hdone=0;
int TotalTime=1,A=0,B=0,C=0,J=0,K=0,L=0,Z=0;
//***************PRINTTING***********************
printf("--INPUT QUANTITY--");
printf("\n  Customer1");printf("\n    Popcorn:");scanf(" %d",&C1.Pquant);printf("\n    Soda:");scanf(" %d",&C1.Squant);printf("\n    Hotdog:");scanf(" %d",&C1.Hquant);
printf("\n  Customer2");printf("\n    Popcorn:");scanf(" %d",&C2.Pquant);printf("\n    Soda:");scanf(" %d",&C2.Squant);printf("\n    Hotdog:");scanf(" %d",&C2.Hquant);
printf("\n  Customer3");printf("\n    Popcorn:");scanf(" %d",&C3.Pquant);printf("\n    Soda:");scanf(" %d",&C3.Squant);printf("\n    Hotdog:");scanf(" %d",&C3.Hquant);
//************************
C1.PopcornTime=1*C1.Pquant;C1.SodaTime=2*C1.Squant;C1.HotdogTime=4*C1.Hquant;
C2.PopcornTime=1*C2.Pquant;C2.SodaTime=2*C2.Squant;C2.HotdogTime=4*C2.Hquant;
C3.PopcornTime=1*C3.Pquant;C3.SodaTime=2*C3.Squant;C3.HotdogTime=4*C3.Hquant;
//***********************************************
for(int i=1;Z=3;i++)
if(popcorn[0].available==1){
     if(C1.go==1&&C1.pdone==0&&popcorn[0].available==1){A=C1.PopcornTime;popcorn[0].available=0;C1.pdone=1;C1.go=0;}
else if(C2.go==1&&C2.pdone==0&&popcorn[0].available==1){A=C2.PopcornTime;popcorn[0].available=0;C2.pdone=1;C2.go=0;}
else if(C3.go==1&&C3.pdone==0&&popcorn[0].available==1){A=C3.PopcornTime;popcorn[0].available=0;C3.pdone=1;C3.go=0;}
}

if(soda[0].available==1){
	 if(C1.go==1&&C1.sdone==0&&soda[0].available==1){B=C1.SodaTime;soda[0].available=0;C1.sdone=1;C1.go=0;}
else if(C2.go==1&&C2.sdone==0&&soda[0].available==1){B=C2.SodaTime;soda[0].available=0;C2.sdone=1;C2.go=0;}
else if(C3.go==1&&C3.sdone==0&&soda[0].available==1){B=C3.SodaTime;soda[0].available=0;C3.sdone=1;C3.go=0;}
}

if(hotdog[0].available==1){
     if(C1.go==1&&C1.hdone==0&&hotdog[0].available==1){C=C1.HotdogTime;hotdog[0].available=0;C1.hdone=1;C1.go=0;}
else if(C2.go==1&&C2.hdone==0&&hotdog[0].available==1){C=C2.HotdogTime;hotdog[0].available=0;C2.hdone=1;C2.go=0;}
else if(C3.go==1&&C3.hdone==0&&hotdog[0].available==1){C=C3.HotdogTime;hotdog[0].available=0;C3.hdone=1;C3.go=0;}
}

if(popcorn[0].available==0){
	if(popcorn[0].available==0&&J==0){Penqueue(A);J++;}
	if(popcorn[popcorn.front].front==0){
			Pdequeue();
			popcorn[0].available=1;J=0;		
		}
	else if(popcorn[popcorn.front]!=0){
			popcorn[popcorn.front]--;A--;
			if(popcorn[popcorn.front]==0){
			Pdequeue();
			popcorn.available=1;J=0;
	}}}
if(soda.available==0){
	if(soda.available==0&&K==0){Senqueue(B);K++;}
	if(soda[soda.front]==0){
			Sdequeue();
			Soda.available=1;K=0;		
		}
	else if(soda[soda.front]!=0){
			soda[soda.front]--;B--;
			if(soda[soda.front]==0){
			Sdequeue();
			Soda.available=1;K=0;
	}}}
if(hotdog.available==0){
	if(hotdog.available==0&&L==0){Henqueue(C);L++;}
	if(hotdog[hotdog.front]==0){
			Hdequeue();
			hotdog.available=1;L=0;		
		}
	else if(hotdog[hotdog.front]!=0){
			hotdog[hotdog.front]--;C--;
			if(hotdog[hotdog.front]==0){
			Hdequeue();
			Hotdog.available=1;L=0;
	}}}
if(A==0)
	C1.go=1;
if(B==0)
	C2.go=1;
if(C==0)
	C3.go=1;
TotalTime++;
if(C1.pdone==1&&C1.sdone==1&&C1.hdone==1&&C2.pdone==1&&C2.sdone==1&&C2.hdone==1&&C3.pdone==1&&C3.sdone==1&&C3.hdone==1)
	Z=3;
}//for
}//main






















//------------------------ENQUEUE/DEQUEUE-----------------------------------------
//*********************************************************************
int Penqueue(int data)
{
    popcorn[0].rear = (popcorn[0].rear + 1) % CAPACITY; size++; popcorn[popcorn[0].rear].rear = data;
    return 1;
}
int Pdequeue()
{
    int data; 
    data = popcorn[front];popcorn.front = (popcorn.front + 1) % CAPACITY; size--;
    return data;
}
//********************************************************************
int Senqueue(int data)
{
    soda.rear = (soda.rear + 1) % CAPACITY; size++; soda[soda.rear] = data;
    return 1;
}
int Sdequeue()
{
    int data; 
    data = soda[soda.front];soda.front = (soda.front + 1) % CAPACITY; size--;
    return data;
}
//*******************************************************************
int Henqueue(int data)
{
    hotdog.rear = (hotdog.rear + 1) % CAPACITY; size++; hotdog[hotdog.rear] = data;
    return 1;
}
int Hdequeue()
{
    int data; 
    data = hotdog[hotdog.front];hotdog.front = (front + 1) % CAPACITY; size--;
    return data;
}


