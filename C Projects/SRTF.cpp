#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>

typedef struct
{
	// input 
	char process_name[10];
	int process_time;
	int burst_time;
	int arrival_time;
	int priority;
	int level;
	//derive
	int current_burst;
	int completion_time;
	int turnAround_time;
	int waiting_time;
	int status;
}process_structure;

int main()
{	
int number_of_process;
printf("Input number of process:");
scanf("%d",&number_of_process);
process_structure process[number_of_process];


for(int i=0;i<number_of_process;i++){
fflush(stdin);// pang flush sa input
printf("\nInput");
printf("\n\tProcess Name:");
fgets(process[i].process_name, 10, stdin); 
printf("\n\tArrival Time:");
scanf("%d",&process[i].arrival_time);
printf("\n\tBurst Time:");
scanf("%d",&process[i].burst_time);
printf("\n\tProcess Priority:");
scanf("%d",&process[i].priority);

process[i].current_burst=process[i].burst_time;
process[i].level=0;
process[i].status=0;
}//input for loop

int time=0;
int srtf_status=1;


srtf_loop:
for(int i=0;i<number_of_process;i++){
	if(process[i].level==0&&process[i].status!=1){
		srtf_status=0;
	}
	if else(process[i].level!=0){							**************
		srtf_status=1;
	}
}

int smallest_srtf_flag=0;

for(int i=0;i<number_of_process;i++){
	if(smallest_srtf_flag==0){
		if(process[i].level==0&&process[i].arrival_time<=time&&process[i].status!=1&&process[i].status!=1){
	
		int smallest_burst_srtf=process[i].current_burst;
		int smallest_burst_location=i;
		smallest_srtf_flag=1;
		}
	}
}
	
for(int i=0;i<number_of_process;i++){
	int srtf_limit=i+1;
		if(process[i].level==0 && process[i].arrival_time<=time && srtf_limit != number_of_process&&process[i].status!=1){
			if( smallest_burst_srtf>process[i].current_burst){
				smallest_burst_srtf=process[i].current_burst;
				smallest_burst_location=i;
			}
			
			if( smallest_burst_srtf==process[i].current_burst){
				smallest_burst_srtf=process[i].current_burst;
				smallest_burst_location=i;
			}
	}	
}

process[smallest_burst_location].current_burst--;

	if(process[smallest_burst_location].current_burst<=0){
		process[smallest_burst_location].status=false;
}

time++;

if(srtf_status==0){
	goto srtf_loop;
}

}
