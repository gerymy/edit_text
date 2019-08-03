#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int i;
	int file_descriptor;
	char text[]="Hello, world!";
	char chtenie;
	file_descriptor=creat("test.txt",0666);//создаём или обнуляем файл
	write(file_descriptor,text,strlen(text));//записываем строку текст
	close(file_descriptor);
	file_descriptor=open("test.txt",O_RDONLY);//открываем файл для чтения
	off_t k=lseek(file_descriptor,0,SEEK_END);//определяем длину файла
	for(i=0;i<=k-1;i++)//цикл чтения файла и записи наоборот
		{
		lseek(file_descriptor,-1-i,SEEK_END);
		read(file_descriptor, &chtenie,1);
		printf(" %c ", chtenie);
		}
	close(file_descriptor);
	printf("\n");
	return 0;
}
