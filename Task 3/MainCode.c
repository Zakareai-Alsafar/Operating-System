#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int main()
{
    pid_t ReturnValue,ReturnChildValue , PID;   // Variable to Return frok Function. Note: sometime return value Without 32bit
    int status;
    printf("\nParent Process (main)\n");
    printf("The Main ID is : %d\n",(int) getpid()); // to print Process ID
    
    ReturnValue = fork();
    
    if(ReturnValue < 0)
    {
        //frok is Faild
        printf("We Have External Error : Sometime Don't have Space Memory\n");
    }
    else if (ReturnValue == 0)
    {
        //Child Process
        for(int i=0;i<1000000;i++); //Delay
        printf("\n	Child Process\n");
	printf("	--------------------------------\n");
        printf("	The Child Process ID is : %d\n",(int) getpid()); // to print Child Process ID
	ReturnChildValue=fork();
	if(ReturnChildValue<0)
	{
        printf("We Have External Error\n");
	}
	else if (ReturnChildValue==0)
	{
	//Child of Child Process
	printf("\n		Child of Child Process\n");
	printf("		--------------------------------\n");
        printf("		The Child of Child Process ID is : %d\n",(int) getpid()); // to print Child Process ID
        char * args[] = {"./ExternalFile",NULL}; // Pointer To External File
        execv(args[0] , args);  //int execv(const char *path, char *const argv[]);  To Run External File 
        printf ("Coming Back To Child of Child Process \n");	//Don't Print Becouse EXECV Replace The Work
	return 22; //Return Status to test
	}
	else
	{
	//Back in Child Process
	PID = wait(&status); // Waiting for the Child of Child to finish.
	printf("\n	Back in Child Process\n");
	printf("	-----------------------------------------------------------\n");
	printf("	-Note: This Statment Don't Run in Child of Child:         -\n");
	printf("	-	printf (\"Coming Back To Child of Child Process\")  -\n");
	printf("	-	return 22;                                        -\n");// To discribe
	printf("	-Becouse EXECV Replace The Work                           -\n");
        printf("	-Return Status of Child of Child is: %d                    -\n",(int) WEXITSTATUS(status)); // Print 0 Becouse EXECV Replace The Work
        printf("	-Coming Back To Child Process                             -\n");
	printf("	-----------------------------------------------------------\n");
        return 22; //Return Status to test
	}
    }
    else    // ReturnValue > 0
    {
        //Parent Process
        PID = wait(&status); // Waiting for the Child to finish.
        printf("\nParent Process (main)\n");
	printf("--------------------------------\n");
        printf("The Parent Process ID is : %d\n",(int) getpid()); // to print Parent Process ID
        printf("The Child  Process ID is : %d\n",(int) PID); // to print Parent Process ID
        printf("Return Status of Child is: %d\n",(int) WEXITSTATUS(status)); // Print 22 Becouse Fork Keep The Work
	printf("Return Status = 22 ,Becouse Fork Keep The Work\n" );
	printf("--------------------------------\n");
    }
}
