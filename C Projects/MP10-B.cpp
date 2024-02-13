




#include <stdio.h>
#include <string.h>
#define MAX 100
#include <windows.h>
#include <time.h>

int Screen(char FileName[]);
int Print(char FileName[]);
int File(char FileName[]);

int main(){
	char FileName[20],choice,ans='Y';
while(toupper(ans)=='Y'){
	fflush(stdin);
	system("cls");
	printf("\n\t\t        M P10 C  -   P r i n t   I t !"); 
	printf("\n\n\t\t\t     (file extension not included)");
	printf("\n\t   INPUT File Name: ");
	gets(FileName);
	strcat(FileName,".txt");
	printf("\n\n\t\t      (1).Screen   (2).Print  (3).File");
	printf("\n\t   Enter choice: ");
	scanf(" %c",&choice);
switch(choice)
	{ case '1':
		system("cls");
	  Screen(FileName);
	  break;
	  
	  case '2':
	  	system("cls");
	  	 Print(FileName);
	  	break;
	  case '3':
	  	system("cls");
	  		File(FileName);
	  		break;
	  default:
            printf("\n\n\t\t   Error! Operator or File Name is not correct");
	}
		
for(int z=0;z<20;z++)
  FileName[z]='\0';

  printf("\n\n\n\n\n\t\t\t\tAgain(y/n)?: ");
  scanf(" %c",&ans);
}//while

}

int Screen(char FileName[]){fflush(stdin);
FILE *fptr;
fptr = fopen("MP10sorted.txt","r");
	if(fptr == NULL)
            {printf("Error! file name");exit(1);} 
char temp[MAX],Part_Number[10],Part_Description[26],Part_Price[30];
printf("\n\t1 - Screen");
printf("\n\n\t\t\t\t  XYZ Company");
//---------------------------time in screen
time_t rawtime;
struct tm * timeinfo;
time ( &rawtime );
 timeinfo = localtime ( &rawtime );
 //printf ( "%s", asctime (timeinfo) );
 printf("\n\n\t\t\t\t\t\tDate: %02d/%02d/%02d", timeinfo->tm_mday, timeinfo->tm_mon+1, 
    timeinfo->tm_year+1900);
   printf("\n\t\t\t\t\t\tTime: %02d:%02d.%02d", timeinfo->tm_hour, timeinfo->tm_min, 
    timeinfo->tm_sec);
	printf("\n\n\tPart Number\t\t  Description\t\t\tPrice\n");
//--------------------------------------
while (fgets(temp, sizeof(temp), fptr)){
		for(int z=0;z<10;z++)
			Part_Number[z]='\0';

		for(int z=0;z<26;z++)
			Part_Description[z]='\0';
		
		for(int z=0;z<30;z++)
			Part_Price[z]='\0';
			
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
		}
printf("\n");		
printf("\t  %s\t\t%s\t\t\t %.02f",Part_Number,Part_Description,Part_Price_Final);
}
		fflush(stdin);
	 	fclose(fptr);
	 	 getchar(); 
	 return 0;
}

int Print(char FileName[]){fflush(stdin);
FILE *Sptr;
Sptr = fopen(FileName,"r");
	if(Sptr == NULL)
            {printf("Error! file name");exit(1);} 
FILE *fptr;
fptr = fopen("MP10Bprint.txt","w");
	if(fptr == NULL)
            {printf("Error!");exit(1);} 


char temp[MAX],Part_Number[10],Part_Description[26],Part_Price[30];
fprintf(fptr,"\n\t2 - Print");
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
 fprintf(fptr,"\n\n\t\t\t\t\t\t Date: %02d/%02d/%02d", timeinfo->tm_mday, timeinfo->tm_mon+1, 
    timeinfo->tm_year+1900);
}
	 fclose(fptr);
	 fclose(Sptr);
	 printf("\nPress any key to print the file...\n\n");
	 getchar();
	 system("notepad /p MP10Bprint.txt");
	 printf("Printing....");
	 getchar();
	 return 0;
}



int File(char FileName[]){fflush(stdin);
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
