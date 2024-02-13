/*Data structures
  N's Queen
  bscs 2-1
  8/18/2019
  Galindez, Christopher Elijah.
  Cepe,Carl Joseph R.
*/

#include<stdio.h>
#include<windows.h>
#include<ctype.h>
#define MAX 100

int REYNA(int N);
void push(int element);
int pop();

//global variables
int top=0,size=0,S[MAX]={0};

//*************main**************
int main(){
int N;char ans='Y';
while(toupper(ans)=='Y'){system("CLS");
	
printf("\n\t\t\t     N ' s    Q U E E N ");
	printf("\n\n\t\t\t         INPUT N:");
	scanf("%d",&N);
if(N>3){
    if(N>25||N==24)
    	printf("\n\t\t     large N takes some time to solve\n\t\t       Have a break, Have a KitKat");
	REYNA(N);}
else if(N==1){
	printf("\n\t\t\t      trivial solution\n");
	REYNA(N);
}
else
	printf("\n\n\n\t\t\t\tno solution");
printf("\n\n\n\t\t\t\tagain(y/n)?:");scanf(" %c",&ans);
}//while
}// main


//************REYNA*************
int REYNA(int N){
	bool success=false;
	push(1);
	char board[N][N];
// solution	
while(!success&&top!='\0'){
	int holder=0;bool conflict=false;
	
	for(int i=1;i<size;i++){
		int checkrows=size-i;
		if (S[top]==S[i] || S[top]==S[i]+checkrows || S[top]==S[i]-checkrows) 
	    conflict = true;
	}
	if (conflict){
		while (S[top]==N)
			holder=pop();	
		if (S[top]!= '\0') 
			push(pop()+1);
		else
			push(holder+1);
	    	}
	else if (!conflict && size==N)
		success = true;
	else 
		push(1);
}//while

// initializing every element of 2d array to 0
for(int x=0;x<N;x++)
	for(int z=0;z<N;z++)
		board[x][z]='.';
		
//assigning queen
for(int j=1;j<=top;j++){
	int x=j-1;
	int z=S[j]-1;
	board[x][z]='Q';}
	
//printing
int k=0;printf("\n");
for(int x=0;x<N;x++){
	for(int z=0;z<N;z++){
		printf("%c",board[x][z]);
		k++;
		if(k==N)
			{k=0;printf("\n");}
		}
	}

if(success==true);

else 
	printf("no solution");
fflush(stdout);

// initializing variable to 0 
top=0;size=0;
for(int p=0;p<MAX;p++)
	S[p]=0;
}//REYNA





void push(int element)
{
	top++;size++;
    S[top] = element;
}

int pop()
{
    int x=S[top];
    top--;size--;
    return x;
    
}

