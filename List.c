#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdlib.h>

void separate();
void list();
char cmd[80],t1[20],t2[20],t3[20],t4[20],buffer[10];
int n,status,fp,wc,cc,lc;
pid_t pid;
DIR *dp;
struct dirent *de;

void separate()
{
	strcpy(t1,"\0");
	strcpy(t2,"\0");
	strcpy(t3,"\0");
	strcpy(t4,"\0");
	n=sscanf(cmd,"%s %s %s %s",t1,t2,t3,t4);
		
}
int main()
{
	while(1)
	{
		printf("myshell$");
		fgets(cmd,80,stdin);
		separate();
		if(strcmp(t1,"exit")==0)
		exit(0);
		pid=fork();
		if(pid==-1)
		printf("\n child process not created ");
		else if(pid==0)
		{
			if(strcmp(t1,"list")==0)
				list();
				else
				{
					switch(n)
				{
						case 1:
							
								execlp(t1,t1,NULL);
							
							break;
						case 2:
								execlp(t1,t1,t2,NULL);
							break;
						case 3: 
								execlp(t1,t1,t2,t3,NULL);
								
							break;
						case 4:
								execlp(t1,t1,t2,t3,t4,NULL);
							break;
					}
				}
			}
		else
		wait(NULL);
		}
		return 0;
}
void list ()
{
	int cnt=0;
	dp=opendir(t3);
	if(dp==NULL)
	{
		printf("\n %s directory not found ",t3);
	}
	else
	{
		if(strcmp(t2,"f")==0)
		{
			while(1)
			{
			de=readdir(dp);
			if(de==NULL)
				break;
			printf("\n file name:%s",de->d_name);
			
			}
		}
		if(strcmp(t2,"n")==0)
		{
		while(1)
		{
			de=readdir(dp);
			if(de==NULL)
				break;
			cnt++;
		}
		printf("\n total files:%d",cnt);
	}
	if(strcmp(t2,"i")==0)
	{
	while(1)
	{
		de=readdir(dp);
			if(de==NULL)
				break;
		printf("\n file name:%s",de->d_name);
		printf("\n inode no:%ld",de->d_ino);
				
		}
	}
		}
}
