#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    printf("Welcome in External File\n");
    printf("My Process ID is : %d\n",(int) getpid()); // to print Process ID
    
}
