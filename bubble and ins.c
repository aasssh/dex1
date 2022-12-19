#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
void bubble(int *,int);
void inst(int *,int);
int main()
{
	pid_t pid;
	int n,i,j,temp,a[10];
	printf("\n Enter number of elements of an array:");
	scanf("%d",&n);
	printf("\n store the elements in the array ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	pid=fork();
	if(pid<0)
	{
		perror("fork() failure");
		return 1;
	}
	if(pid==0)
	{
		printf("This is a child process\n");
		inst(a,n);
	}
	else
	{
		wait(NULL);
		printf("This ia parent process\n");
		bubble(a,n);
	}
	return 0;

}
void bubble(int *a,int n)
{
	printf("in bubblesort\n ");
	int i=0,j=0,temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("\n%d",a[i]);
	

}
void inst(int *a,int n)
{
	printf("in insertion sort\n");
	int i=0,j=0,t=0;
	for(i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		while(j>=0 && t<a[j])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=t;
	}
	for(i=0;i<n;i++)
		printf("\n%d",a[i]);

}
