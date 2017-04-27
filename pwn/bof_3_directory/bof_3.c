#include <stdio.h>
#include <stdlib.h>

void flag(void){
	puts("FLAG{You_can_avoid_SSP!}");
	exit(1);
}

void input(void){
	char buf[20] = {0};
	int canary;
	__asm__ __volatile__(
		"mov eax,[ebp-0xC]\n\t"
		:"=a" (canary)
		:
		:);
	printf("Canary = 0x%x\n",canary);
	printf("Input your data : ");
	fflush(stdout);
	gets(buf);
	printf("Hi, %s\n",buf);
	fflush(stdout);
}

int main(void){
	printf("flag_function_address = %p\n",flag);
	fflush(stdout);
	input();
	return 0;
}
