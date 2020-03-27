#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define web_page "page.txt"

/*open a file
 * @fd - file descriptor
 * @filename - the file to open and used as reference for error message
 * @flag - the opening file permissions*/
void open_file(FILE **fd,char *filename,char *flag)
{
	*fd = fopen(filename,flag);
	if(*fd==NULL)
	{
		char error[100]; sprintf(error,"fopen(%s):",filename);
		perror(error);
		exit(EXIT_FAILURE);
	}
}

/*Check file for keyword
 * @fd - file descriptor
 * @keyword - keysection to search the file for*/
void check_file_for_keyword(FILE **fd , char *keyword)
{
	/*open file and read contents checking for section containing keyword in the file*/
	char buf[100];
	char *match , *section , *sample;
	sample = keyword;

	/*read the webpage*/
	while(fread(buf,sizeof(buf),1,*fd))
	{
		section = buf;
		match = strstr(section,sample);
		if(match)
		{	/*print the contents to stdout*/
			printf("%s\n",match);
		}
	}
}

/*close a file
 * @fd - file descriptor
 * @filename - filename of the file to close, used as reference when printing error message*/
void close_file(FILE **fd,char *filename)
{
	if(fclose(*fd)!=0)
	{
		char error[100]; sprintf(error,"fclose(%s):",filename);
		perror(error);
		exit(EXIT_FAILURE);
	}
}


int main()
{

	FILE *fd;

	printf("\t\t*** Coronavirus UK statistics ***\t\t\n");

	open_file(&fd,web_page,"r");

	check_file_for_keyword(&fd,"Coronavirus Cases:");
	
	close_file(&fd,web_page);
		
	return 0;
}
