#include <stdio.h>
#include <string.h>

char compare[] = "Input_this_string";
int flag = 0xdeadbeef;

int main(void){
	char buf[50];
	char flagbuf[10];
	
	printf("Input:");
	scanf("%s",buf);
	if(strcmp(buf,compare) == 0){
		printf("FLAG{%x}\n",flag);
	}else{
		printf("Incorrect!\n");
	}

	return 0;
}
