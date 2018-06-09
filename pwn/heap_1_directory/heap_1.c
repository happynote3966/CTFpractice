#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FIRST_NAME_SIZE 0x20
#define MAX_LAST_NAME_SIZE 0x20
#define MAX_NAME_SIZE 0x30

char flag[50];



void read_flag(void){
	int fd;

	fd = open("flag.txt",'r');
	read(fd,flag,50);
	close(fd);	
}

int main(void){
	char *name;
	void *target;
	unsigned int size;
	setvbuf(stdin,NULL,_IONBF,0);
	setvbuf(stdout,NULL,_IONBF,0);
	read_flag();

	puts("Welcome to the second heap question...");
	
	name = (char *)malloc(sizeof(char) * MAX_NAME_SIZE);
	target = (void *)malloc(0x10);
	size = malloc_usable_size(target);
	printf("Target chunk usable size is %d\n",size);
	printf("Input your name : ");
	gets(name);

	if(malloc_usable_size(target) == '@'){
		puts("Second stage CLEAR!!");
		puts(flag);
		exit(0);
	}

	printf("Welcome %s ! Anyway, did you overwrite chunk size?",name);

	free(target);
	free(name);

	return 0;
}
	
