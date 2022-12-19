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
void search();
char cmd[80],t1[20],t2[20],t3[20],t4[20],ch;
int fp,n;
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
		printf("myshell$");
		fgets(cmd,80,stdin);
		separate();
		if(strcmp(t1,"exit")==0)
		exit(0);
		pid=fork();
		if(pid==-1)
		printf("\n child process not created \n");
		else if(pid==0)
		{
			if(strcmp(t1,"search")==0)
				search();
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
void search()
{
	char s[80];
	int i=0,cnt=0,lc=1;
	fp=open(t3,O_RDONLY);
	if(fp==-1)
	{
		printf("\n file not found\n");
		return;
	}
	while(read(fp,&ch,1))
	{
		if(ch=='\n')
			lc++;
		if(ch ==0 || ch =='\t' || ch==' ')
		{
			s[i]='\0';
			i=0;
			if(strstr(s,t4))
			{
				if(strcmp(t2,"f")==0)
				{
					printf("\n pattern \" %s \" found in \"%s\" at line no:%d\n",t4,s,lc);
					break;
				}
				if(strcmp(t2,"c")==0)
				{
					cnt++;
				}
				if(strcmp(t2,"a")==0)
				{
					printf("\npattern \" %s \" found in \"%s\" at line no:%d\n",s,lc);
					break;
				}
						
			}
		}
		else
		{
		s[i]=ch;
		i++;
		}
	}
	if(strcmp(t2,"c")==0)
	printf("\n Total occurence of given pattern=%d \n",cnt);
			
}		
