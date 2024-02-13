#include<stdio.h>

typedef struct {
	char Process_Id;
	int Arrival_Time;
	int Burst_Time;
	int Priority;
	int Level;
	
	int Current_Arrival_Time;
	int Current_Burst_Time;
	
	int Waiting_Time;
	int Turn_Around_Time;
	int End_Time;
	
	int Status;
}process_structure;

int main(){
	int number_of_process;
	printf("Input number of Process:");
	scanf("%d",&number_of_process);
	
	process_structure process[number_of_process];
	
	for(int i=0;i<number_of_process;i++){
		process[i].Process_Id = 'A' + i;
		printf("\n\t input Process %c",process[i].Process_Id);
		printf("\n\t Burst Time: ");
		scanf("%d",&process[i].Burst_Time);
		printf("\n\t Arrival Time: ");
		scanf("%d",&process[i].Arrival_Time);
		printf("\n\t Priority: ");
		scanf("%d",&process[i].Priority);
		printf("\n\t Level: ");
		scanf("%d",&process[i].Level);
		
		process[i].Current_Burst_Time=process[i].Burst_Time;
		process[i].Current_Arrival_Time=process[i].Current_Arrival_Time;
		process[i].End_Time=0;
		process[i].Status=0;
	}
	int Time=0,Complete;
	int Current_Srtf;// para malaman kung tataas naba to next lvl
	int Current_Srtf_Enable=0;
	
	int Current_PP;
	int Current_PP_Enable=0;

for(int j=0;j<10;j++){

	int Srtf_Largest_Burst,Srtf_Largest_Location;
	int PP_Largest_Priority,PP_Largest_Location,PP_Flag;
	int SRTF,PP,FCFS;
	SRTF=0;
	PP=0;
	FCFS=0;
	Srtf_Largest_Burst=0;
	Srtf_Largest_Location=0;
	
	PP_Largest_Priority=0;
	PP_Largest_Location=0;
	PP_Flag=0;
	
	for(int i=0;i<number_of_process;i++){ // pang check ng level na gagawin
		if(process[i].Level==0 && process[i].Arrival_Time <= Time && process[i].Status ==0){
			SRTF=1;
			if(process[i].Current_Burst_Time>Srtf_Largest_Burst)
			{
				Srtf_Largest_Burst=process[i].Current_Burst_Time;
				Srtf_Largest_Location=i;
				//Current_Srtf=i; // baka eto
				
			}
		}
		
		
		if(process[i].Level==1 && process[i].Arrival_Time <= Time && process[i].Status ==0){
			PP=1;
			if(PP_Flag==0){
				PP_Largest_Priority=process[i].Priority;
				PP_Largest_Location=i;
				PP_Flag=1;
			}
		}
		
		if(process[i].Level==2 && process[i].Arrival_Time <= Time && process[i].Status ==0){
			FCFS=1;
		}
	}
	
	
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
					printf("\nwtf");
				}				
			}

		process[Srtf_Smallest_Location].Current_Burst_Time--;
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
	
Time++;
		
}//j trial

	for(int i=0;i<number_of_process;i++){
		printf("\n%c = %d = %d = %d",process[i].Process_Id,process[i].Current_Burst_Time,process[i].Level,process[i].End_Time);
		if(process[i].Level==1){
		}
	}
	
	
	printf("\n\t time = %d",Time);
}//main
