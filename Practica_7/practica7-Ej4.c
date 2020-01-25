#include <pthread.h>
#include <stdio.h>
int a=0; 

void *Hilo1(void *arg) {
 printf ("EL valor de a en el hilo es %d\n", a);
 a++;
 printf ("Nuevo valor de a en el hilo es %d\n", a);
 pthread_exit(NULL);
}
int main() {
 pthread_t t1;
 pthread_create(&t1, NULL, Hilo1, "Soy joinable\n"); //Esto se imprimiría si hiciesemos como en el primer ejercicio, printf del arg0
 pthread_join(t1, NULL);
 printf("El valor después de ejecutar el thread es %d\n", a);
 return 0;
}

/*	EL valor de a en el hilo es 0
	Nuevo valor de a en el hilo es 1
	El valor después de ejecutar el thread es 1 */

