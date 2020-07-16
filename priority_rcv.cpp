#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

#include <sys/resource.h>


int main(int argc, char *argv[])
{
	char ch;
	int pid ;
	int prio; 
	char alph[26] = {'A','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int indexPriority[26] = {10,11,12,13,14,15,16,17,18,-17,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16};

    // Check if a filename has been specified in the command
	if (argc < 2)
	{
		printf("Missing PID\n");
		return(1);
	}
	else
	{
		pid = atoi (argv[1]);
		printf("PID : %d" , pid);
		fflush(stdout);
	}


	while ( prio != -1)
	{
		prio = getpriority (PRIO_PROCESS, pid);
		printf("Priority : %d\n", prio);
		fflush(stdout);
		
		if (prio == 19){
			printf("%s"," ");
			fflush(stdout);
			sleep (1);						
		}
		else if (prio >= 0 && prio <= 9){
			printf("%d", prio);
			fflush(stdout);
			sleep (1);			
		}
		else {
			for (int i = 0; i < 26; i++){   
				if (pid == indexPriority[i])
				{          
					printf("%c", alph[i]);
					fflush(stdout);
					sleep (1);					
				}
				else {
					sleep (1);
				}
			}
		}		   
	}
	return(0);
}
