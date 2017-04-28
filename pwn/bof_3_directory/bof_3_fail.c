#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int canaryglobal;

void flag(void){
	puts("FLAG{You_can_avoid_mock_SSP!}");
	exit(1);
}

void input(void){
	srand((unsigned)time(NULL));

	char buf[20] = {0};
	int canary = 0xabcdefa1 +  rand() % 10;
	canaryglobal = canary;
	//char buf[10] = {0};
	/*
	int canary;
	__asm__ __volatile__(
		"mov eax,[ebp-0xC]\n\t"
		:"=a" (canary)
		:
		:);
	*/
	printf("Canary = 0x%x\n",canary);
	printf("Input your data : ");
	fflush(stdout);
	gets(buf);
	printf("Hi, %s\n",buf);
	if(canaryglobal != canary){
		puts("Stack Smash Detected!");
		exit(1);
	}
	fflush(stdout);
}

int main(void){
	printf("flag_function_address = %p\n",flag);
	fflush(stdout);
	input();
	return 0;
}
