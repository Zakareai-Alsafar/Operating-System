/*
	./FourthReq 19 12
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<limits.h>

int main( int argc, char *argv[])
{
if(argc==1)
{
	printf("\nWorring !! ---> Don't Insert argv\nWrite like './FourthReq 19 12'\n");
	return 0;
}
int select=0,n=1;
while(n)
{
printf("--------------------------------------------------\n");
printf("press 1 to Run lab 1 Arathmatic operater using argv int :\n");
printf("press 2 to Run lab 2 write on file :\n");
printf("press 3 to Run lab 3 read & write using argv int :\n");
printf("press 0 to Exit of Program :\n");
printf("Enter Your Chouse:");
scanf("%d",&select);
printf("--------------------------------------------------\n");

switch(select)
{

	case 1 :{
		printf("\nlab1 Running:\n");
		int x= atoi(argv[1]);
		int y= atoi(argv[2]);
		printf("The Values of first= %d\n",x);
		printf("The Values of Second= %d\n",y);
		printf("The Values of Result= %d\n",x+y);
		printf("Done lab1 Finishing\n\n");
		break;
		}
	case 2 :{
		printf("\nlab2 Running:\n");
		FILE *fp;
		fp=fopen("REQ4lab2.txt","w");
		fprintf(fp,"Welcome Zakareai In your File By FPRINTF\n");
		fputs("Welcome Zakareai In your File By FPUTS\n",fp);     //puts( char, fp) for char by char
		printf("Write Masseage in File\n");
		printf("Done lab2 Finishing\n\n");
		fclose(fp);
		break;}

	case 3 :{
		printf("\nlab3 Running:\n");
		FILE *fp;
		char ch;
		//write		
		if((fp=fopen("REQ4lab3.txt","w"))==NULL)
			{
				printf("Cannot open file \n");
				exit(1);
			}
		for(int i=1;i<argc;i++)
		{
			fprintf(fp,"The argv[%d] = ",i);
			fputs(argv[i],fp);
			fputc('\n',fp);
		}

		fclose(fp);

		//Read	
		if((fp=fopen("REQ4lab3.txt","r"))==NULL)
			{
				printf("Cannot open file \n");
				exit(1);
			}
			
		ch = getc(fp);  //read one character
		while(ch!=EOF){
			printf("%c",ch);
			ch=getc(fp);
		}
		fclose(fp);
		printf("Done lab3 Finishing:\n\n");
		break;
		}
	case 0 :{n=0;break;}
}
}
}
