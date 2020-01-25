#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	pid_t mipid,pid, otropid;
	int estado, edad, edadHijo, edadNieto;
	mipid=fork();

	if(mipid==-1){
		perror("Error la llamada a fork() \n");
	}else{
		if(mipid==0){
			otropid=fork();
			if(otropid==0){
				printf("Nieto: el pid de mi padre es: %d\n",getppid()); //se ve que este adquiere el pid del Hijo que es su Padre, no el pid de su Abuelo
			}else{
				printf("Hijo: Mi pid es: %d\n",getpid());
				edadHijo=140;
				exit(edadHijo);
			}
		}else{
			printf("Padre: Mi pid es: %d\n",getpid());
			pid=wait(&estado);
			edad=WEXITSTATUS(estado); //proceso padre puede obtener el valor de los ocho bits 
									  //menos significativos del parámetro que recibe desde lallamada a exit por parte del hijo
			printf("Mi hijo %d ha fallecido a los %d años.\n", pid, edad);
			pid=wait(&estado);   //aqui vemos que nos devuleve -1, por que el hijo ya murio
			printf("pid=%d\n", pid);
		}
	}
return 0;
}