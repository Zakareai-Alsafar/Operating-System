/*
	./FifthReq run open
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<limits.h>


int main( int argc, char *argv[])
{
if ((!strcmp(argv[1],"run"))&&(!strcmp(argv[2],"open")))
		{
		system("gcc testRun.c -o testRun");
		system("./testRun RUN OPEN");
		}
else printf("Syntax Erorr send as './FifthReq run open'\n");
}
