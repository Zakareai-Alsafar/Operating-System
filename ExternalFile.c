#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    printf("\n			********************************\n");
    printf("			* Welcome in External File      *\n");
    printf("			* My Process ID is : %d       *\n",(int) getpid()); // to print Process ID
    printf("			************************************* in ExternalFile\n");
    
}

