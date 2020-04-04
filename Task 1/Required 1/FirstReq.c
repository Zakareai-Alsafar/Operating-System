/*
	./FirstReq Zakareai 1997
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<limits.h>
	FILE *fp;
	char ch;
int main( int argc, char *argv[])
{
if (argc==1){
printf("Worring !!!\n");
printf("Don't Write Anything in file becouse don't have argv !\n");
printf("Pleas Write like this './FirstReq 2020 4'\n\n");
return 0;
}

if((fp=fopen("REQ1WriteByCharAndString.txt","w"))==NULL)
		{
			printf("Cannot open file \n");
			exit(1);
		}

// WriteByChar
	fprintf(fp,"\"Wellcome in File Write\"\n\n\nWrite By charecters :\n");
	for (int i=1;i<argc;i++)  //start whit 1 bescues 0 is name of file 
		{
		 for(int j=0;j<strlen(argv[i]);j++)
			putc(argv[i][j],fp); //to write charecter by charecter
		putc(' ',fp);//space between Strings
		}


// WriteByString

	fprintf(fp,"\n\nWrite By Strings  :\n");
	for (int i=1;i<argc;i++) 	//start whit 1 bescues 0 is name of file 
	{
		fputs(argv[i],fp);	//to write String by String
		putc(' ',fp);       //space between Strings
	} 
	fclose(fp);

printf("Done \nWriting Argv in file have successful \n");
}



