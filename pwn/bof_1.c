#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigHandler(int sig){
	printf("Ouch!\n");
}

int main(void){
	char buf[20];
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

}
