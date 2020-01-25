#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int a=0;
int main()
 {
 pid_t hijo=fork();
 if (hijo==-1) {
 perror("Error en la llamada a fork()");
 exit(-1);
 } else if (hijo==0) {
 printf("El valor de a en el proceso hijo es %d\n", a);
 a++;
 printf("Nuevo valor de en el proceso hijo es %d\n", a);
 } else {
 hijo=wait(NULL);
 printf("El valor después de crear/terminar el proceso hijo es %d\n", a);
 }
 return 0;
}

/* El valor de a en el proceso hijo es 0
Nuevo valor de en el proceso hijo es 1
El valor después de crear/terminar el proceso hijo es 0 */
