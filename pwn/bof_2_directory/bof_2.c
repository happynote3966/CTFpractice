#include <stdio.h>
#include <stdlib.h>

void flag(void){
	puts("FLAG{Can_you_get_EIP?}");
	exit(1);
}

void input(void){
	char buf[20] = {0};
	gets(buf);
	printf("Hi, %s\n",buf);
}

int main(void){
	printf("flag_function_address = %p\n",flag);
	printf("Input your data : ");
	fflush(stdout);
	sleep(5);
	input();
	return 0;
}