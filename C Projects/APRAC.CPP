#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct{
      int in;
      float fl;
      char cr;
      char st[10];
}INFO;
INFO A;
void main(){clrscr();
FILE *sfile;
char ans='n';
sfile=fopen("apple.txt","a+");
	while(toupper(ans)=='Y'){
printf("INTEGER:");
scanf("%d",&A.in);
printf("FLOAT:");
scanf("%f",&A.fl);
printf("CHAR:");
scanf(" %c",&A.cr);
printf("STRING:");
scanf(" %s",A.st);
fprintf(sfile,"%d %f %c %s\n",A.in,A.fl,A.cr,A.st);
printf("continue:");
scanf(" %c",&ans);
}
fclose(sfile);
FILE *tfile;
sfile=fopen("manga.txt","r");
tfile=fopen("apple.txt","w");
while(fscanf(sfile,"%d %f %c %s\n",&A.in,&A.fl,&A.cr,A.st)!=EOF)
{
printf("%d\n",A.in);
printf("%f\n",A.fl);
printf("%c\n",A.cr);
printf("%s\n",A.st);
fprintf(tfile,"%d %f %c %s\n",A.in,A.fl,A.cr,A.st);
}
fclose(sfile);
fclose(tfile);
rename("apple.txt","manga.txt");
getch();
}