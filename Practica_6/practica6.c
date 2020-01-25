#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t mipid,mipid2;
	int status, status2;

		if(mipid=fork()==0){
			printf("Soy el primer hijo (%d, hijo de %d)\n",getpid(),getppid());
		}else{
			if(mipid2=fork()==0){
				printf("Soy el segundo hijo (%d, hijo de %d)\n",getpid(), getppid());
			}else{
				waitpid(mipid,&status,0);
				waitpid(mipid,&status2,0);
				printf("Soy el padre\n");
			}
		}
return 0;
}