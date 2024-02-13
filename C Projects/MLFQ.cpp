#include<stdio.h>
#include<conio.h>

typedef struct
{
	char process_name[10];
	int process_time;
	int burst_time;
	int arrival_time;
	int priority_level;
	int completion_time;
	int turnAround_time;
	int waiting_time;
}process_structure;

int main()
{
int number_of_process;
printf("Input number of process:");
scanf("%d",&number_of_process);
process_structure process[number_of_process];


for(int i=0;i<number_of_process;i++){
printf("\nInput");
printf("\n\tProcess Name:");
printf("\n\tArrival Time:");
printf("\n\tBurst Time:");
printf("\n\tPriority Level:");
}//input for loop

}
