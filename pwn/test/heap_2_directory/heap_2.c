#include <stdio.h>
int main(void){
	setvbuf(stdin,NULL,_IONBF,0x0);
	setvbuf(stdout,NULL,_IONBF,0x0);
	return 0;
}

