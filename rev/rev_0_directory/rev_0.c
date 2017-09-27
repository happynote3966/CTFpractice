#include <stdio.h>
#include <string.h>

char flag[] = "FLAG{Strings_is_very_useful_command!}";

int main(void){
	char buf[50];
	printf("Please input\"You_are_genius\":");
	scanf("%s",buf);
	if(strcmp(buf,"You_are_genius") == 0){
		printf("Thank you :)\n");
	}else{
		printf("Say \"You_are_genius!\"\n");
	}
	return 0;
}
