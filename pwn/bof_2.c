#include <stdio.h>

void input(void){
	char buf[20];
	gets(stdin,buf,20);
	printf("%s\n",buf);
}

int main(void){
	printf("Input your data : ");
	input();
	return 0;
}
