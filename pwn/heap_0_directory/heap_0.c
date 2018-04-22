#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char password[] = "HE4P_EXPL01T4T10N";
char flag[50];


void read_flag(void){
	int fd;

	fd = open("flag.txt",'r');
	read(fd,flag,50);
	close(fd);	
}

int main(void){
	read_flag();

	puts("Welcome to the first heap question...");
	printf("Input your password : ");

	char *ptr = (char*)malloc(0x20);

	read(0,ptr,0x20);
	ptr[strlen(ptr) - 1] = '\0';

	if(strcmp(ptr,password)){
		puts("WRONG!");
	}else{
		puts(flag);
	}

	free(ptr);

	return 0;
}
	
