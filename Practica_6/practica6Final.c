//signal(SIGINT, SIG_DFL); Hace q siempre se ejecute la señal a pesar de hacer ctr-c


//PRACTICA INTERMEDIA


//trazas son printf del mensaje: soy el pinche, el somelier...
//shell scrip while y switch dentro
//salto linea echo -e "..../n"
//cat: cat programa.c
//hacer comentarios, huir variables globales

/*PRIMERA PARTE:
	-trabajar con punteros
	pid_t *pidcocina 		pidcocina=(pid_t *)malloc(n+2*sizeof)(pid_t))
	while(1) pause
	enviar señal sigaction o signal (armar manejadora)
	sigaction seria==  struct sigactionjefe
						jefe.sa_handler=monta_mesa;

	despues de armar señal deben esperar.
	opcion proceso devuelva un valor wexitestatus que se lo devuelve al padre (somelier a chef)
*/

switch(i){
							case 0: printf("Soy el Sommelier %d con id %d. Mi padre es %d\n",i,getpid(),getppid());
								somelier.sa_handler=manejadora;
								if (-1==sigaction(SIGUSR1,&somelier,NULL)){			
									perror("Sommelier: sigaction");
								}
								pause();
								break;
							case 1: printf("Soy el Jefe de cocina %d con id %d. Mi padre es %d\n",i,getpid(),getppid());
								pidcocina[1]=getpid();
								break;
							default: printf("Soy el pinche %d con id %d. Mi padre es %d\n",i,getpid(),getppid());
								break;
							
						}
					}else{
						printf("Soy el chef \n");
						pidcocina[0]=getpid();
					}