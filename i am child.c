#include<stdio.h>
#include<sys/types.h>

void ChildProcess(); /*child process prototype*/
void ParentProcess(); /*parent process prototype*/

int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
		ChildProcess();
	else
		ParentProcess();
	return 0;
}

void ChildProcess()
{
	printf("\nI am child process.. id=> %d",getpid());
}

void ParentProcess()
{
	printf("I am parent process..id=> %d",getpid());
}
