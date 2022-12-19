#include<stdio.h>
int main()
{
	int pid,retnice;
	printf("\n press DEL to stop process ");
	pid=fork();
	for(;;)
	{
		if(pid==0)
		{
			retnice=nice(4);
			printf("child gets higher CPU priority %d\n",retnice);
			sleep(1);
		}
		else
		{
			retnice=nice(-5);
			printf("Parent gets lower CPU priority %d \n",retnice);
			sleep(1);
		}
	}


}
