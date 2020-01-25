#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	pid_t pid;
	int status;
	int i,p;

	for(i=0;i<=3;i++){
		pid=fork();
		if(pid==0){
			printf("Soy el hijo %d, mi padre es %d\n",getpid(),getppid());
			sleep(2);
			exit(i);
		}else{
			p=wait(&status);
			p=WEXITSTATUS(status);
			printf("Soy el padre %d y me ha llegado el valor %d\n",getpid(),p);
			sleep(2);
		}
	}
return 0;
}