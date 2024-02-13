/*Data structures
  Addition with Linked List
  bscs 2-1
  8/22/2019
  Galindez, Christopher Elijah.
  Cepe,Carl Joseph R.
*/

#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include <cctype>

int  l=0,fn,sn,differ,z=0;
struct node
{
	int  num;
	struct node*next;
	struct node*prev;
};
struct node*numb1 =NULL;
struct node*core1 =NULL;
struct node*last1 =NULL;
struct node*numb2 =NULL;
struct node*core2 =NULL;
struct node*last2 =NULL;
struct node*numb3 =NULL;
struct node*core3 =NULL;
struct node*last3 =NULL;

int main ()
{
char ans='Y';
while(toupper(ans)=='Y'){system("CLS");
printf("\n\t      A D D I T I O N   W I T H   L I N K E D  L I S T");
int answer,sum={0};
int  result[100]={0};
char nmb1[100]={0},nmb2[100]={0};	
core1=(struct node*)malloc(sizeof(struct node)); 
printf("\n\n\n\t\ti n p u t");
printf ("\n\n\t\t\tfirst number: ");
scanf ("%s",&nmb1);
char tem1 [2] = {'\0', '\0'};
fn=strlen(nmb1);
//printf ("%d\n",fn);
int* arr1 = (int*) malloc (sizeof (int) * fn);
	for ( int i = fn-1, j = 0; i >= 0; --i)
    {
    	if ( isdigit (nmb1[i] ) )
        	{
            	tem1 [0] = nmb1 [i] ;
            	arr1 [j++] = atoi (tem1) ;
        	}
	}			
core1->num=arr1[0];
core1->next=NULL;
numb1=core1;
last1=numb1;	
	for (int  i=1;i<fn;i++)
	{
		core1=(struct node*)malloc(sizeof(struct node));
		core1->num=arr1[i];
		core1->next=NULL;
		last1->next=core1;
		last1=last1->next;			
	}
core1=numb1;
core2=(struct node*)malloc(sizeof(struct node));
printf ("\n\t\t\tsecond number: ");
scanf ("%s",&nmb2);
char tem2 [2] = {'\0', '\0'};
sn=strlen(nmb2);
//printf ("%d\n",sn);
int* arr2 = (int*) malloc (sizeof (int) * sn);
	for (int i = sn-1, j = 0; i >= 0; --i)
    {
        if ( isdigit (nmb2[i] ) )
        {
            tem2 [0] = nmb2 [i] ;
            arr2 [j++] = atoi (tem2) ;
        }
	}
core2->num=arr2[0];
core2->next=NULL;
numb2=core2;
last2=numb2;
	for (int  i=1;i<sn;i++)
	{
		core2=(struct node*)malloc(sizeof(struct node));
		core2->num=arr2[i];
		core2->next=NULL;
		last2->next=core2;
		last2=last2->next;			
	}
core2=numb2;
	if (fn>sn)
	{
		differ=fn-sn;
		l=fn;
	for (int  i=0;i<differ;i++)
		{
			core2=(struct node*)malloc(sizeof(struct node));
			core2->num=z;
			core2->next=NULL;
			last2->next=core2;
			last2=last2->next;			
		}
		core2=numb2;
	}
	else
	{
		differ=sn-fn;
		l=sn;
		for (int  i=0;i<differ;i++)
		{
			core1=(struct node*)malloc(sizeof(struct node));
			core1->num=z;
			core1->next=NULL;
			last1->next=core1;
			last1=last1->next;			
		}
		core1=numb1;
	}	
int  a=0;
	for (int i=0;i<l;i++)
	{		
		long long int resu =a+core1->num+core2->num;
		if (resu>=10)
		{
			a = 1;
			resu  = resu % 10;
		}
		else
			a=0;
		if (i==0)
		{
			core3=(struct node*)malloc(sizeof(struct node));
			core3->num= resu;
			core3->next=NULL;
			core3->prev=NULL;
			numb3=core3;
			last3=numb3;
		}
		else
		{
			core3=(struct node*)malloc(sizeof(struct node));
			core3->num=resu;
			core3->prev=last3;
			core3->next=NULL;
			last3->next=core3;
			last3=last3->next;			
		}
		core1=core1->next;
		core2=core2->next;
	}
	if (a==1)
	{
		core3=(struct node*)malloc(sizeof(struct node));
		core3->num=a;
		core3->prev=last3;
		core3->next=NULL;
		last3->next=core3;
		last3=last3->next;
	}
	core3=numb3;
	struct node*tempo;
	tempo=last3;
	printf("\n\n\n\t\to u t p u t");
	printf ("\n\n\t\t\tanswer: ");
	while(tempo!=NULL)
	{
		printf("%d",tempo->num);
		tempo=tempo->prev;
	}
printf("\n\n\n\t\t\t     AGAIN(y/n)?: ");scanf(" %c",&ans);
}//while
}


