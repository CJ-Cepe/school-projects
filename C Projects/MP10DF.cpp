#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<windows.h>
#define MAX 100


int main(){
	char allList[MAX][MAX],numList[MAX][MAX],Temp[MAX],numGetter[MAX];
	int a=0,b=0;
	char Code,delList[MAX][MAX];	
 FILE *Fptr;// reading FILE*****************************************
 Fptr = fopen("MP10unsorted.txt","r");
 if(Fptr == NULL)
             {printf("Error!");exit(1);} 
 FILE *Sptr;// reading FILE*****************************************
 Sptr = fopen("MP10Transaction.txt","r");
 if(Sptr == NULL)
             {printf("Error!");exit(1);} 
 //reading fptr-------getting list----------------------------------            
 while (fgets(Temp, sizeof(Temp), Fptr)) {
 	strcpy(allList[a],Temp);	
	int q=0;
	while(Temp[q]!=' '){
	numGetter[q]=Temp[q];
		q++;
		}
	strcpy(numList[a],numGetter);
 	a++;

for(int z=0;z<MAX;z++){
numGetter[z] = '\0';
Temp[z]= '\0';
	}	 	
}           
//-----------------------------------------------------------------
 while (fgets(Temp, sizeof(Temp), Sptr)){
 	int J=strlen(Temp);
 	J--;
 	
 	if(J==1){
 		Code=Temp[0];
	 }
 	else if(J!=1){
 			int q=0;
 		while(Temp[q]!=' '){
			numGetter[q]=Temp[q];
			q++;
			}
			
			if(Code=='A'){
				for(int z=0;z<a;z++){
					int M=strcmp(numGetter,numList[z]);
					if(M==0){
						printf("INVALID ADD–ALREADY ON MASTER");
						goto Aend;
					} 
				}
				if(M!=0){
					strcpy(allList[a],Temp);
					//print temp on file special that q++ temp[q] 
				//		char Atemp[MAX];
				//		for(int z=0;z<MAX;z++){
				//			Atemp[z]='\0';
					//	} 
					//	int k=0;
					// while(temp[q]!='\0')
					//	{
					//		Atemp[k] = temp[q];
					//		k++;q++;
					//	}
					
					a++;}
				Aend:
			}//A
 		
 			else if(Code=='C'){int Cenabler =0;
 				for(int z=0;z<a;z++){
				 int N =strcmp(numGetter,numList[z]);
				 if(N==0){
				 	Cenabler = 1;        //
				 }
			}
				 if(Cenabler !=1){
				 	printf("INVALID CHANGE–NOT ON MASTER");
				 	goto Cend;
				 }
				 
				 else if(Cenabler ==1){
				 	//print temp and get Number on file
				 	// %s %s numGetter,temp
				 }
 			Cend:	
			 }//C
	 
	 		else if(Code=='D'){int Denabler =0;
	 			for(int z=0;z<a;z++){
				 int o =strcmp(numGetter,numList[z]);
				 if(o==0){
				 	Denabler = 1;        //
				 }
			}
	 			if(Denabler== 0){
	 				printf("INVALID CHANGE–NOT ON MASTER");	 				
				 }
	 			else if(Denabler==1){
	 				strcpy(delList[b],numGetter);
				 }
			 }
	 
	 }//else
 			
for(int z=0;z<MAX;z++){
numGetter[z] = '\0';
Temp[z]= '\0';
	}	 	
 	
 }//while
	
	
	
	
	
}
