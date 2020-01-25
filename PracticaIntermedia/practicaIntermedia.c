#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
int calculaAleatorios(int min, int max);
void manejadoraMozo(int s);
void manejadoraPinches(int s);
void manejadoraJefe(int s);
void manejadoraSommelier(int s);

int main(int argc, char* argv[]){
	pid_t *pidcocina;
	pid_t pid,pidsomm,pidpinche;
	int i,min=0, max=1, resultado=0,status,countBien;
	srand(time(NULL));
	struct sigaction sommelier={0};
	struct sigaction pinches={0};
	struct sigaction jefe={0};
	if (argc>2){
		printf("ERROR! Numero de argumentos inválido\n");
		int exit = -1;
		return exit;
	}else{
		int numPinches;
		numPinches=atoi(argv[1]);
		if(numPinches<=0){
			printf("ERROR! No puede haber 0 o negativos pinches en cocina. Contrata pinches!\n");
			exit(-1);
		}else{
			int numTrabajadores;
			numTrabajadores=numPinches+2;
			//Creamos en puntero que contenga en total de trabajadores "hijos" del chef (menos el mozo, hijo del sommelier)		
			pidcocina=(pid_t *)malloc((numTrabajadores+2)*sizeof(pid_t));
			//Creamos los distintos procesos
			for(i=0;i<numTrabajadores;i++){
				pid=fork();
				if(pid==-1){
						perror("ERROR en la llamada al fork\n");
						exit(-1);
				}else{
					if(pid==0){
						if(i==0){
							printf("Soy el Sommelier con id %d. Mi padre es %d\n",getpid(),getppid());
							//Enmascaramos la señal del Sommelier
							sommelier.sa_handler=manejadoraSommelier;
							if (-1==sigaction(SIGUSR1,&sommelier,NULL) || sigaction(SIGUSR2,&sommelier,NULL)==-1){			
								perror("Sommelier: sigaction");
								return(1);
							}
							pause();
						}
						if(i==1){
							printf("Soy el Jefe de cocina con id %d. Mi padre es %d\n",getpid(),getppid());
							//Enmascaramos la señal del Jefe de sala
							jefe.sa_handler=manejadoraJefe;
							if (-1==sigaction(SIGUSR1,&jefe,NULL)){			
								perror("Jefe de sala: sigaction");
								return(1);
							}
							pause();
						}
						if(i>1){
							printf("Soy el Pinche de cocina %d con id %d. Mi padre es %d\n",i-1,getpid(),getppid());
							//Enmascaramos la señal de los Pinches de cocina
							pinches.sa_handler=manejadoraPinches;
							if (-1==sigaction(SIGUSR1,&pinches,NULL)){			
								perror("Pinches: sigaction");
								return(1);
							}
							pause();
						}
					}else{
						pidcocina[i]=pid;	
					}			
				}
			}
			sleep(3);
			resultado=calculaAleatorios(min, max);
			if(resultado==0){
				printf("Chef: Faltan ingredientes!\n");
				//Enviamos al Sommelier la senial SIGUSR1
				kill(pidcocina[0],SIGUSR1);
			}else{ 
				printf("Chef: Falta vino!\n");
				//Enviamos al Sommelier la senial SIGUSR2
				kill(pidcocina[0],SIGUSR2);
			}
			//Esperamos  al valor que nos envia el Sommelier
			pidsomm=wait(&status);
			//Si es un 1, no se puede abrir el restaurante
			if(WEXITSTATUS(status)==1){
				printf("Sommelier: Chef... no hemos encontrado el vino \n");
				printf("Chef: Imposible abrir el restaurante... CERRAMOS\n");
				for(i=0;i<numTrabajadores;i++){
					//Matamos todos los procesos hijo
					kill(pidcocina[i],SIGKILL);
				}
			}else{
				//Si el Sommelier nos devuelve un 2, no se han encontrado los ingredientes
				if(WEXITSTATUS(status)==2){
					printf("Sommelier: Lo sentimos Chef, no hemos encontrado los ingredientes \n\n");
					printf("*LOS PINCHES SE PONEN MANOS A LA OBRA*\n");
					for(i=2;i<numTrabajadores;i++){
						kill(pidcocina[i],SIGUSR1);
						pidpinche=wait(&status);
						if(WEXITSTATUS(status)==0){
							printf("Pinche %d: Se ha cocinado bien el plato!\n",(i-1));
							countBien++;		
						}else{
							printf("Pinche %d: No se ha cocinado bien el plato...\n",(i-1));						
						}
					}
					if(countBien==0){
						printf("Chef: Todos los platos se han cocinado mal. Esto es una verguenza! Hoy no se abre el restaurante\n");
						//Si ningun plato se ha cocinado bien, matamos todos los procesos
						for(i=0;i<numTrabajadores;i++){
							kill(pidcocina[i],SIGKILL);
						}
					}else{
						printf("Total de platos bien cocinados: %d \n",countBien);
						//Enviamos señal SIGUSR1 al Jefe de sala
						kill(pidcocina[1],SIGUSR1);
						sleep(10);
						printf("ABRIENDO RESTAURANTE\n");
						for(i=0;i<numTrabajadores;i++){
							kill(pidcocina[i],SIGKILL);
						}
					}
				}else{
					//Si el Sommelier nos devuelve un 3, se han encontrado los ingredientes
					//Procedemos de igual manera que en el caso anterior
					printf("Sommelier: Buenas noticias Chef, hemos encontrado todo \n\n");
					printf("*LOS PINCHES SE PONEN MANOS A LA OBRA*\n");
					for(i=2;i<numTrabajadores;i++){
						kill(pidcocina[i],SIGUSR1);
						pidpinche=wait(&status);
						if(WEXITSTATUS(status)==0){
							printf("Pinche %d: Se ha cocinado bien el plato!\n",(i-1));
							countBien++;
						}else{
							printf("Pinche %d: No se ha cocinado bien el plato...\n",(i-1));
						}
					}
					if(countBien==0){
						printf("Chef: Todos los platos se han cocinado mal. Esto es una verguenza! Hoy no se abre el restaurante\n");
						for(i=0;i<numTrabajadores;i++){
							kill(pidcocina[i],SIGKILL);
						}
					}else{
						printf("Total de platos bien cocinados: %d \n",countBien);
						kill(pidcocina[1],SIGUSR1);
						sleep(10);
						printf("ABRIENDO RESTAURANTE\n");
						for(i=0;i<numTrabajadores;i++){
							kill(pidcocina[i],SIGKILL);
						}

					}
				}
			}
		}
	}
free(pidcocina);
return 0;
}


int calculaAleatorios(int min, int max) {
return rand() % (max-min+1) + min;
}

void manejadoraMozo(int s){
	//La manejadora del mozo llama a la funcion calculaAleatorios y envia dicho numero con exit al Sommelier
	int min=0,max=1,resultado=0;
	srand(time(NULL));
	resultado=calculaAleatorios(min, max);
		exit(resultado);
}

void manejadoraPinches(int s){
	int min=2,max=5,resultadoDormir=0,resultado=0;
	srand(time(NULL));
	//Calculamos un aleatorio entre 2-5. Los pinches dormirán dicha cantidad de segundos
	resultadoDormir=calculaAleatorios(min, max);
	sleep(resultadoDormir);
	//Calculamos un aleatorio entre 0-1 (plato bien/mal cocinado) y enviamos el valor con exit al Chef
	resultado=calculaAleatorios(0, 1);
		exit(resultado);
}

void manejadoraJefe(int s){
	//La manejadora del Jefe de sala: duerme 3s y muestra un mensaje por pantalla
	sleep(3);
	printf("Jefe de sala: Chef! Se han montado todas las mesas \n");
	exit(1);
}


void manejadoraSommelier(int s){
	int status;
	pid_t pidw;
	srand(time(NULL));
	struct sigaction mozoSom={0};
	pid_t mozo=fork();
	if(mozo==-1){
		printf("ERROR\n");
	}else{
		if(mozo==0){
			printf("Soy el Mozo con id %d. Mi padre es %d\n",getpid(),getppid());
			//Armamaos la manejadora del mozo y la enmascaramos
			mozoSom.sa_handler=manejadoraMozo;
			if (-1==sigaction(SIGPIPE,&mozoSom,NULL)){			
				perror("Mozo: sigaction");
			}
			pause();
		}else{
			sleep(5);
			kill(mozo,SIGPIPE);
			pidw=wait(&status);
			if(WEXITSTATUS(status)==1){
				printf("Mozo: He encontrado lo que faltaba! \n");
				exit(3);
			}else{
				if(WEXITSTATUS(status)==0 && s==SIGUSR2){
					printf("Mozo: Oh no! No he encontrado el vino... \n");
					exit(1);
				}else{
					if(WEXITSTATUS(status)==0 && s==SIGUSR1){
						printf("Mozo: Vaya por Dios, no he encontrado los ingredientes que faltaban \n");
						exit(2);
					}
				}
			}
		}
	}
}
