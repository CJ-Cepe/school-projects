/*Cepe, Carl Joseph R.
  Galindez, Christopher Elijah F. 
  
  PATTERN MATCHING
  COMP 20063 Data Structures and Algorithms: BSCS 2-1
  7/7/2019
  DEV-C++
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>//toupper
#include<stdlib.h>//system color

int KMP(char* PATTERN, char* TXT);
int computeLPS(char* PATTERM, int A, int* lps);

int main(){
char ans='Y';
while(toupper(ans)=='Y'){system("cls");
	//ENTERING FILENAME AND DISPLAYING CONTENT
	char FNAME[30],TXT[50];
	system("COLOR F0");
	printf("---------------------------------------------------------------\n\n");
	printf("*input file name.must include the file extension"); printf("\n --FILE NAME: "); 
	scanf("%s", FNAME); 

	FILE *sfile; sfile=fopen(FNAME,"r");
		if(sfile==NULL)
			{printf(" -file not found-"); goto Q;}
	while(fscanf(sfile,"%s ",&TXT)!=EOF){printf(" > TEXT: %s",TXT);}
	
	//ENTERING PATTERN TO BE SEARCH
	char PATTERN[20];
	printf("\n\n --ENTER PATTERN: ");
	scanf("%s", PATTERN);
	KMP(PATTERN,TXT);
	fclose(sfile);
	Q:
	printf("\n\n --AGAIN(y/n)?: ");
	scanf(" %c", &ans);}
	
return 0;	
}

// PATTERN
int KMP(char* PATTERN, char* TXT)
{ int A=strlen(PATTERN);
  int B=strlen(TXT);
  int lps[A];
  computeLPS(PATTERN, A, lps); 
  int i = 0; // index for TXT
  int j = 0; // index for PATTERN
  int z=0;
    while (i < B) { 
        if (PATTERN[j] == TXT[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == A) { 
            z++;//computes the number of matches
            j = lps[j - 1]; 
        } 
  
        else if (i < B && PATTERN[j] != TXT[i]) { 
            
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    //display the number of matches
    if(z!=0)
		printf(" >TOTAL NUMBER OF MATCHES: %d",z);
	else
		printf(" --No match found--");
}
  
//COMPUTES SUFFIX/PREFIX
int computeLPS(char* PATTERN, int A, int* lps) 
{ 
    int len = 0, i = 1;
    lps[0] = 0; 
     
    while (i < A) { 
        if (PATTERN[i] == PATTERN[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else  
        { 
        
            if (len != 0) { 
                len = lps[len - 1]; 
  
            } 
            else
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 


