#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

/*El pid de un proceso nunca cambia durante el tiempo de vida de éste; sin embargo, 
sí puede versemodificado   el   valor   de   su  ppid:   cuando   el   proceso   
padre   muere,   el   proceso   huérfano   pasa   a considerarse como hijo del proceso init, 
entonces el valor de su ppid toma el valor 1
(que es el valordel pid del proceso init)
*/

int main(void){
	pid_t pidproceso,pidpadre;
	pidproceso=getpid();
	pidpadre=getppid();
	printf("Soy el proceso de pid=%d\n", pidproceso);    
	printf("Mi padre es el proceso de pid=%d\n", pidpadre);    
return 0;
}
