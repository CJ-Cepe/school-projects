#include<stdio.h>
#include<conio.h>
void main(){clrscr();
int first,second,i=0,A[10],B[10],C[10],D[10],TA=0,TB=0,TC=0,TD=0,iTOTAL,n=0;
char ans='y',H1,H2;
char title[25];
float fTOTAL;
printf("\t\tinput data\n");
FILE *sfile;
sfile=fopen("c:mayor.txt","w");
while(ans=='y'||ans=='Y'){
printf("precint %d",i+1);
printf("\n\tVotes for candidate A: ");
scanf("%d",&A[i]);
printf("\n\tVotes for candidate B: ");
scanf("%d",&B[i]);
printf("\n\tVotes for candidate C: ");
scanf("%d",&C[i]);
printf("\n\tVotes for candidate D: ");
scanf("%d",&D[i]);


fprintf(sfile,"\nprecint %d\n %d %d %d %d",i,A[i],B[i],C[i],D[i]);


printf("\n\tInput another precint results?:");
scanf(" %c",&ans);
i++;
n++;
}
fclose(sfile);
sfile=fopen("c:mayor.txt","r");
printf("\n        CANDIDATE CANDIDATE CANDIDATE CANDIDATE\n");
printf("PRECINT     A         B         C         D\n");
printf("--------------------------------------------------\n");
i=0;
while(fscanf(sfile," %s %d %d %d %d %d",title, &i,&A[i],&B[i],&C[i],&D[i])!=EOF)
{
printf("  %d         %d          %d        %d         %d\n",i+1,A[i],B[i],C[i],D[i]);
TA+=A[i];TB+=B[i];TC+=C[i];TD+=D[i];
i++;
}
iTOTAL=TA+TB+TC+TD;
fTOTAL=iTOTAL*0.50f;
fclose(sfile);


	if(fTOTAL==TA||fTOTAL<TA)
		printf("\nCandidate A is the winner");
	else if(fTOTAL==TB||fTOTAL<TB)
		printf("\nCandidate B is the winner");
	else if(fTOTAL==TC||fTOTAL<TC)
		printf("\nCandidate C is the winner");
	else if(fTOTAL==TD||fTOTAL<TD)
		printf("\nCandidate D is the winner");
	else   {
	       if(TA>TB && TA>TC && TA>TD)
		       {//printf("\nCandidate A is the winner");
			first=TA;
			H1='A';}
	       else if(TB>TA && TB>TC && TB>TD)
		       {//printf("\nCandidate B is the winner");
			first=TB;
			H1='B';}
	       else if(TC>TA && TC>TB && TC>TD)
			{//printf("\nCandidate C is the winner");
			H1='C';
			first=TC;}
	       else if(TD>TB && TD>TC && TD>TA)
			{//printf("\nCandidate D is the winner");
			first=TD;
			H1='D';}
if ( first<TA )
	{ second=first;
	  first = TA;
	  H2=H1;
	  H1='A';}
if ( first < TB)
	    { second=first;
	      first=TB;
	      H2=H1;
	      H1='B';}
if ( first < TC)
	      {	second=first;
	      first=TC;
	      H2=H1;
	      H1='C'; }
if ( first < TD)
	      {	second=first;
	      first=TD;
	      H2=H1;
	      H1='D'; }

printf("\nshould have been a standout between %c and %c",H2,H1);
	     }

printf("\nTOTAL       %d          %d        %d         %d",TA,TB,TC,TD);

getch();
}