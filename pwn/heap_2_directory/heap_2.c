#include <stdio.h>
#include <stdlib.h>

struct student{
	char name[40];
	void (*student_func)(char *);
};


void print_name(char *name){
	printf("This student is %s!\n",name);
}


void invoke_shell(char *prog_name){
	system(prog_name);
}

int main(void){
	setvbuf(stdin,NULL,_IONBF,0x0);
	setvbuf(stdout,NULL,_IONBF,0x0);
	struct student *s = (struct studnet *)malloc(sizeof(struct student));
	s->student_func = print_name;
	puts("Welcome to heap level2!");
	printf("Please tell me your name... :");
	read(0,s->name,sizeof(struct student));
	s->student_func(s->name);
	return 0;
}

