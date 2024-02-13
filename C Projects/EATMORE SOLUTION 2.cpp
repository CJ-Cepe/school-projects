/*
  Cepe,Carl Joseph R.                     
  Galindez,Christoper Elijah		
  BSCS 2-1
  Data structures
  EATMORE solution 2:with queues
  8/24/2019
  dev- c++
*/	

#include<stdio.h>
#include<windows.h>
#define pServe 1//popcorn serving duration
#define sServe 2//soda serving duration
#define hServe 4//hotdog serving duration
#define MAX 20

int TIME,X,a,b,c,c1END,c2END,c3END;

void gotoxy(short x, short y);
void initialization();
void PrintScan();
void finishChecker();
void HOTDOG();
void SODA();
void POPCORN();
void antiLoop();
void Queue(int value,int determine,char man);

struct Customer{
	int popcorn,soda,hotdog;
	int p,s,h;
	bool finish,pfin,sfin,hfin,free;
}c1,c2,c3;

struct Queue{
	int size,front,back,array[MAX];
	char array2[MAX];
	bool fresh;
};

struct Food{
	bool availability,empty;
	struct Queue queue;
	int processing;
	char tao;
}popcorn,soda,hotdog;

int main(){
initialization();
PrintScan();
antiLoop();
while(true){	
	
	if(c1.finish!=true){
		 if(c1.pfin!=true&&c1.free==true&&popcorn.queue.fresh!=true){
			Queue(c1.popcorn,1,'1');
			c1.free=false;
			popcorn.queue.fresh=true;}
		 else if(c1.sfin!=true&&c1.free==true&&soda.queue.fresh!=true){
		 	Queue(c1.soda,2,'1');
		 	c1.free=false;
			soda.queue.fresh=true;}
		 else if(c1.hfin!=true&&c1.free==true&&hotdog.queue.fresh!=true){
		 	Queue(c1.hotdog,3,'1');
		 	c1.free=false;
			hotdog.queue.fresh=true;}
	   }//if c1

	if(c2.finish!=true){
		 if(c2.pfin!=true&&c2.free==true&&popcorn.queue.fresh!=true){
			Queue(c2.popcorn,1,'2');
			c2.free=false;
			popcorn.queue.fresh=true;}
		 else if(c2.sfin!=true&&c2.free==true&&soda.queue.fresh!=true){
		 	Queue(c2.soda,2,'2');
		 	c2.free=false;
			soda.queue.fresh=true;}
		 else if(c2.hfin!=true&&c2.free==true&&hotdog.queue.fresh!=true){
		 	Queue(c2.hotdog,3,'2');
		 	c2.free=false;
			hotdog.queue.fresh=true;}
	}//if c2

	if(c3.finish!=true){
		 if(c3.pfin!=true&&c3.free==true&&popcorn.queue.fresh!=true){
			Queue(c3.popcorn,1,'3');
			c3.free=false;
			popcorn.queue.fresh=true;}
		 else if(c3.sfin!=true&&c3.free==true&&soda.queue.fresh!=true){
		 	Queue(c3.soda,2,'3');
		 	c3.free=false;
			soda.queue.fresh=true;}
		 else if(c3.hfin!=true&&c3.free==true&&hotdog.queue.fresh!=true){
		 	Queue(c3.hotdog,3,'3');
		 	c3.free=false;
			hotdog.queue.fresh=true;}
	}//if c3

POPCORN();SODA();HOTDOG();
if(popcorn.queue.size<2)
	popcorn.queue.fresh=false;
if(soda.queue.size<2)	
	soda.queue.fresh=false;
if(hotdog.queue.size<2)
	hotdog.queue.fresh=false;
finishChecker();
X++;
if(c1.finish==true&&a==0)
	{ c1END=X; a=1;}
if(c2.finish==true&&b==0)
	{ c2END=X; b=1;}
if(c3.finish==true&&c==0)
	{ c3END=X; c=1;}
if(c1.finish==true&&c2.finish==true&&c3.finish==true)
	break;
TIME++;
}//while
float Average=(c1END+c2END+c3END)/3;
gotoxy(0,20);
gotoxy(28,3+X);printf("(1)Total Time: %d",X);
gotoxy(25,4+X);printf("---time spend buying----");
gotoxy(27,5+X);printf("Customer 1: %d min",c1END);
gotoxy(27,6+X);printf("Customer 2: %d min",c2END);
gotoxy(27,7+X);printf("Customer 3: %d min",c3END);
gotoxy(27,8+X);printf(">>>AVERAGE: %.0f min",Average);
}//main

void Queue(int value,int determine,char man){
	if(determine==1)
		{popcorn.queue.array[popcorn.queue.back]=value;
		 popcorn.queue.array2[popcorn.queue.back]=man;
		 popcorn.queue.back++;
		 popcorn.queue.size++;}
	else if(determine==2)
		{soda.queue.array[soda.queue.back]=value;
		 soda.queue.array2[soda.queue.back]=man;
		 soda.queue.back++;
		 soda.queue.size++;}
	else if(determine==3)
		{hotdog.queue.array[hotdog.queue.back]=value;
		 hotdog.queue.array2[hotdog.queue.back]=man;
		 hotdog.queue.back++;
		 hotdog.queue.size++;}
}//Queue

void POPCORN(){
	
	if(popcorn.availability==true&&popcorn.queue.size!=0)
	{
		popcorn.processing=popcorn.queue.array[popcorn.queue.front];
		popcorn.tao=popcorn.queue.array2[popcorn.queue.front];
		popcorn.queue.front++;
		popcorn.availability=false;
	}
		if(popcorn.tao=='1')
		{gotoxy(30,2+X);printf("1");}
		else if(popcorn.tao=='2')
		{gotoxy(30,2+X);printf("2");}
		else if(popcorn.tao=='3')
		{gotoxy(30,2+X);printf("3");}	
		else if(popcorn.tao=='0')
		{gotoxy(30,2+X);printf("*");}
		
popcorn.processing--;

	if(popcorn.processing==0){
		popcorn.availability=true;
		if(popcorn.tao=='1')
			{c1.free=true;
			 c1.pfin=true;}
		else if(popcorn.tao=='2')
			{c2.free=true;
			 c2.pfin=true;}
		else if(popcorn.tao=='3')
			{c3.free=true;
			 c3.pfin=true;}
		popcorn.tao='0';
		popcorn.queue.size--;
	}
}//popcorn
void antiLoop(){
	if(c1.popcorn==0)
		c1.pfin=true;
	if(c1.soda==0)
		c1.sfin=true;
	if(c1.hotdog==0)
		c1.hfin=true;
		
	if(c2.popcorn==0)
		c2.pfin=true;
	if(c2.soda==0)
		c2.sfin=true;
	if(c2.hotdog==0)
		c2.hfin=true;
	
	if(c3.popcorn==0)
		c3.pfin=true;
	if(c3.soda==0)
		c3.sfin=true;
	if(c3.hotdog==0)
		c3.hfin=true;
}

void SODA(){
	if(soda.availability==true&&soda.queue.size!=0)
	{
		soda.processing=soda.queue.array[soda.queue.front];
		soda.tao=soda.queue.array2[soda.queue.front];
		soda.queue.front++;
		soda.availability=false;		
	}
	
		if(soda.tao=='1')
			{gotoxy(38,2+X);printf("1");}
		else if(soda.tao=='2')
			{gotoxy(38,2+X);printf("2");}
		else if(soda.tao=='3')
			{gotoxy(38,2+X);printf("3");}
		else 
			{gotoxy(38,2+X);printf("*");}

soda.processing--;

	if(soda.processing==0){
		soda.availability=true;
		if(soda.tao=='1')
			{c1.free=true;c1.sfin=true;}
		else if(soda.tao=='2')
			{c2.free=true;c2.sfin=true;}
		else if(soda.tao=='3')
			{c3.free=true;c3.sfin=true;}
		soda.tao='0';
		soda.queue.size--;
	}
}

void HOTDOG(){
	if(hotdog.availability==true&&hotdog.queue.size!=0)
	{
		hotdog.processing=hotdog.queue.array[hotdog.queue.front];
		hotdog.tao=hotdog.queue.array2[hotdog.queue.front];
		hotdog.queue.front++;
		hotdog.availability=false;		
	}
	
		if(hotdog.tao=='1')
			{gotoxy(46,2+X);printf("1");}
		else if(hotdog.tao=='2')
			{gotoxy(46,2+X);printf("2");}
		else if(hotdog.tao=='3')
			{gotoxy(46,2+X);printf("3");}
		else if(hotdog.tao=='0')
			{gotoxy(46,2+X);printf("*");}

hotdog.processing--;

	if(hotdog.processing==0){
		hotdog.availability=true;
		if(hotdog.tao=='1')
			{c1.free=true;c1.hfin=true;}
		else if(hotdog.tao=='2')
			{c2.free=true;c2.hfin=true;}
		else if(hotdog.tao=='3')
			{c3.free=true;c3.hfin=true;}
		hotdog.tao='0';
		hotdog.queue.size--;
				}
}

void finishChecker(){
	if(c1.hfin==true&&c1.pfin==true&&c1.sfin==true)	
		{c1.finish=true;}
		
	if(c2.hfin==true&&c2.pfin==true&&c2.sfin==true)
		{c2.finish=true;}
		
	if(c3.hfin==true&&c3.pfin==true&&c3.sfin==true)
		{c3.finish=true;}
}

void PrintScan(){
printf("\t\t\t    --INPUT QUANTITY--\n");
printf("\t\t\t   popcorn   soda  hotdog");
printf("\n  Customer1");printf("\n    Popcorn:");scanf("%d",&c1.p);printf("    Soda:");scanf("%d",&c1.s);printf("    Hotdog:");scanf("%d",&c1.h);
printf("\n  Customer2");printf("\n    Popcorn:");scanf("%d",&c2.p);printf("    Soda:");scanf("%d",&c2.s);printf("    Hotdog:");scanf("%d",&c2.h);
printf("\n  Customer3");printf("\n    Popcorn:");scanf("%d",&c3.p);printf("    Soda:");scanf("%d",&c3.s);printf("    Hotdog:");scanf("%d",&c3.h);	
c1.popcorn=c1.p*pServe;c1.soda=c1.s*sServe;c1.hotdog=c1.h*hServe;
c2.popcorn=c2.p*pServe;c2.soda=c2.s*sServe;c2.hotdog=c2.h*hServe;
c3.popcorn=c3.p*pServe;c3.soda=c3.s*sServe;c3.hotdog=c3.h*hServe;
}

void initialization(){
	TIME=0;a=0;b=0;c=0;
	
	popcorn.queue.back=0;
	popcorn.queue.front=0;
	popcorn.queue.size=0;
	soda.queue.back=0;
	soda.queue.front=0;
	soda.queue.size=0;
	hotdog.queue.back=0;
	hotdog.queue.front=0;
	hotdog.queue.size=0;
	popcorn.queue.fresh=false;
	soda.queue.fresh=false;
	hotdog.queue.fresh=false;
	X=0;
	popcorn.tao='0';
	soda.tao='0';
	hotdog.tao='0';

	c1.pfin=false;
	c1.sfin=false;
	c1.hfin=false;
	c1.finish=false;
	c1.free=true;
	
	c2.pfin=false;
	c2.sfin=false;
	c2.hfin=false;
	c2.finish=false;
	c2.free=true;
	
	c3.pfin=false;
	c3.sfin=false;
	c3.hfin=false;
	c3.finish=false;
	c3.free=true;
	
	popcorn.availability=true;
	popcorn.empty=true;
	soda.availability=true;
	soda.empty=true;
	hotdog.availability=true;
	hotdog.empty=true;
for(int i=0;i<MAX;i++)
	{
		popcorn.queue.array[i]=0;
		popcorn.queue.array2[i]='\0';
		soda.queue.array[i]=0;
		soda.queue.array2[i]='\0';
		hotdog.queue.array[i]=0;
		hotdog.queue.array2[i]='\0';
	}
}

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
