#include <stdio.h>

int main(void){
	//int flag = 0x11451419;
	char buf[101];
	unsigned int flag = 0xdeadbeef;
	int i;
	printf("This is the question of Format String Bug (FSB).\nRead the value of variable with Format String Attack(FSA).");
	printf("If you input \"retire\",then, program will be exit.");
	printf("Hint:value is meaning. Are you \'innmu\'?");
	while(flag == 0xdeadbeef){
		fgets(buf,100,stdin);
		printf(buf);
		for(i = 0; i < 101; i++){
			buf[i] = '\0';
		}
	}
	return 0;
}
