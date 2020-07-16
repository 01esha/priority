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
 FILE *fp;
 char *filename;
 char ch;
 int pid = getpid(); 
 char alph[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 int indexPriority[26] = {10,11,12,13,14,15,16,17,18,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16, -17, -18};


 printf("My PID is %d\n", pid);
 sleep(10);

  // Check if a filename has been specified in the command
  if (argc < 2)
   {
        printf("Missing Filename\n");
        return(1);
   }
   else
  {
        filename = argv[1];
        printf("Filename : %s\n", filename);
   }

   // Open file in read-only mode
   fp = fopen(filename,"r");

   // If file opened successfully, then print the contents
   if ( fp )
      {
        
        while ( (ch = fgetc(fp)) != EOF )
           {
               if (isspace(ch)) {
                   setpriority(PRIO_PROCESS, pid, 19);
                   printf("%c", ch);
                   sleep (1);
                   }
               if (isdigit(ch)) {
                   setpriority(PRIO_PROCESS, pid, ch);
                   printf("%c", ch);
                   sleep (1);
               }
               if (isalpha(ch)) {
                    for (int i = 0; i < 26; i++){   
                        if (toupper(ch) == alph[i])
                        {          
                        setpriority(PRIO_PROCESS, pid, indexPriority[i]);
                        printf("%c",alph[i]);
                        sleep (1);
                        break;
                        }
                    }
               };            
           }
       setpriority(PRIO_PROCESS, pid, -19); 
       }
   else
      {
         printf("Failed to open the file\n");
        }

return(0);
}
