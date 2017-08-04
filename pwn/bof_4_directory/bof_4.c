#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "myasm.h"

int canaryglobal;
char flagbuf[50];
char flagpath[100];

void input(void){
	srand((unsigned)time(NULL));
	char buf[20] = {0};
	strcpy(flagpath,"./flag.txt");
	int canary = 0xabcdefa1 +  rand() % 10;
	canaryglobal = canary;

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
	strcpy(flagpath,"./flag.txt");
	//printf("%p\n",flagpath);
	//printf("%p\n",flagbuf);
	//open_gadget();
	//read_gadget();
	//write_gadget();
	//printf("open_gadget address = %p\n",open_gadget);
	//printf("read_gadget address = %p\n",read_gadget);
	//printf("write_gadget address = %p\n",write_gadget);
	fflush(stdout);
	input();
	return 0;
}
