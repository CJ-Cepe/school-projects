# include <stdio.h>
# include <string.h> 
#define TOTAL 26
// d pa tapos paayos output!!!!!
int search(char Inorder[TOTAL], char Parent, int n){
	
	for(int i=0;i<n;i++){
		if(Inorder[i]==Parent)
			return i;
	}
			return -1;
}

int Postorder(char Inorder[TOTAL],char Preorder[TOTAL],int n){
	int ROOT = search(Inorder,Preorder[0],n);
	
    if (ROOT != 0) {
        Postorder(Inorder, Preorder + 1, ROOT); 
    }
    if (ROOT != n - 1){
        Postorder(Inorder + ROOT + 1, Preorder + ROOT + 1, n - ROOT - 1); 
	}
		
		printf("%c",Preorder[0]);
	}
	
 


int action(char Inorder[TOTAL],char Preorder[TOTAL]){
	int n = sizeof(Inorder)/sizeof(Inorder[0]);
	printf("\nInorder: %s", Inorder);
	printf("\t\tPreorder: %s", Preorder);
	printf("\t\tPostorder:");
	Postorder(Inorder,Preorder,n);
}


int main(){
	char Inorder[TOTAL];
	char Preorder[TOTAL];
  FILE *fptr;
  fptr = fopen ("mp8input01.txt", "r");  
  if (fptr==NULL){
  	printf("file not be found!");
  }	
	while ( fscanf (fptr, "%s %s",Preorder,Inorder) !=EOF){
		action(Inorder,Preorder);
	
	}
        
	 fclose(fptr);
}//main

