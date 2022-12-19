#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct process
{
	int first_bt,temp_bt,priority,next_bt,at,ft,tat,wt;
}
p[100];
struct schedule
{
	int end_time,pid;
}sch[100];
int sch_cnt;  //schedule counter
int ct;  // current time
int np;	 // Number of process
int i;
void take_input()
{
	printf("Enter the number of process :  ");
	scanf("%d",&np);
	
	
	for(i=0;i<np;i++)
	{
		printf("Enter the arival time of the proess %d : ",i);
		scanf("%d",&p[i].at);
	}
	printf("\n");
	
	for(i=0;i<np;i++)
	{
		printf("Enter the priority of the proess %d : ",i);
		scanf("%d",&p[i].priority);
	}
	
	printf("\n");
	for(i=0;i<np;i++)
	{
		printf("Enter the burst time of the process %d : ",i);
		scanf("%d",&p[i].first_bt);
		p[i].temp_bt = p[i].first_bt;
	}
}

void take_rinput()
{
	for(i=0;i<np;i++)
	{
		p[i].next_bt = rand()%10+1;
		p[i].temp_bt = p[i].next_bt;
	}
}

int getProcessBySJF()
{
	int minp = -1;
	int minat = 32768;

	for(i=0;i<np;i++)
	{
		if(p[i].at<=ct && p[i].temp_bt >0 && p[i].priority<minat)
		{
			minp = i;
			minat = p[i].priority;
		}
	}
	return minp;
}

void showGanttChart()
{
	for(i=0;i<sch_cnt*5;i++)
		printf("-");
	printf("\n|");

	for(i=0;i<sch_cnt;i++)
		printf("P%d |",sch[i].pid);
	printf("\n");

	for(i=0;i<sch_cnt*5;i++)
		printf("-");
	printf("\n0");

	for(i=0;i<sch_cnt;i++)
		printf("%5d",sch[i].end_time);
}

void print_output()
{
	float avgtat = 0,avgwt =0;
	printf("\n");
	printf("\n PID \tFBT \t Prio \t AT \t FT \t TAT \t WT \n");
	for(i=0;i<np;i++)
	{
		printf("\nP%d \t %d \t %d \t %d \t %d \t %d \t %d\n",i,p[i].first_bt,p[i].priority,p[i].at,p[i].ft,p[i].tat,p[i].wt);
		
	
	
	avgtat = avgtat + p[i].tat;
	avgwt  = avgwt  + p[i].wt;
	}
		
	printf("Average  turn around time : %f",(float)avgtat/np);
	printf("\nAverage waiting time : %f\n",(float)avgwt/np);
}

void main()
{
	take_input();
	//to process first burst time of each process
	while(1)
	{
		int x = getProcessBySJF();
		if(x==-1)    // if no process, will return -1
			break;
		sch[sch_cnt].pid = x;
		ct += p[x].temp_bt;
		p[x].temp_bt = 0;
		p[x].ft = ct;
		sch[sch_cnt].end_time = ct;
		sch_cnt++;
		p[x].tat = p[x].ft-p[x].at;
		p[x].wt = p[x].tat-p[x].first_bt;
	}
	showGanttChart();
	print_output();
	
	/*take_rinput();
	
	//To process Next Burst Time of each process
     
	     while(1)
		{
			int x = getProcessBySJF();
			if(x==-1)    // if no process, will return -1
				break;
			sch[sch_cnt].pid = x;
			ct += p[x].priority_bt;
			p[x].priority_bt = 0;
			p[x].ft = ct;
			sch[sch_cnt].end_time = ct;
			sch_cnt++;
			p[x].tat = p[x].ft-p[x].at;
			p[x].wt = p[x].tat-p[x].first_bt-p[x].next_bt-2;
		}
		showGanttChart();
		print_output();
		
	*/	
}













