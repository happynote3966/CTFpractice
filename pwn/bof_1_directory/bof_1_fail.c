#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigHandler(int sig){
	printf("FLAG{You_can_input_data_which_cause_BOF!}\n");
	//fflush(stdout);
	exit(1);
}
/*
void input(void){
	char buf[100];
	gets(buf);
	return;
}
*/
int main(void){
	char buf[10];
	printf("Input data : ");
	//fflush(stdout);
	struct sigaction newAct;
	sigemptyset(&newAct.sa_mask);
	sigaddset(&newAct.sa_mask,SIGSEGV);
	newAct.sa_sigaction = sigHandler;
	newAct.sa_flags = SA_SIGINFO|SA_RESTART|SA_ONSTACK;
	if(sigaction(SIGSEGV,&newAct,NULL) == -1){
		fprintf(stderr,"Failed to set my signal handler.\n");
		exit(1);
	}
	gets(buf);
	printf("Can you make BOF?\n");
	//fflush(stdout);
	return 0;
}
