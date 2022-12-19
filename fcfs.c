#include<stdio.h>
#include<string.h>
struct job
{
	char name[20];
	int at,bt,ct,tat,wt,st,tbt;

}job[10];
int n,i,j;
float avg_tat=0;
float avg_wt=0;
void take_input()
{
	printf("\n enter the no of process: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the arrival time of the process %d ",i);
		scanf("%d",&job[i].at);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of the process %d ",i);
		scanf("%d",&job[i].bt);
		job[i].tbt=job[i].bt;
	}
	for(i=0;i<n;i++)
	{
		printf("Enter the name of the process %d ",i);
		scanf("%s",&job[i].name);
		
	}
}
void sort()
{
	struct job temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(job[i].at>job[j].at)
			{
				temp=job[i];
				job[i]=job[j];
				job[j]=temp;
			}
		}
	}
}
void process()
{
	int time=job[0].at;
	for(j=0;j<n;j++)
	{
		job[j].st=time;
		printf("| %d %s ",job[j].st,job[j].name);
		time=time+job[j].tbt;
		job[j].ct=time;
		job[j].tat=time-job[j].at;
		job[j].wt=job[j].tat-job[j].tbt;
		printf("%d |",time);
	}
}
void print_output()
{
	printf("\n \n");
	printf("\n------------------------------------------------");
	printf("\nPname          AT         BT        TAT          WT");
	printf("\n--------------------------------------------------");
	for(i=0;i<n;i++)
	{
		printf("\n%s        %8d         %5d        %4d       %3d",job[i].name,job[i].at,job[i].bt,job[i].tat,job[i].wt);
		avg_tat=avg_tat+(float)(job[i].tat);
		avg_wt=(float)avg_wt+(float)(job[i].wt);
	}
	printf("\n-------------------------------------------------------");
	printf("\n The avg of the  <turn around time is %f ",avg_tat/n);
	printf("\n The avg of the  waiting time is %f ",avg_wt/n);
}
int main()
{
	int i;
	take_input();
	sort();
	process();
	print_output();
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		job[i].tbt=job[i].bt=rand()%10+1;
		job[i].at=job[i].ct+2;
		
	}
	process();
	print_output();
}


