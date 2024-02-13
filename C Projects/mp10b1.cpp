#include <stdio.h>
#include <string.h>
#define MAX 100
#include <windows.h>
#include <time.h>
#include <process.h>



int main(){
	char newFileName[50];
FILE *Sptr;
Sptr = fopen("MP10sorted.txt","r");
	if(Sptr == NULL)
            {printf("Error! file name");exit(1);} 
printf("\n\t\t\t    (file extension not required)");            
printf("\n    Input desired FileName: ");
gets(newFileName);
strcat(newFileName,".txt");           
            
            
FILE *fptr;
fptr = fopen(newFileName,"w");
	if(fptr == NULL)
            {printf("Error!");exit(1);} 


char temp[MAX],Part_Number[10],Part_Description[26],Part_Price[30];
fprintf(fptr,"\n\t3 - File");
fprintf(fptr,"\n\n\t\t\t\t  XYZ Company");
//---------------------------time in screen
time_t rawtime;
struct tm * timeinfo;

time ( &rawtime );
 timeinfo = localtime ( &rawtime );
 fprintf(fptr,"\n\n\t\t\t\tProduct Listing");
	fprintf(fptr,"\n\n\tPart Number\t\t Description\t\tPrice\n");

//--------------------------------------

	
while (fgets(temp, sizeof(temp), Sptr)){
		for(int z=0;z<10;z++){
			Part_Number[z]='\0';}

		for(int z=0;z<26;z++){
			Part_Description[z]='\0';}
		
		for(int z=0;z<30;z++){
			Part_Price[z]='\0';}
			
		int j = strlen(temp); j--;	
	//getting part number
		int i=0,k=0;
	
		while(temp[i]!=' '){
			Part_Number[i]=temp[i];
			i++;
		}
	
		i++;/// to set to Part description
		
	//getting part price		
		while(temp[j]!=' '){
		   j--;}
		  int end=j;
		  int start=i;
		   j++;
		while(temp[j]!='\0'){
			Part_Price[k]=temp[j];
			k++;j++;
		}
float Part_Price_Final=atof(Part_Price);

	int x=0;
	//getting part description		
		while(start!=end){
			Part_Description[x]=temp[start];
			start++;x++;
		}fflush(stdin);
fprintf(fptr,"\n");	
fprintf(fptr,"\t  %s\t\t%s\t\t %.02f",Part_Number,Part_Description,Part_Price_Final);
 //fprintf(fptr,"\n\n\t\t\t\t\t\t Date: %02d/%02d/%02d", timeinfo->tm_mday, timeinfo->tm_mon+1, 
   // timeinfo->tm_year+1900);
}
	 fclose(fptr);
	 fclose(Sptr);
	 	 printf(" \n\n\t\t\t  File saved in %s",newFileName);
	 getchar();
	 
	 
	 return 0;
}
