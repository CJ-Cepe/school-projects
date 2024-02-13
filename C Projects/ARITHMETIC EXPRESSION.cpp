/*Data structures
  Evaluation of Arithmetic expressions
  bscs 2-1
  7/27/2019
  Galindez, Christopher Elijah.
  Cepe,Carl Joseph R.
*/



#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 10
int priority(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

char Stack1[MAX];
int Top=-1,element=0;
push(char data){
	element++;
	Top++;
	Stack1[Top]=data;

}  

int pop(){
	Top--;
	element--;
}

int main(){char ans='Y';

while(toupper(ans)=='Y'){
system("CLS");

char INFIX[MAX],RPN[MAX];
printf("\n\n\t\tA R I T H M E T I C   E X P R E S S I O N ");
printf("\n\n\n\t\t   I N P U T");
printf("\n\n\t\t\tinfix: ");
gets(INFIX);
//scanf("%s",&INFIX);
int i=0,j=0;

while(INFIX[i]!=NULL){
	
	if(INFIX[i]=='(')
		{
		push(INFIX[i]);
		}
	else if(INFIX[i]==')')
		{
		while(Stack1[Top]!='(')//
			{RPN[j]=Stack1[Top];
			pop();
			j++;}
		if(Stack1[Top]=='(')
			{
			pop();
			}
		}
	else if(isdigit(INFIX[i]))
		{
		RPN[j]=INFIX[i];j++;
		}
	else if(INFIX[i]=='*'||INFIX[i]=='+'||INFIX[i]=='-'||INFIX[i]=='/'||INFIX[i]=='^')
		{
		while(element!=0&&priority(INFIX[i])<=priority(Stack1[Top]))
		{
		RPN[j]=Stack1[Top];pop();j++;
		}
		push(INFIX[i]);}

	else if(isblank(INFIX[i])){
			}
i++;
}
while(element!=0){
	RPN[j]=Stack1[Top];j++;pop();
}
printf("\n\n\t\t   O U T P U T\n\n\t\t      postfix: ");puts(RPN);
//evaluating 
char Stack2[MAX],token;
int element2=0,A,B,C;i=0;Top=-1;
while(RPN[i]!=NULL){
	token=RPN[i];
		if(isdigit(token)){
			Top++;Stack2[Top]=token;element2++;}
		else if(token=='*'||token=='+'||token=='-'||token=='/'||token=='^'){
			B=(Stack2[Top]-'0');Top--;element2--;
			A=(Stack2[Top]-'0');Top--;element2--;
			switch(token){
				case '+': {Top++;Stack2[Top]=(A+B)+'0';break;} 
					case '-': {Top++;Stack2[Top]=(A-B)+'0';element2++;break;}
						case '*': {Top++;Stack2[Top]=(A*B)+'0';element2++;break;}
							case '/': {Top++;Stack2[Top]=(A/B)+'0';element2++;break;}
								case '^': {Top++;Stack2[Top]=(pow(A,B)+'0');element2++;break;}
			}
		}
i++;
}//whiles
printf("\n\t\t       Answer: %d",Stack2[Top]-'0');
printf("\n\n\n\n\t\t\t\tAgain(y/n)?:");
scanf(" %c",&ans);    
for(int z=0;z<MAX;z++){
INFIX[z]='\0';RPN[z]='\0';Stack1[z]='\0';Stack2[z]='\0';}// for clearing char arrays
fflush(stdin);
}//while
printf("\n\n");
}//main
