#include<stdio.h>
#include<conio.h>

bool solution(int N,int board[*][*],int column);
bool safe(int N,int board[*][*],int row,int column)


int N;
int main(){
int n;
printf("Input N: ");
scanf("%d",&n);
N=n;
int board[N][N]={0};
////////////////////////////////////////////////////////////////////
if (solution(N,board, 0) == false) { 
        printf("Solution does not exist"); 
          } 
          
for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n");
}
}

bool solution(int N,int board[N][N],int column){
	if(N<=column)
		return true;
	for(int i=0;i<N;i++){
		if(safe(board,i,column)){
		 		board[i][column]=1;
			if(solution(board,column+1))
				return true;
			board[i][column]=0;
		}
	}
return false;
}

bool safe(int N,int board[N][N],int row,int column){
	int i,j;
	for(i=0;i<column;i++){
		if(board[row][i])
		return false;
	}
	for(i=row,j=column;i>=0&&j>=0;i--,j--){
		if(board[i][j])
			return false;
	}
	for(i=row,j=column;j>=0&&i<N;i++,j--){
		if(board[i][j])
			return false;
	}
return true;
}
