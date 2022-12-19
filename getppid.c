#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int pid=fork();
	if(pid>0)
	{
		printf("Parent Process ");
		printf("ID:%d\n\n",getpid());
	
	}
	else if(pid==0)
	{
		printf("child process");
		printf("ID: %d\n",getpid());
		printf("Parent--- -ID:%d",getppid());
		sleep(10);

		printf("child process");
		printf("ID %d\n",getpid());
		printf("Parent-- -ID:%d",getppid());
	}

}
