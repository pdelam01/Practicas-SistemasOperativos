#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int return_value=10;

void *Hilo2(void *arg) {
 	printf("%s\n", (char *)arg);
	sleep(10);
	pthread_exit(NULL);
}

void *Hilo1(void *arg) {
 	printf ("%s\n", (char *)arg);
 	pthread_exit((void *)(int)return_value);
}

int main() {
	pthread_t t1, t2;
 	pthread_attr_t attr;
	int ret1;
 	// Inicializacion del attributo
 	if (pthread_attr_init(&attr) != 0) {
 		perror("Error en la creación de la estructura de los atributos.");
	 	exit(-1);
 	}
 	
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 	pthread_create (&t1, &attr, Hilo1, "Soy joinable");
 	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
 	pthread_create (&t2, &attr, Hilo2, "Soy detached");
 	pthread_join(t1, (void **)&ret1);
 	printf("El thread joinable terminó con retval='%d'\n", ret1);
 	return 0;
}
