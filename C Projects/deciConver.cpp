#include<stdio.h>
#include<conio.h>
#include<ctype.h>// padagdag !!!!
#include<stdlib.h>
int main(){char ans='Y';// pa change name nalang to function DeciConvert !!!!!!!
while(toupper(ans)=='Y'){system("CLS");
	int i=0,j=0,k=0,deci1,res,Limit=8,last,z;
    double Decimal,deci2,x;
	char Binary[36]={0},reverse[36]={0},Octal[36]={0},reverse2[36]={0},reverse3[36]={0},Hexa[36]={0};
	printf("\n                     DECIMAL ---> BINARY,OCTAL,HEXADECIMAL\n\n\n");
	printf("\n             INPUT");
printf("\n                Decimal: ");
scanf("%lf",&Decimal);
	deci1=Decimal;// gets the whole number
	deci2=Decimal-deci1;// gets the fractional part number
if(deci2!=0){k++;}
//*****decimal to binary*********
x=deci2;z=deci1;
while(z){
	int rem=z%2;
	reverse[j]=rem+'0';
	z/=2;
last=j;j++;}j=0;	
while(last>=0){
	Binary[j]=reverse[last];
	last--;j++;
}
//*computes fraction
if(k!=0){
Binary[j]='.';j++;
while(Limit!=0){
	x*=2;
	int bit=x;
		if(bit==1){
			Binary[j]=bit+'0';
			x-=bit;
				  }
		else{
			Binary[j]=bit+'0';}
Limit--;
j++;	
			}
		}
		
//*****decimal to octal***********
x=deci2;z=deci1;j=0;
while(z!=0){
	int temp = z%8;
    reverse2[j]= temp+'0';
	z=z/8;
last=j;j++;
}j=0;
while(last>=0){
	Octal[j]=reverse2[last];
	last--;j++;
}
Limit=8;
if(k!=0){
Octal[j]='.';j++;
while(Limit!=0){
	x*=8;
	int bit=x;
		if(bit!=0){
			Octal[j]=bit+'0';
			x-=bit;
				  }
		else{
			Octal[j]=bit+'0';}
Limit--;
j++;	
}
}
//*******decimal to hexdecimal********
z=deci1;x=deci2;j=0;
while(z!=0){
int temp = z % 16;
  
	if(temp<10){
		reverse3[j]=temp+48;
	}
	else
	{reverse3[j]= temp+55;}
	z=z/16;last=j;j++;
}j=0;
while(last>=0){
	Hexa[j]=reverse3[last];
	last--;j++;
}Limit=8;
if(k!=0){
Hexa[j]='.';j++;
while(Limit!=0){
	x*=16;
	int bit=x;
		if(bit!=0){
			if(bit==15)
			    {Hexa[j]='F';}
			else if(bit==14)
				{Hexa[j]='E';}
			else if(bit==13)
				{Hexa[j]='D';}
			else if(bit==12)
				{Hexa[j]='C';}
			else if(bit==11)
				{Hexa[j]='B';}
			else if(bit==10)
				{Hexa[j]='A';}
			else
				{Hexa[j]=bit+'0';}
			x-=bit;
				}
		else{
			Hexa[j]=bit+'0';}
Limit--;
j++;	
}
}
printf("\n\t\t---------------------------------------------");
printf("\n                Binary : %s",Binary);
printf("\n\n                Octal  : %s",Octal);
printf("\n\n                Hexa   : %s",Hexa);
 
printf("\n\n\n\n\t\t\t\tAGAIN(y/n)?:");scanf(" %c",&ans);
}//while
}//main
