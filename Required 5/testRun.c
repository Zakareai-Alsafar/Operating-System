#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<limits.h>

int main( int argc, char *argv[])
{
	printf("\nNow you in test Run Program System Call :\n\n");
	printf("	the Zero argument = %s\n",argv[0]);
	printf("	the First argument = %s\n",argv[1]);
	printf("	the Second argument = %s\n\n",argv[2]);
}
