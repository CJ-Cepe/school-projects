#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<windows.h>
#define MAX 100


int main(){
	char Part_Number[11],Part_Description[27];
	float Part_Price;
	int c,d,i=0,j=0,k=0; 
  	char ans='Y',KeyList[MAX][11],DataCollection[MAX][MAX];
  	
	
 FILE *fptr;// CREATING FILE*****************************************
 fptr = fopen("MP10unsorted.txt","w");
 if(fptr == NULL)
             {printf("Error!");exit(1);} 
 FILE *Sptr;// CREATING FILE*****************************************
 Sptr = fopen("MP10sorted.txt","w");
             
             
while(toupper(ans)=='Y'){
    system("CLS");    printf("\n\t\t  S e q u e n t i a l    M a s t e r   F i l e\n\n"); 
    printf("\n\t\tEnter Part Number: ");
   	gets(Part_Number);
   	printf("\n\t\tEnter Part Description: ");
   	gets(Part_Description);
	printf("\n\t\tEnter Part price: ");
	scanf("%f",&Part_Price);
	
	for(j=0;j!=i;j++){//comparing ket field if existing
		int test = strcmp(Part_Number,KeyList[j]);
			if(test==0)
				{printf("\n\t\t   Key Number already existing, failed to add");
				goto ask;
				}
	}
	strcpy(KeyList[i],Part_Number);
	i++;
	
	char temp[MAX];
	for(int z=0;z<=MAX;z++){
		temp[z]='\0';
	}
	strcat(temp,Part_Number);
	strcat(temp," ");
	strcat(temp,Part_Description);
	strcat(temp," ");
	char temp2[50];
	sprintf(temp2, "%f", Part_Price);
	strcat(temp,temp2);
	strcpy(DataCollection[k],temp);
	k++;
	//writing in the file
	fprintf(fptr,"%s %s %.2f\n", Part_Number,Part_Description,Part_Price);
	printf("\n\n\t\t\t\tAdd Successful!");
	ask:
	printf("\n\t\t\t  \t again(y/n)?:");scanf(" %c",&ans);//getchar();
	fflush(stdin);
}
   fclose(fptr);
////////////////////////////////////////////////////////////////////////////////////////////  
  // sort_strings(DataCollection, k);
  char temp3[MAX];
   for (c = 0 ; c < k - 1; c++)
  {
    for (d = 0 ; d < k - c - 1; d++)
    {
      if (strcmp(DataCollection[d], DataCollection[d+1]) > 0) /* For decreasing order use < */
      {
        strcpy(temp3,DataCollection[d]);
        strcpy(DataCollection[d],DataCollection[d+1]);
		strcpy(DataCollection[d+1],temp3);
      }
    }
  }
  for (c = 0; c < k; c++){
  		 fputs(DataCollection[c], Sptr);
  		 fprintf(Sptr,"\n");}
  fclose(Sptr);
  
printf("\n\t\t Transactions saved. Press any key to continue...");
printf("\n\n\n");

	return 0;
}


