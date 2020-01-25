#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<signal.h>

int main(){
	pid_t otropid;
	printf("Introduzca el pid del proceso que desea terminar: \n");
	scanf("%d",&otropid);
	kill(otropid,SIGTERM); //Kill envia la señal, 	SIGTERM hace que muera
return 0;
}