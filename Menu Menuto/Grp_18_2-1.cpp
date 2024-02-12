/*Logic design and Digital Computer Circuits
	BSCS 2-1		August 13, 2019
	Renwell Jean Angel
	Joseph Puapo Tupaen
	Carl Joseph Cepe
*/
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h> 
#include<ctype.h>

//^^^^^^^^^^FUNCTIONS^^^^^^^^^^^^^
void gotoxy(short x, short y);
int deciConverter();
void octDec();
void hexDec();
void binaryDeci();
int ASCII();
int formula(int binary);
void grayCode();
int complement();
int errorDetect();
int EXIT();

//===========MAIN===============
int main()
{system("CLS");

char sagot;
while(sagot!='X'){

gotoxy(11,1);printf("---------------------MENU MENUTO---------------------");
gotoxy(12,3);
printf("'Choose one function by typing the corresponding NUMBER'");

gotoxy(19,5);
printf("(N). NUMBER SYSTEM ");
gotoxy(21,7);
printf("(1). Decimal to binary, octal and hexadecimal");
gotoxy(21,8);
printf("(2). Octal to decimal");
gotoxy(21,9);
printf("(3). Hexadecimal to decimal");
gotoxy(21,10);
printf("(4). Binary to decimal");

gotoxy(19,12);
printf("(C). CODES");
gotoxy(21,14);
printf("(5). Ascii");
gotoxy(21,15);
printf("(6). Gray code");

gotoxy(19,17);
printf("(O). OTHERS");
gotoxy(21,19);
printf("(7). Complement");
gotoxy(21,20);
printf("(8). Hamming code");


gotoxy(19,22);
printf("(X). EXIT");

gotoxy(29,24);
printf("Choose one:                                   ");
	gotoxy(40,24);scanf(" %c",&sagot);
switch(sagot){
	case '1':
		deciConverter();
		break;
	case '2':
		octDec();
		break;
	case '3':
		hexDec();
		break;
	case '4':
	    binaryDeci();
		break;
	case '5':
		ASCII();
		break;
	case '6':
		grayCode();
		break;
	case '7':
		complement();
		break;
	case '8':
		errorDetect();
		break;
	case 'X':
		EXIT();
		break;
	default:
		{gotoxy(40,24);
		printf("No such valid code!");
	 	getch();}

}//switch menu

}//while menu
system("CLS");
}//menu main

//===========================DECIMAL TO BINARY,OCTAL,HEXA================================================
int deciConverter(){char ans='Y';
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
system("CLS");
return 0;
}//deciConverter

// =========================OCTAL TO DECIMAL=========================
void octDec() {
	char ans = 'Y', hex[80];
	while(toupper(ans)=='Y'){
	
	int base = 1,dec = 0; 
	system("CLS");
	printf("\n\t\t\t  -----Octal to Decimal----- ");
	printf("\n\t\t  Octal(8) values = (0,1,2,3,4,5,6,7)\n");
	printf("\n\n\n\t\tInput Octal Value : ");
	fflush(stdin);
	scanf("%s", hex);
    int len = strlen(hex); 

    for (int x=len-1; x>=0; x--) {    
        if (hex[x]>='0' && hex[x]<='9') { 
            dec += (hex[x] - 48)*base; 
            base = base * 8; 
        }   
    } 
    
    printf("\n\n\t\tDecimal Equivalent: %d\n", dec);
    printf("\n\n\n\t\t\t   Try again? (y/n): ");
    fflush(stdin);
    scanf("%c", &ans);
}
system("CLS");
} 

//================================HexaDecimal to Decimal====================================
// HEXA TO DECI
void hexDec() {
	char ans = 'Y', hex[80];
	while(toupper(ans)=='Y'){
	
	int base = 1,dec = 0; 
	system("CLS");
	printf("\n\t\t\t-----Hexadecimal to Decimal-----\n");
	printf("\n\t Hexadecimal(16) values = (0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F)\n");
	printf("\n\n\n\t\tInput Hexadecimal Value: ");
	fflush(stdin);
	scanf("%s", hex);
    int len = strlen(hex); 
    
    for (int x=len-1; x>=0; x--) {    
        if (hex[x]>='0' && hex[x]<='9') { 
            continue;
        } 
        else if (hex[x]>='A' && hex[x]<='F' || hex[x]>='a' && hex[x]<='b') { 
            hex[x]=toupper(hex[x]); 
        } 
    }
    for (int x=len-1; x>=0; x--) {    
        if (hex[x]>='0' && hex[x]<='9') { 
            dec += (hex[x] - 48)*base; 
            base = base * 16; 
        } 
        else if (hex[x]>='A' && hex[x]<='F') { 
            dec += (hex[x] - 55)*base; 
            base = base*16; 
        } 
    } 
    printf("\n\n\t\tDecimal Equivalent: %d\n", dec);
    printf("\n\n\n\t\t\t   Try again? (y/n): ");
    fflush(stdin);
    scanf("%c", &ans);
}
system("CLS");
} //hexa to decimal

//=========================================BINARY TO DECIMAL=======================================
void binaryDeci() {
	char ans='Y';
	while(toupper(ans)=='Y'){
	system("CLS");
	int no, rem, dev, i=1, res=0;
	printf("\n\t\t\t-----Binary to Decimal-----\n");
	printf("\n\t\t\t Binary(2) values = (0,1)\n");
	printf("\n\n\n\t\tEnter a Binary Value: ");
	scanf("%d", &no);
	while(no) {
		rem=no%10;
		no/=10;
		res+=rem*i;
		i=i*2;
	}
	printf("\n\n\n\t\tDecimal equivalent: %d\n", res);
	printf("\n\n\n\t\t\t   Try again? (y/n): ");
	fflush(stdin);
	scanf("%c", &ans);
}
	system("CLS");
}

//===============ASCII=========================================================
int ASCII(){
	char ans='Y';
	while(toupper(ans)=='Y'){system("CLS");
	int i=0;
	char a[32];
	printf("\n\n\t\t\t      -----ASCII-----");
	printf("\n\n\n\n\tEnter  String: ");
	scanf("%s", &a);
	
	printf("\n\n\tASCII Values : ");
	while(a[i]) {
		printf(" %d", a[i++]);
	}
	printf("\n\n\n\n\t\t\t\tAGAIN(y/n)?: ");scanf(" %c",&ans);
}
	printf("\n\n\n\t");
	system("CLS");
	return 0;
}//ascii

//===============gray code=========================================================
void grayCode(){
char ans = 'Y';
while(toupper(ans)=='Y'){
    int binary, gray;
 	system("CLS");
    	printf("\n\n\t\t\t      -----GRAY CODE-----\n");
    printf("\n\n\n\t     Enter a binary number: ");
    scanf("%d", &binary);
    gray = formula(binary);
    printf("\n\n\t     Gray Code equivalent : %d", gray);

printf("\n\n\n\n\t\t\t  Try again? (y/n): ");
    fflush(stdin);
    scanf("%c",&ans);
}
system("CLS");
}// gray code
 
int formula(int binary)
{
    int a, b, result;
 
    if (!binary){
        return 0;
    }
    else
    {
        a = binary % 10;
        binary = binary / 10;
        b = binary % 10;
        if ((a && !b) || (!a && b)){
            result =  1 + 10 * formula(binary);
            return result;
        }
        else{
            result =  10 * formula(binary);
            return result;
        }
    }
}//*********gray code****************

//=========================COMPLEMENT====================================================
int complement(){system("CLS");
	int z; char ans='Y';
while(toupper(ans)=='Y'){
	//**********local variables**************
	int size=32;
	int n,i=0,k=0,binaryNum[size],limit,carry=1;
	char binary[size],ones[size],twos[size];
	gotoxy(26,1);printf("---1's and 2's COMPLEMENT---");
	for(z=0;z<22;z++){gotoxy(3+z,4);printf("%c",196);}for(z=0;z<6;z++){gotoxy(3,4+z);printf("%c",179);}
	for(z=0;z<22;z++){gotoxy(3+z,10);printf("%c",196);}for(z=0;z<6;z++){gotoxy(25,4+z);printf("%c",179);}
	gotoxy(3,4);printf("%c",218);gotoxy(25,10);printf("%c",217);gotoxy(25,4);printf("%c",191);gotoxy(3,10);printf("%c",192);
	gotoxy(12,5);printf("INPUT");
	for(z=0;z<52;z++){gotoxy(25+z,4);printf("%c",196);}for(z=0;z<10;z++){gotoxy(25,5+z);printf("%c",179);}
	for(z=0;z<52;z++){gotoxy(25+z,14);printf("%c",196);}for(z=0;z<10;z++){gotoxy(77,4+z);printf("%c",179);}
	gotoxy(25,14);printf("%c",192);gotoxy(77,14);printf("%c",217);gotoxy(77,4);printf("%c",191);
    gotoxy(45,5);printf("OUTPUT");gotoxy(29,7);
	printf("Original binary:                                ");gotoxy(29,9);printf("Ones complement:                                ");
    gotoxy(29,11);printf("Twos complement:                                ");
	gotoxy(5,7);printf("decimal:            ");gotoxy(14,7);scanf("%d",&n);
    //*****convert decimal to binary*********
    while (n > 0) { 
        // storing remainder 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } limit=i;
    // printing binary array 
    for (int j = i - 1; j >= 0; j--) {
        binary[k]=binaryNum[j]+'0';k++;}binary[k]='\0';
 //******compute ones complement************
 for(i=0; i<limit; i++)
    {
        if(binary[i] == '1')
        {
            ones[i] = '0';
        }
        else if(binary[i] == '0')
        {
            ones[i] = '1';
        }
    }
    ones[limit] = '\0';
 //******compute twos complement**********
    for(i=limit-1; i>=0; i--)
    {
        if(ones[i] == '1' && carry == 1)
        {
            twos[i] = '0';
        }
        else if(ones[i] == '0' && carry == 1)
        {
            twos[i] = '1';
            carry = 0;
        }
        else
        {
            twos[i] = ones[i];
        }
    }
    twos[limit] = '\0';
//**********PRINTING************
    gotoxy(45,5);printf("OUTPUT");
	gotoxy(46,7);printf("%s", binary);
    gotoxy(46,9);printf("%s", ones);
    gotoxy(46,11);printf("%s", twos);
    gotoxy(6,12);printf("AGAIN?(Y/N):   ");
    gotoxy(18,12);scanf(" %c",&ans);
}
    gotoxy(0,z+10);
    system("CLS");
	return 0; 
}// complement

//======================Error Detection/HammingCode====================================================
int errorDetect(){
system("CLS");
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
system("CLS");
return 0;
}// error detect

//=============EXIT============================
int EXIT()
{
system("CLS");
gotoxy(30,12);
printf(" >>> BYE BYE <<< ");

gotoxy(10,3);
printf("BSCS 2-1");
gotoxy(10,6);
printf("Joseph Puapo Tupaen");
gotoxy(10,5);
printf("Renwell Jean Angel");
gotoxy(10,7);
printf("Carl Joseph Cepe");
gotoxy(20,1);
printf("LOGIC DESIGN AND DIGITAL COMPUTER CIRCUITS ");
getch();
system("CLS");
return 0;
}
//====================GOTOXY===============================================================
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
