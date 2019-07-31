#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int file_descriptor;
	char text[]="Hello, it's me";
	char buff[20]={0};
	file_descriptor=creat("test.txt",0666);
	write(file_descriptor,text,14);
	read(file_descriptor,&buff,14);
	close(file_descriptor);
	printf("hello %s \n", buff);
	file_descriptor=open("test.txt",O_RDONLY);
	read(file_descriptor, &buff, 20);
	printf("2: %s \n",buff);
	close(file_descriptor);
	return 0;
}
