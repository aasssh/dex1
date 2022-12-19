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
void count();
char cmd[80],t1[20],t2[20],t3[20],t4[20],buffer[10];
int n,status,fp,wc,cc,lc;
pid_t pid;
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
			if(strcmp(t1,"count")==0)
				count();
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
		waitpid(pid,&status,0);
		}
}


void count()
{
	int lc=0,wc=0,cc=0;
	fp=open(t3,O_RDONLY);
	if(fp!=-1)
	{
	while(read(fp,buffer,1))
	{
	if(buffer[0]==' ' || buffer[0]=='\t' || buffer[0]=='\n')
	{
			wc++;
			cc++;
	}
		else
			cc++;
			if(buffer[0]=='\n')
			lc++;
	}
	}
	else
		printf("\n file %s is not found\n",t3);
		if(strcmp(t2,"w")==0)
			printf("\n word count is %d\n",wc);
		if(strcmp(t2,"l")==0)
			printf("\n line count is %d\n",lc);
		if(strcmp(t2,"c")==0)
			printf("\n character count is %d\n",cc);
			close(fp);	
}
void separate()
{
	strcpy(t1,"\0");
	strcpy(t2,"\0");
	strcpy(t3,"\0");
	strcpy(t4,"\0");
	n=sscanf(cmd,"%s %s %s %s",t1,t2,t3,t4);
		
}
