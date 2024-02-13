/*

BSCS 2-1
Operating SYstem
MLFQ


================Members================

Caculitan, Harold Roxas 
Cepe,      Carl Joseph 
Cornita,   Meryll Daeme 
Erfe,	   Jefferson 
Galindez,  Christopher Elijah
Montoya,   Royce Ricco
Tarcenio,  Earl 

=======================================
						
*/

#include<stdio.h>
#include <windows.h> // gotoxy
#include<stdlib.h> //system CLS

//----------GOTOxy for design----------------------------------

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//----------Process Struture  ;) -------------------------------
typedef struct {
	char Process_Id;
	int Arrival_Time;
	int Burst_Time;
	int Priority;
	int Level;
	
	int Current_Arrival_Time;// hindi na gamit -_-
	int Current_Burst_Time;
	int Level_Initial;
	
	int Waiting_Time;
	int Turn_Around_Time;
	int End_Time;

	int Status;
}process_structure;

//==============================================================
//================M A I N=======================================
//==============================================================
int main(){
	
	//para lumaki yung console window :)
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd,SW_SHOWMAXIMIZED);
	
	
	//-----------------------------------------------------------getting number of process														
	int number_of_process;
	gotoxy(23,1);
	printf("Input number of Process:");
	scanf("%d",&number_of_process);
	
	//----------------------------------------------------------Creating process with Process_Structure data type/structure
	process_structure process[number_of_process];
	
	//----------------------------------------------------------Collecting Process data :3
	for(int i=0;i<number_of_process;i++){
		
		process[i].Process_Id = 'A' + i;
		
		LEVEL_ERROR:
		system ("CLS");
		gotoxy(23,1);
		printf("Input number of Process:%d",number_of_process);
		
		
		gotoxy(29,3);
		printf(" Input Data");
		gotoxy(35,5);
		printf("%c",process[i].Process_Id);
		gotoxy(23,7);
		printf("Level:0-SRTF 1-PP 2--FCFS");
		
		gotoxy(27,9);
		printf("Burst Time: ");
		scanf("%d",&process[i].Burst_Time);
		gotoxy(27,11);
		printf("Arrival Time: ");
		scanf("%d",&process[i].Arrival_Time);
		gotoxy(27,13);
		printf("Level: ");
		scanf("%d",&process[i].Level);
		gotoxy(27,15);
		printf("Priority: ");
		scanf("%d",&process[i].Priority);

		process[i].Current_Burst_Time=process[i].Burst_Time;
		process[i].Current_Arrival_Time=process[i].Current_Arrival_Time;
		process[i].End_Time=0;
		process[i].Status=0;
		process[i].Level_Initial=process[i].Level;
		
		if(process[i].Level!=0 && process[i].Level!=1 && process[i].Level!=2){
			gotoxy(18,19);			
			printf("Invalid value for LEVEL. Try Again");
			gotoxy(19,20);
			system("pause");
			goto LEVEL_ERROR;
		}
	}
	
	//----------------------------------------------------------pang set ng mga importanteng bagay hahaha!!! (Para malaman kung sino nabang uunahin)
	int Total_BT=0;
	for(int i=0;i<number_of_process;i++){
		Total_BT=process[i].Burst_Time+Total_BT;
	}
	char Gantt_Chart[Total_BT];
	int Gantt_Chart_Time[Total_BT];
	int G=0;

	int Time=0,Complete=0;
	int Current_Srtf;
	int Current_Srtf_Enable=0;
	
	int Current_PP;
	int Current_PP_Enable=0;
	
	int Current_FCFS;
	int Current_FCFS_Enable=0;
	int Current_FCFS_Occupied=0;
	int Current_FCFS_Complete=0;
	
	int Current_Level_Enable=0;
	int Current_Level;
	int Incoming_Level;
	
	//----------------------------------------------------------Start ng lOOP :)
while(Complete==0){
	
	//..........................................................bumabalik sa initial value mga variables na to
	int Srtf_Largest_Burst,Srtf_Largest_Location;
	int PP_Largest_Priority,PP_Largest_Location,PP_Flag;
	int FCFS_Flag,FCFS_Initial,FCFS_Initial_Location;
	
	int SRTF,PP,FCFS;
	SRTF=0;
	PP=0;
	FCFS=0;
	
	Srtf_Largest_Burst=0;
	Srtf_Largest_Location=0;
	
	PP_Largest_Priority=0;
	PP_Largest_Location=0;
	PP_Flag=0;
	
	FCFS_Flag=0;
	FCFS_Initial=0;
	FCFS_Initial_Location=0;
	
	//...........................................................pang check ng level na gagawin
	for(int i=0;i<number_of_process;i++){
	 
		if(process[i].Level==0 && process[i].Arrival_Time <= Time && process[i].Status ==0 && Current_FCFS_Complete==0){
			SRTF=1;
			if(process[i].Current_Burst_Time>Srtf_Largest_Burst)
			{
				Srtf_Largest_Burst=process[i].Current_Burst_Time;
				Srtf_Largest_Location=i;
			}
		}
		
		
		if(process[i].Level==1 && process[i].Arrival_Time <= Time && process[i].Status ==0 && Current_FCFS_Complete==0){
			PP=1;
			if(PP_Flag==0){
				PP_Largest_Priority=process[i].Priority;
				PP_Largest_Location=i;
				PP_Flag=1;
			}
		}
		
		if(process[i].Level==2 && process[i].Arrival_Time <= Time && process[i].Status ==0){
			FCFS=1;
			if(FCFS_Flag==0){
				FCFS_Initial=process[i].Arrival_Time;
				FCFS_Initial_Location=i;
				FCFS_Flag=1;				
			}
		}
	}
	
	//...........................................................para mag level up yung 1 and hindi ma putol yung FCFS kapag may process pang active :)
	if(SRTF==1){
		Incoming_Level=0;
	}
	
	else if(SRTF !=1 && PP==1){
		Incoming_Level=1;
	}
	
	else if(SRTF !=1 && PP !=1 && FCFS ==1){
		Incoming_Level=2;
	}
	
	
	if(Current_Level_Enable==0){
		Current_Level=Incoming_Level;
		Current_Level_Enable=1;
	}
	
	if(Incoming_Level == Current_Level){         
		Current_Level=Incoming_Level;
	}
	
	else if(Incoming_Level > Current_Level){
		Current_Level=Incoming_Level;
	}
	
	
	else if(Incoming_Level < Current_Level){
		if(Current_Level==1){
			process[Current_PP].Level=2;
			Current_Level=Incoming_Level;
		}
		
		Current_Level=Incoming_Level;
	}
	
	
//____________________________________________________________________________________________________________________	
//_____________________________________________________________SRTF___________________________________________________
//____________________________________________________________________________________________________________________	
	
	if(SRTF==1){  //SRTF algo
		int Srtf_Smallest_Burst=Srtf_Largest_Burst;
		int Srtf_Smallest_Location=Srtf_Largest_Location;
			for(int i=0;i<number_of_process;i++){
				if(process[i].Level==0 && process[i].Arrival_Time <= Time && process[i].Status ==0){				
					if(process[i].Current_Burst_Time<Srtf_Smallest_Burst){
						Srtf_Smallest_Burst=process[i].Current_Burst_Time;
						Srtf_Smallest_Location=i;	
					}
					else if(process[i].Current_Burst_Time==Srtf_Smallest_Burst){
						if(process[i].Arrival_Time<process[Srtf_Smallest_Location].Arrival_Time){
							Srtf_Smallest_Burst=process[i].Current_Burst_Time;
							Srtf_Smallest_Location=i;	
						}
					}
				}
				if(process[Current_Srtf].Current_Burst_Time == process[Srtf_Smallest_Location].Current_Burst_Time && Current_Srtf != Srtf_Smallest_Location && Current_Srtf_Enable !=0 ){
					Srtf_Smallest_Location=Current_Srtf;
				}				
			}
		process[Srtf_Smallest_Location].Current_Burst_Time--;
		Gantt_Chart[G]=process[Srtf_Smallest_Location].Process_Id;
		Gantt_Chart_Time[G]=Time+1;
		G++;
		
		
		if(process[Srtf_Smallest_Location].Current_Burst_Time <=0 ){
			process[Srtf_Smallest_Location].Status=1;
			process[Srtf_Smallest_Location].End_Time=Time+1;
		}
		if(Current_Srtf_Enable==0){
			Current_Srtf_Enable=1;
			Current_Srtf=Srtf_Smallest_Location;
		}
		
		else if(Current_Srtf_Enable=1);{
			if(Current_Srtf!=Srtf_Smallest_Location){
				if(process[Current_Srtf].Status==0){
				process[Current_Srtf].Level=1;
				Current_Srtf=Srtf_Smallest_Location;
				}
				if(process[Current_Srtf].Status==1){
					Current_Srtf=Srtf_Smallest_Location;
				}
			}
		}
}//SRTF		
	

//____________________________________________________________________________________________________________________	
//_____________________________________________________________PP_____________________________________________________
//____________________________________________________________________________________________________________________

	if(SRTF!=1 && PP == 1){// PP
		int PP_Smallest_Priority=PP_Largest_Priority;
		int PP_Smallest_Location=PP_Largest_Location;
		
		for(int i=0;i<number_of_process;i++){
			if(process[i].Level==1 && process[i].Arrival_Time <=Time && process[i].Status == 0){
				if(process[i].Priority<PP_Smallest_Priority){
					PP_Smallest_Priority=process[i].Priority;
				    PP_Smallest_Location=i;	
				}
				else if(process[i].Priority==PP_Smallest_Priority){
					if(process[i].Arrival_Time<process[PP_Smallest_Location].Arrival_Time){
					PP_Smallest_Priority=process[i].Priority;
				    PP_Smallest_Location=i;	
					}
					
					else if(process[i].Arrival_Time>process[PP_Smallest_Location].Arrival_Time){
						
					}
				}
			}
			if(process[Current_PP].Priority == process[PP_Smallest_Location].Priority && Current_PP != PP_Smallest_Location && process[Current_PP].Status ==0 && Current_PP_Enable !=0){
				    		PP_Smallest_Location=Current_PP;
					}
		}
	
	
		process[PP_Smallest_Location].Current_Burst_Time--;
		Gantt_Chart[G]=process[PP_Smallest_Location].Process_Id;
		Gantt_Chart_Time[G]=Time+1;
		G++;
		
		
		
		if(process[PP_Smallest_Location].Current_Burst_Time <=0 ){
			process[PP_Smallest_Location].Status=1;
			process[PP_Smallest_Location].End_Time=Time+1;
		}
		if(Current_PP_Enable==0){
			Current_PP_Enable=1;
			Current_PP=PP_Smallest_Location;
		}
		
		else if(Current_PP_Enable=1);{
			if(Current_PP!=PP_Smallest_Location){
				if(process[Current_PP].Status==0){
				process[Current_PP].Level=2;
				Current_PP=PP_Smallest_Location;
				}
				else if(process[Current_PP].Status==1){
				Current_PP=PP_Smallest_Location;
				}
			}
		}	
}//PP	


//____________________________________________________________________________________________________________________
//_____________________________________________________________FCFS___________________________________________________
//____________________________________________________________________________________________________________________

	if(SRTF!=1 && PP!=1 && FCFS ==1){
		  if(Current_FCFS_Occupied==0){
			for(int i=0;i<number_of_process;i++){
				if(process[i].Level==2 &&process[i].Arrival_Time <= Time && process[i].Status ==0){
					if(process[i].Arrival_Time<FCFS_Initial){
						FCFS_Initial=process[i].Arrival_Time;
						FCFS_Initial_Location=i;
					}
					
					else if(process[i].Arrival_Time==FCFS_Initial && i != FCFS_Initial_Location){
					}
					
					else if(process[i].Arrival_Time==FCFS_Initial && i == FCFS_Initial_Location){
						FCFS_Initial=process[i].Arrival_Time;
						FCFS_Initial_Location=i;
					}
				}	
			}
		}
			
		if(Current_FCFS_Enable==0){
			Current_FCFS=FCFS_Initial_Location;
			Current_FCFS_Enable=1;
			Current_FCFS_Occupied=1;
			Current_FCFS_Complete=1;
		}
		
		if(Current_FCFS_Occupied==0){
			Current_FCFS=FCFS_Initial_Location;
			Current_FCFS_Occupied=1;
			Current_FCFS_Complete=1;
		}

		process[Current_FCFS].Current_Burst_Time--;	
		Gantt_Chart[G]=process[Current_FCFS].Process_Id;
		Gantt_Chart_Time[G]=Time+1;
		G++;
		
		
		if(process[Current_FCFS].Current_Burst_Time <=0){
			process[Current_FCFS].Status=1;
			process[Current_FCFS].End_Time=Time+1;
			Current_FCFS_Occupied=0;
			Current_FCFS_Complete=0;		
		}					
	}//FCFS
	
	
//________________________________________________________________________end nung BIG 3 (SRTF,PP,FCFS)
	
Time++;//for time ++

	//....................................................................to check kung tapos naba
Complete=1;
for(int i=0;i<number_of_process;i++){
	if(process[i].Status==0){
		Complete=0;
							}
									}
				
}//while loop
//------------------------------------------------------------------------End of WHILE LOOP
int Total_TT=0;
int Total_WT=0;
float TTave;
float WTave;


for(int i=0;i<number_of_process;i++){
	process[i].Turn_Around_Time=process[i].End_Time-process[i].Arrival_Time;
	process[i].Waiting_Time=process[i].Turn_Around_Time-process[i].Burst_Time;
	
	Total_TT=Total_TT+process[i].Turn_Around_Time;
	Total_WT=Total_WT+process[i].Waiting_Time;
}

TTave=Total_TT/number_of_process;
WTave=Total_WT/number_of_process;

system ("CLS");
		gotoxy(23,1);
		printf("Input number of Process:%d",number_of_process);
gotoxy(4,3);
printf("P_ID=Process ID		BT=Burst Time		AT=Arrival Time");
gotoxy(4,4);
printf("LS=Level Start		LE=Level End		P=Priority");		
gotoxy(4,5);
printf("WT=Waiting Time		ET=End Time	        Tt=Total Time");
		
		
		
gotoxy(4,8);		
printf("P_ID");
gotoxy(12,8);		
printf("BT");
gotoxy(20,8);		
printf("AT");
gotoxy(28,8);		
printf("LS");
gotoxy(36,8);		
printf("LE");
gotoxy(44,8);		
printf("P");
gotoxy(52,8);		
printf("ET");
gotoxy(60,8);		
printf("TT");
gotoxy(68,8);		
printf("WT");

for(int i=0;i<number_of_process;i++ ){
	gotoxy(5,10+i);
	printf("%c",process[i].Process_Id);
	gotoxy(12,10+i);
	printf("%d",process[i].Burst_Time);
	gotoxy(20,10+i);
	printf("%d",process[i].Arrival_Time);
	gotoxy(28,10+i);
	printf("%d",process[i].Level_Initial);
	gotoxy(36,10+i);
	printf("%d",process[i].Level);
	gotoxy(44,10+i);
	printf("%d",process[i].Priority);
	gotoxy(52,10+i);
	printf("%d",process[i].End_Time);
	gotoxy(60,10+i);
	printf("%d",process[i].Turn_Around_Time);
	gotoxy(68,10+i);
	printf("%d",process[i].Waiting_Time);
}
printf("\n\n\t\t\tTT total     =   %d",Total_TT);       
printf("\n\t\t\tWT total     =   %d",Total_WT);
printf("\n\t\t\tTT average   =   %.2f",TTave);
printf("\n\t\t\tWT average   =   %.2f",WTave);

printf("\n\n\t\t\t       GANTT CHART\n\n");

//-----------------------------------------------------gantt chart -_- 
for(int i=0;i<Total_BT;i++){
	printf("|%c",Gantt_Chart[i]);
}
}//main
//===========================================================END============================================
