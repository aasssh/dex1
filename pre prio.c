#include<stdio.h>
#include<stdlib.h>
struct Process
{
	int first_bt,next_bt,at,ft,tat,wt,temp_bt,priority;
}
P[100];
struct Schedule
{
	int pid,endtime;
}
sch[100];
int sch_cnt;
int ct;
int np;
int i;
void take_input()
{
	printf("Enter the number of process:");
	scanf("%d",&np);
	for(i=0;i<np;i++)
	{
		printf("Enter the arrival time:");
		scanf("%d",&P[i].at);
		
		printf("Enter the first burst time:");
		scanf("%d",&P[i].first_bt);
		
		printf("enter the priority:");
		scanf("%d",&P[i].priority);
		
		P[i].temp_bt=P[i].first_bt;
	}
}
void take_rinput()
{
	for(i=0;i<np;i++)
	{
		P[i].next_bt=rand()%10+1;
		
		P[i].temp_bt=P[i].next_bt;
	}
}

int getProcessByPriority()
{
	int minp=-1;
	int minat=32768;
	
	for(i=0;i<np;i++)
	{
		if(P[i].at<=ct && P[i].temp_bt>0 && P[i].priority<minat)
		{
			minp=i;
			minat=P[i].priority;
		}
	}
	return minp;
}

void showGanttChart()
{
	for(i=0;i<sch_cnt*5;i++)
	printf("--");
	printf("\n|");
	
	
	for(i=0;i<sch_cnt;i++)
	printf(" P%d |",sch[i].pid);
	printf("\n");
	
	for(i=0;i<sch_cnt*5;i++)
	printf("--");
	printf("\n0");
	
	for(i=0;i<sch_cnt;i++)
	printf("%5d",sch[i].endtime);
}

void print_output()
{
	float  avgtat=0,avgwt=0;
	printf("\n");
	printf("\nPID\tFBT\tRBT\tAT\tFT\tTAT\tWT\tP\n");
	for(i=0;i<np;i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,P[i].first_bt,P[i].next_bt,P[i].at,P[i].ft,P[i].tat,P[i].wt,P[i].priority);
		avgtat+=P[i].tat;
		avgwt+=P[i].wt;
	}
	avgtat=avgtat/np;
	avgwt=avgwt/np;
	
	printf("Avergate turn around time:%f",avgtat);
	printf("\nAverage waiting time;%f\n",avgwt);
}
int main()
{
take_input();
while(1)
{
	int x=getProcessByPriority();
	if(x==-1)
		break;
		sch[sch_cnt].pid=x;
		ct++;
		P[x].temp_bt--;
		sch[sch_cnt].endtime=ct;
		sch_cnt++;
	if(P[x].temp_bt==0)
		{
		P[x].ft=ct;
		P[x].tat=P[x].ft-P[x].at;
		P[x].wt=P[x].tat-P[x].first_bt;
		}
}

showGanttChart();
print_output();

take_rinput();

while(1)
{
	
	int x=getProcessByPriority();
	if(x==-1)
		break;
		sch[sch_cnt].pid=x;
		ct++;
		P[x].temp_bt--;
		sch[sch_cnt].endtime=ct;
		sch_cnt++;
	if(P[x].temp_bt==0)
	{
		P[x].ft=ct;
		P[x].tat=P[x].ft-P[x].at;
		P[x].wt=P[x].tat-P[x].first_bt-P[x].next_bt-2;
	}
}
	showGanttChart();
	print_output();
}

