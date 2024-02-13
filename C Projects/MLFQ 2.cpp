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
	bool status;
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
process[i].status=true;
}//input for loop

// getting the largest burst time for srtf
int largest_burst=0;
for(int i=0;i<number_of_process;i++){
	if(largest_burst<process[i].burst_time){
		largest_burst=process[i].burst_time;
	}
}

int time=0;// HOLY TIMER :o 

//SRTF
int smallest,location;
smallest=largest_burst;

for(int i=0;i<number_of_process;i++){//scan all srtf
	if(process[i].level==0 && process[i].arrival_time <= time){//check if really level 0
			if(smallest>process[i].current_burst){//check smallest srtf
				location=i;
				printf("\n%d",location);
			}
	}
	i++;
}
process[location].current_burst--;
time++;
printf("\n%d",process[0].level);
printf("\n%d",largest_burst);
printf("\n%d",location);
printf("\n%d    %d",process[location].current_burst,time);
}
