
#include<windows.h> //*****padagdag neto for gotoxy
#include<stdio.h>

void gotoxy(short x, short y) {//gotoxy function ********padagdag(copy/paste) nalang!!!
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
 
int main(){// papalitan nalang tong main to function COMPLEMENT!!!
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
    return 0; 
} 
