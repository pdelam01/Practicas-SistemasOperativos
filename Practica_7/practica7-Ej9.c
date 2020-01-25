#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#define N 5.0
void *hilo(void *ptr) {
 int x;
 printf("COMIENZO TAREA HILO\n");
 srand((int)pthread_self());
 x=1+(int)(N*rand()/ RAND_MAX +1.0); // X es un número aleatorio entre 1 y N 
 sleep(x);
 printf("FIN TAREA HILO : Tiempo ejecucion %d\n",x);
}
int main() {
 pthread_t t1, t2, t3, t4, t5;
 pthread_create(&t1, NULL, hilo, NULL);
 pthread_create(&t2, NULL, hilo, NULL);
 pthread_create(&t3, NULL, hilo, NULL);
 pthread_create(&t4, NULL, hilo, NULL);
 pthread_create(&t5, NULL, hilo, NULL);
 printf("Van a comenzar los hilos :\n");
 pthread_exit(NULL);
 return 0;
} 