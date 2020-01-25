#include <pthread.h>
#include <stdio.h> 

void *Hilo(void *arg) {			//void* nos permite pasarle cualquier cosa
 printf ("%s\n",(char *)arg);
 pthread_exit (NULL);
}


// gcc -o practica7ej1 practica7-Ej1.c -pthread


int main() {
 pthread_t t1, t2; //definimos los procesos
 pthread_create (&t1, NULL, Hilo, "Ejecuta un hilo");    //los creamos
 pthread_create (&t2, NULL, Hilo, "Ejecuta otro hilo");
 printf("Fin del thread principal\n");
 return 0;
}

//Por cada ejecucion saldrá algo distinto. Es programacion concurrente