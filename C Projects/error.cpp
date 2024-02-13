#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h> 
#include<math.h>//*****padagdag neto 

void gotoxy(short x, short y) {//gotoxy function ********padagdag(copy/paste) nalang!!!
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(){// pa change nalang to function ERROR  !!!! 
char ans='Y';  	
while(toupper(ans)=='Y'){
	//*****local variables
	char MSG[32];
	int min,max,parity,j,x,i,z;
	//*****converting char to binary equivalent*********
	gotoxy(0,0);printf("ERROR CHECKING: HAMMING CODE :                      MAX five letters");
	for(z=0;z<8;z++){gotoxy(31+z,1);printf("%c",196);}gotoxy(32,2);printf("SENDER");for(z=0;z<63;z++){gotoxy(15+z,3);printf("%c",196);}gotoxy(16,4);printf("INPUT:                                                                                         ");
	gotoxy(16,7);printf("OrigBits:                                                                                        ");
	gotoxy(6,7);printf("     ");gotoxy(6,9);printf("     ");gotoxy(6,11);printf("     ");
	gotoxy(16,9);printf("SendCode:                                                                                                   ");
	gotoxy(31,15);printf("RECIEVER");gotoxy(16,17);printf("RcvdCode:                                                                                           ");
	gotoxy(4,17);printf("        ");gotoxy(4,18);printf("       ");gotoxy(6,19);printf("     ");
	gotoxy(31,19);printf("         ");gotoxy(30,19);printf("             ");
	//******for graphics/border********
	for(z=0;z<75;z++){gotoxy(3+z,12);printf("%c",196);}for(z=0;z<75;z++){gotoxy(3+z,16);printf("%c",196);}for(z=0;z<10;z++){gotoxy(30+z,14);printf("%c",196);}
	for(z=0;z<75;z++){gotoxy(3+z,20);printf("%c",196);}for(z=0;z<11;z++){gotoxy(3+z,5);printf("%c",196);}for(z=0;z<8;z++){gotoxy(78,4+z);printf("%c",179);}
	gotoxy(78,3);printf("%c",191);gotoxy(78,12);printf("%c",217);gotoxy(78,16);printf("%c",191);gotoxy(78,20);printf("%c",217);gotoxy(39,1);printf("%c",191);
	gotoxy(40,14);printf("%c",191);gotoxy(29,14);printf("%c",218);gotoxy(3,16);printf("%c",218);gotoxy(3,5);printf("%c",218);gotoxy(14,3);printf("%c",218);
	gotoxy(30,1);printf("%c",218);gotoxy(3,20);printf("%c",192);gotoxy(3,12);printf("%c",192);gotoxy(30,2);printf("%c",179);gotoxy(39,2);printf("%c",179);
	gotoxy(29,15);printf("%c",179);gotoxy(40,15);printf("%c",179);for(z=0;z<6;z++){gotoxy(3,6+z);printf("%c",179);}for(z=0;z<8;z++){gotoxy(14,4+z);printf("%c",179);}
	for(z=0;z<3;z++){gotoxy(3,17+z);printf("%c",179);}for(z=0;z<3;z++){gotoxy(14,17+z);printf("%c",179);}for(z=0;z<3;z++){gotoxy(78,17+z);printf("%c",179);}
	gotoxy(5,6);printf("BitLGTH");gotoxy(4,8);printf("CheckBits"); gotoxy(4,10);printf("TotalBits");
	//****Converts char to binary equivalent*******
	gotoxy(22,4);scanf("%s",&MSG);
	size_t length = strlen(MSG);// can be int
    char *binary = (char*) malloc(length*8 + 1); 
    binary[0] = '\0';
    for( i = 0; i < length; ++i) {
        char ch = MSG[i];
        for(j = 7; j >= 0; --j){
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
        }
    }
	int wordSize=length*8;
 	gotoxy(26,7);printf("%s",binary);
  	gotoxy(7,7);printf("%d",wordSize); 
	//******parity bit***************************
	int n=0;
  	while(pow (2,n) < wordSize + n + 1){n++;}
    gotoxy(7,9);printf("%d",n);
    int total=n+wordSize; // total*****
    gotoxy(7,11);printf("%d",total);
    int ham[total],M=0,O=0;// for condition 
    //***finding where to place bits************
    for(int i = 1; i <= total; i++){
    
        if( i == pow( 2, M )){
            ham[i] = 9;    //initial value of redundant bits
            M++;
        }
        else{
        		if(binary!=NULL){
            ham[i] = binary[O]-'0';
            O++;}
        }
	}
	//******placing the parity bit****************
	M=0;
	for (O = 1; O <=total; O= pow (2, M)){M++;
      j = O, min = 1,max = O,parity = 0;
       while ( j <= total){
          for (x = j; max >= min && x <= total; min++, x++){
              if (ham[x] == 1)parity = parity + 1;}
          j = x + O;min = 1;}
    //***check if even*******
      if (parity % 2 == 0){ ham[O] = 0;}
      else{ham[O] = 1;}
	}
	//********final printing result**************
	   gotoxy(26,9);
	   for(i=1;i<=total;i++)
       	printf("%d",ham[i]);    	
    //********receiver/compare*******************
    char receive[total],compare[total];
    for(i=0;i<total;i++){
    	compare[i]=ham[i+1]+'0';}
	compare[i+1]='\0';
	gotoxy(26,17);scanf(" %s",receive);
	if(strncmp(receive,compare,total)!=0){gotoxy(32,19);printf("Error");}
	else{gotoxy(31,19);printf("Success");}
	int result=strcmp(receive,compare);
	gotoxy(5,17);printf("AGAIN?");gotoxy(5,18);printf("(y/n)");gotoxy(7,19);scanf(" %c",&ans);
}//while
gotoxy(0,20);
}//********Error function end*************
    	
    
    
