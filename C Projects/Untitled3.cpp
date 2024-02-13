#include<conio.h>
#include<Stdio.h>
void main(){
//**********Variable***********
int P=1,S=1,H=1;
struct Q{
	int Q[3];
	int T[3];
};
//***************GATHERING DATA****************
struct Q C1,C2,C3;
printf("\t| POPCORN| SODA | HOTDOG |")
scanf("Customer1: %d %d %d",C1.Q[0],C1.Q[1],C1.Q[2]);
scanf("Customer2: %d %d %d",C2.Q[0],C2.Q[1],C2.Q[2]);
scanf("Customer3: %d %d %d",C3.Q[0],C3.Q[1],C3.Q[2]);
//************SOLUTION 1***************** 
for(int i=0;i<3;i++){
	if(i==0)//popcorn
		M=1;
	else if(i==1)//soda
		M=2;
	else//hotdog
		M=4;
	C1.T[i]=C1.Q[i]*M;C2.T[i]=C2.Q[i]*M;C3.T[i]=C3.Q[i]*M;
}
for(i=0;i<)
if(C1.T[0]!=0){C1.T[0]--;}
else if(C1.T[0]==0){C1++;P=0;}


if(C2.T[1]!=0){C2.T[1]--;}
else if(C2.T[1]==0){C2++;S=0;}

if(C3.T[2]!=0){C3.T[2]--;}
else if(C3.T[2]==0){C3++;H=0;}



