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
void typeline();
char cmd[80],t1[20],t2[20],t3[20],t4[20],ch;
int fp,n,m,lc;
pid_t pid;

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
		printf("myshell$\n");
		fgets(cmd,80,stdin);
		separate();
		if(strcmp(t1,"exit")==0)
		exit(0);
		pid=fork();
		if(pid==-1)
		printf("\n child process not created ");
		else if(pid==0)
		{
			if(strcmp(t1,"typeline")==0)
				typeline();
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
void typeline()
{
	lc=0;
	fp=open(t3,O_RDONLY);
	while(read(fp,&ch,1))
	{
		if(ch=='\n')
			lc++;
	}
	//lc=lc+1;
	lseek(fp,0,SEEK_SET);
	if(strcmp(t2,"a")==0)
	{
			while(read(fp,&ch,1))
			{
				printf("%c",ch);
			}
		}
		else
		{
			n=atoi(t2);
			if(n>0)
			{
				while(read(fp,&ch,1))
				{
					printf("%c",ch);
					if(ch=='\n')
						n--;
					if(n==0)
						break;	
				}
			}
			else
			{
				n=-n;

				m=lc-n;
	//			printf("%d%d%d",n,m,lc);
				while(read(fp,&ch,1))
				{
					if(ch=='\n')
						m--;
					if(m==0)
						break;
				}
				while(read(fp,&ch,1))
				{
					printf("%c",ch);
				}
			}
		}
		close(fp);
}		
			
