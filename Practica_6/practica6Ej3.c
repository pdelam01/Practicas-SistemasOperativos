#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void muestraNumero(int sig); // Función de tipo handler
void muestraNumero2(int sig);

int main(int argc, char* argv[]) {
/* Se le asigna el handler a la señal SIGUSR1 */
if (signal(SIGUSR2, muestraNumero)==SIG_ERR) {  //Cambiando sigusr1 por 2 hace que se ejecute al enviarle la señal 12
	perror("Llamada a signal.");
	exit(-1);
	}
	pause();
	for(int i=0; i<10; i++){ //Despues de enviarle la señal, mostrara del 0-9 numeros 
		printf("%d\n",i);
	}

if (signal(SIGUSR1, muestraNumero2)==SIG_ERR) {  //Cambiando sigusr1 por 2 hace que se ejecute al enviarle la señal 12
	perror("Llamada a signal.");
	exit(-1);
	}
	pause();
	printf("Hola\n");

}
/* La proxima vez que se reciba la señal SIGUSR1
* se llamará a la función muestraNumero()
*/

void muestraNumero(int sig) {
/* Se vuelve a asignar el handler a la señal SIGUSR1 */
	if (signal(SIGUSR2, muestraNumero)==SIG_ERR) {
	perror("Llamada a signal.");
	exit(-1);
	}
/* Se ejecuta el código de la rutina de tratamiento */
printf("Número de señal recibida: %d\n", sig);
}

void muestraNumero2(int sig) {
/* Se vuelve a asignar el handler a la señal SIGUSR1 */
	if (signal(SIGUSR1, muestraNumero2)==SIG_ERR) {
	perror("Llamada a signal.");
	exit(-1);
	}
/* Se ejecuta el código de la rutina de tratamiento */
printf("Número de señal recibida: %d\n", sig);
}