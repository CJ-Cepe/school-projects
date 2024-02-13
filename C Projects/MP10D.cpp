#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100

int main(){
	 FILE *fptr;// read FILE*****************************************
 	 fptr = fopen("MP10sorted.txt","r");
 	 if(fptr == NULL)
             {printf("Error!");exit(1);}
	
	 FILE *sptr;// read FILE*****************************************
 	 sptr = fopen("MP10Transaction.txt","r");
 	 if(sptr == NULL)
             {printf("Error!");exit(1);}
             
	FILE *aptr;// read FILE*****************************************
 	 aptr = fopen("Audit.txt","w");
 	 if(aptr == NULL)
             {printf("Error!");exit(1);}
             
	char tempCode,ans='Y',code,code2;
	char partNum[10],partDesc[26],temp[MAX],temp2[MAX],Error[MAX];
	char part_Number[10];
	float partPrice;
	int allower=0,a=0;
while (fgets(temp, sizeof(temp), sptr)){
		for(int z=0;z<10;z++)
			partNum[z]='\0';
		
	//	for(int z=0;z<26;z++)
	//		partDesc[z]='\0';
		
	//	for(int z=0;z<30;z++)
	//		Part_Price[z]='\0';
		
		
		int j = strlen(temp);
		j--;
		
	if(j==1){
		code = temp[0];allower++;
		printf("%c\n",code);
	}
	else{
		int i=0;
		while(temp[i]!=' '){  //getting part number
		partNum[i]=temp[i];
		i++;
		}puts(partNum);allower++;
	}//else
		
	if (allower==2)
		{
			if(code=='A'){
				while (fgets(temp2, sizeof(temp2), fptr)){
						//getting part number
					int k=0;
					while(temp2[k]!=' '){
			        part_Number[k]=temp2[k];
		         	k++;
							}
					//if(strcompare)
					if(strccmp(partNum,part_Numer)==0){
						ERROR = "INVALID ADD–ALREADY ON MASTER";
						printf("\nINVALID ADD–ALREADY ON MASTER");
						a++;
					}
						for(int z=0;z<10;z++)
							part_Number[z]='\0';
				}
				if(a!=0){
					
						fprintf(fptr,"%s %s %.2f\n", partNum,partDesc,partPrice);

				}
			}//if(code=='A')
		}//if (allower==2)


	}//while
}
