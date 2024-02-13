#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){
	 FILE *fptr;// CREATING FILE*****************************************
 	 fptr = fopen("MP10Transaction.txt","w");
 	 if(fptr == NULL)
             {printf("Error!");exit(1);}
			  
	char tempCode,ans='Y',code,code2;
	char partNum[10],partDesc[26];
	float partPrice;
printf("\n\t\t\tM P 1 0 C  T R A N S A C T I O N\n\n");
while(toupper(ans)=='Y'){
	fflush(stdin);
	printf("\t\tUpdate Code:   ");
	scanf("%c",&tempCode);
	code=toupper(tempCode);
if(code=='A')
{			fflush(stdin);
			printf("\n\t\tPart Number: ");
			gets(partNum);
			printf("\n\t\tPart Description:");
			gets(partDesc);
			printf("\n\t\tPart Price:");
			scanf("%f", &partPrice);	
	fprintf(fptr,"%c\n", code);
	fprintf(fptr,"%s %s %.2f\n", partNum,partDesc,partPrice);

}//if(code=='A')

else if(code=='C'){
			fflush(stdin);
			printf("\n\t\tPart Number: ");
			gets(partNum);
			printf("\n\t\tChange ID: ");
			scanf(" %c",&code2);
		if(toupper(code2)=='P'){
			fflush(stdin);	
			printf("\n\t\tPart Price: ");
			scanf("%f", &partPrice);		
				fprintf(fptr,"%c\n", code);
				fprintf(fptr,"%s %.2f\n", partNum,partPrice);
			}
		else if(toupper(code2)=='D'){
			fflush(stdin);	
			printf("\n\t\tPart Description: ");
			gets(partDesc);
				fprintf(fptr,"%c\n", code);
				fprintf(fptr,"%s %s\n", partNum,partDesc);			
			}
		else{
			printf("\n\t\t\tInvalid input");
			fflush(stdin);
		}
	
}//else if(code=='B')	
	
else if(code=='D'){
			fflush(stdin);
			printf("\n\t\tPart Number: ");
			gets(partNum);
			fprintf(fptr,"%c\n", code);
			fprintf(fptr,"%s\n", partNum);
			fflush(stdin);
}//else if(code=='D')
	
else{
	printf("\n\t\t Invalid input");
}	


for(int i = 0; i<10 ; i++)
	partNum[i]='\0';
	
for(int i = 0; i<26 ; i++)
	partDesc[i]='\0';
printf("\n\t\t\t\tAnother (y/n)?: ");scanf(" %c",&ans);	
printf("\n\t\t      --------------------------------------\n");
}//while

fclose(fptr);
printf("\n    All entries saved in MP10Transaction.txt...Press any key to continue....");	
printf("\n\n");

}// main

