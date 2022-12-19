#include<stdio.h>
#include<string.h>
struct process
{
	char name[20];
	int at,bt,ft,tat,wt,st,temp_bt;
}p[10];
int np,i,j,tq;
float avg_tat=0;
float avg_wt=0;
// to accept the info about pes
void take_input()
{
	printf("Enter the no of ps : ");
	scanf("%d",&np);
	printf("Enter the time Quantum: ");
	scanf("%d",&tq);
	for(i=0;i<np;i++)
	{
		printf("Enter the name of the p: ");
		scanf("%s",&p[i].name);
		printf("Enter the arrival time of the p : ");
		scanf("%d",&p[i].at);
		printf("Enter the burst time of the p: ");
		scanf("%d",&p[i].bt);
		p[i].temp_bt=p[i].bt;
		printf("\n\n");
	}
}
// to sort the pes by arriaval time
void sort()
{
	struct process temp;
	for(i=0;i<np;i++)
	{	
		for(j=i+1;j<np;j++)
		{
			if(p[i].at>p[j].at)	
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}

// to calculate the tat n wt
void getprocessbyRR()
{
	int x=0,cnt=0,time=p[0].at;
	printf("\n***********Gantt chart*********\n");
	while(1)
	{
		if(p[x].temp_bt!=0)
		{
			printf("|%d %s ",time,p[x].name);
			if(p[x].temp_bt>=tq)
			{
				p[x].temp_bt=p[x].temp_bt-tq;
				time=time+tq;
			}
			else
			{
				time=time+p[x].temp_bt;
				p[x].temp_bt=0;
			}
			printf("%d |",time);
			if(p[x].temp_bt==0)
			{
				p[x].ft=time;
				p[x].tat=time-p[x].at;
				p[x].wt=p[x].tat-p[x].bt;
				cnt++;
			}
		}
		x++;
		if(x==np)
		{
			x=0;
		}
		if(cnt==np)
			break;
	}
}
//to print the output table
void print_output()
{
	printf("\n\n");
	printf("\n---------------------------------------");	
	printf("\n pname\tat\temp_bt\ttat\twt ");
	printf("\n---------------------------------------");
	for(i=0;i<np;i++)
	{
		printf("\n%s\t%d\t%d\t%d\t%d",p[i].name,p[i].at,p[i].bt,p[i].tat,p[i].wt);
		avg_tat=avg_tat+(float)(p[i].tat);
		avg_wt=(float)avg_wt+(float)(p[i].wt);
	}
	printf("\n-----------------------------------------");
	printf("\nThe avg of the turn around time is %f",avg_tat/np);
	printf("\nThe avg of the waiting time is %f",avg_wt/np);
}

void main()
{
	int i;
	take_input();
	sort();
	getprocessbyRR();
	print_output();
	for(i=0;i<np;i++)
	{
		p[i].temp_bt=p[i].bt=rand()%10+1;
		p[i].at=p[i].bt+2;
	}
	getprocessbyRR();
	print_output();
}
