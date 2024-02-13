//CEPE,CARL JOSEPH R.     Computer programming
//BSCS1-1                 binary search single
//january 4,2019
#include<stdio.h>
#include<conio.h>
void main(){
clrscr();
int first=0,target,found,mid,last=5,location;
int list[]={0,1,2,3,4,5};
///print///
printf("input target number:");
scanf("%d",&target);
//////////
while(first<=last)
       { mid=(first+last)/2;
		if(target>list[mid])
			first=mid+1;
		else if(target<list[mid])
			last=mid-1;
		else
			first=last+1;
       }
location=mid;
found=1;
printf("%d=found\n",found);
printf("%d=location",location+1);
getch();
return;

}
