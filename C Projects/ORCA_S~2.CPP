#include<stdio.h>

int main(){
    char A,b='A';
    int vote[4];
    int i,f=0;
    int allover=0;
    float total[4]={0,0,0,0};
    float percent[4];
    float great=0.0,greater=0.0;
    FILE *mayor=fopen("vote.txt","w");
    for ( i=1; i<6; i++){
	A='A';
	printf("Precint %d\n",i);
	for (int j=0; j<4; j++){
	    printf("Enter Vote for Cand. %c: ",A++);
	scanf(" %d",&vote[j]);
	    total[j]+=vote[j];
	}allover=total[0]+total[1]+total[2]+total[3];

	fprintf(mayor,"%d\t\t%d\t%d\t%d\t%d\n",i,vote[0],vote[1],vote[2],vote[3]);
    }fclose(mayor);
    mayor =fopen("vote.txt","r");
    printf("\nPrecint\t\tA\tB\tC\tD\n");
    while (fscanf(mayor,"%d%d%d%d%d",&i,&vote[0],&vote[1],&vote[2],&vote[3])!=EOF){
	printf("%d\t\t%d\t%d\t%d\t%d\n",i,vote[0],vote[1],vote[2],vote[3]);
    } printf("Total\t\t%.0f\t%.0f\t%.0f\t%.0f\n",total[0],total[1],total[2],total[3]);
    A='A';
    for (int k=0; k<4; k++){
    percent[k]=(total[k]/allover)*100;
    }
    for (int l=0; l<4; l++){
    if (percent[l]>50 || percent[l]==50){
    printf("The Winner is candidate %c",A);
    f=1;
    }A++;
    }
     if (f==0){

    for (int q=0; q<4; q++){
	if (percent[q]>greater){
	greater=percent[q];
	}else if (percent[q]>great)
	great=percent[q];
    }

   printf("Run-Off Between \n");
   A='A';
   for (int m=0; m<4; m++){
   if (percent[m]>greater || percent[m]==greater || percent[m]==great)
   printf("Candidate %c\n",A);
   A++;
   }
     }
   printf(" %c\n",&b);
   b++;
   printf(" %c\n",&b);
    getch();
    return 0;
}