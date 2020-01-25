#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main(){
	printf("Arrancando...\n"); //Esto lo ejecuta el padre solo

	pid_t mipid;
	int a=5;
	mipid=fork();

	if(mipid==-1){
		perror("Error la llamada a fork() \n");
	}else{
		if(mipid==0){
			a=a+2;
			printf("Hijo: Mi pid es: %d\n",getpid());
			printf("El valor de a es: %d\n",a);
		}else{
			a=a+1;
			printf("Padre: Mi pid es: %d\n",getpid());//si ponemos ppid, ponemos al padre del padre (este getpid es su propio pid)
			printf("El valor de a es: %d\n",a);
		}
		
	}
	printf("Finalizando...\n"); //Esto lo ejecutan ambos, hijo y padre, por eso al ejecutar el programa sale dos veces
return 0;
}