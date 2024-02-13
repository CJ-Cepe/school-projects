#include<conio.h>
#include<Stdio.h>
void main(){
//**********Variable***********
int Z=0,M,P=1,S=1,H=1,C1F=0,C2F=0,C3F=0,Q=0;
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
	C1.T[i]*M;C2.T[i]*M;C3.T[i]*M;
}
for(i=0;Z=3;i++){
	if(C1.T[0]!=0){C1.T[0]--;}
	C1F++;
		if(C1.T[0]==0&&Q==0){
			P=0;Q++;}
			if(C1.T[0]==0&&S==0&&Q>0){
				C1.T[1]--;
				if(C1.T[1==0]){
					S=1;
					if(C1.T[1==0]&&H==1){
						C1.T[2]--;
							if(C1.T[2]==0){
								printf("\nTotal Minutes of customer 1: %d",C1F);
									Z++;
	}}}}
	if(C2.T[1]!=0){C2.T[1]--;}
	C2F++;
		if(C2.T[1]==0&&W==0){
			S=0;W++;}
			if(C2.T[1]==0&&H==0&&W>0){
				C2.T[2]--;
				if(C2.T[2]==0){
					H=1;
					if(C2.T[2]==0&&P=1){
						C2.T[0]--;
						if(C2.T[0]==0){
							printf("\nTotal Minutes of customer 2: %d",C2F);
							Z++;
		} } }  }	
	if(C3.T[2]!=0){C3.T[2]--;}
	C3F++;
		if(C2.T[2]==0&&E==0){
			H=0;E++;}
			if(C2.T[2]==0&&P==0&&E>0){
				C2.T[0]--;
				if(C2.T[0]==0){
					P=1;
					if(C2.T[0]==0&&S==1){
						C2.T[1]--;
						if(C2.T[1]==0){
							printf("\nTotal Minutes of customer 3: %d",C3F);
							Z++;
		} } }  }	
}						
}
