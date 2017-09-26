#include <stdio.h>
#include <stdlib.h>

void flag(void){
	puts("FLAG{XXXXXXXXXXXXXXXXXX}");
	exit(1);
}

void input(void){
	char buf[20] = {0};
	gets(buf);
	printf("Hi, %s\n",buf);
	fflush(stdout);
}

int main(void){
	printf("flag_function_address = %p\n",flag);
	printf("Input your data : ");
	fflush(stdout);
	input();
	return 0;
}
