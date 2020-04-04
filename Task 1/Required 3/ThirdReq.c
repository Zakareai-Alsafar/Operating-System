/*
	./ThirdReq
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<limits.h>

	FILE *fp,*Newfp;
	char ch;

void OpenWriteFile()
{
		if((fp=fopen("REQ3TextWrite.txt","a"))==NULL)
		{
			printf("Cannot open file \n");
			exit(1);
		}

}

void OpenReadFile()
{
	if((fp=fopen("REQ3TextWrite.txt","r"))==NULL)
		{
			printf("Cannot open file \n");
			exit(1);
		}
	if((Newfp=fopen("REQ3NewTextWrite.txt","w"))==NULL)
		{
			printf("Cannot open file \n");
			exit(1);
		}
		

}
void WriteByCharAndString(char st[])
{

	fprintf(fp,"Write By charecters :\n");
	for (int i=0;i<strlen(st);i++)  
		putc(st[i],fp); 		//to write charecter by charecter
	putc('\n',fp);		//New Line between Lines

// WriteByString
	fprintf(fp,"\n\nWrite By Strings :\n");
		fputs(st,fp);	//to write String by String
		putc('\n',fp);       //New Line between Lines
	fclose(fp);
}

void ReadFile()
{
	OpenReadFile();
		ch = getc(fp); //read one character
		while(ch!=EOF){
			putc(ch,Newfp); // Write in New File
			printf("%c",ch);
			ch=getc(fp);
		}
	fclose(fp);
}


int main( int argc, char *argv[])
{
char str[50];
printf("Write Your Text To Save In File : ");
scanf("%[^\n]",str); // to read All Line
OpenWriteFile();
WriteByCharAndString(str);
ReadFile();

return 0;
}


