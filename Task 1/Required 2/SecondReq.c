/*
	./SecondReq Zakareai 1997 8 7
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<limits.h>

	FILE *fp;
	char ch;

void OpenFile()
{
	if((fp=fopen("REQ2WriteByCharAndStringUsingFunction.txt","w"))==NULL)
	{
		printf("Cannot open file \n");
		exit(1);
	}

}

void WriteByCharAndString(int argc, char *argv[])
{
	fprintf(fp,"\"Wellcome in File Write Argv Using Function\"\n\n\nWrite By charecters :\n");
	for (int i=1;i<argc;i++)  //start whit 1 bescues 0 is name of file 
		{
		 for(int j=0;j<strlen(argv[i]);j++)
			putc(argv[i][j],fp); //to write charecter by charecter
		putc(' ',fp);//space between Strings
		}

	fprintf(fp,"\n\nWrite By Strings :\n");
	for (int i=1;i<argc;i++) 	//start whit 1 bescues 0 is name of file 
	{
		fputs(argv[i],fp);	//to write String by String
		putc(' ',fp);       //space between Strings
	} 
	fclose(fp);
}

int main( int argc, char *argv[])
{
if (argc==1){
printf("Worring !!! \nDon't Write anything in file becouse don't have argv !\n");
return 0;
}

OpenFile();
WriteByCharAndString(argc,argv);
printf("Done \nWriting Argv in file using Function have successful \n");
}


