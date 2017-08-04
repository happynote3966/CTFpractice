#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <unistd.h>

#include "myasm.h"

int canaryglobal;
char flagbuf[50];
char flagpath[100];

void input(void){
	srand((unsigned)time(NULL));
	char buf[20] = {0};
	strcpy(flagpath,"./flag.txt");
	printf("flagpath = %p\n",flagpath);
	printf("flagbuf = %p\n",flagbuf);
	int canary = 0xabcdefa1 +  rand() % 10;
	canaryglobal = canary;

	printf("Canary = 0x%x\n",canary);
	printf("Input your data : ");
	fflush(stdout);
	read(0,buf,100);
	printf("Hi, %s\n",buf);
	if(canaryglobal != canary){
		puts("Stack Smash Detected!");
		exit(1);
	}
	fflush(stdout);
}

int main(void){
	input();
	return 0;
}
