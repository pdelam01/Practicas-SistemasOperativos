#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int tam=100;

//v[2]----*(p+2)
//argc=#
//void numFiles(char cmd, char* directorio) --- 

int main(int argc, char *argv[]){
int seleccion, num;
char* directorio;
directorio=(char*)malloc(tam*(sizeof(char)));
char cmd[100];

	if (argc < 1 || argc>2){
		printf("ERROR! Ha de pasar 1 argumento\n");
		int exit = -1;
		return exit;
	}else{
		if (argc==2){
			strcpy(directorio,argv[1]);
			sprintf(cmd,"test -d %s",directorio);
			int retorno=system(cmd);
			num=1;
			if(retorno!=0){
				printf("ERROR! El argumento pasado no es un directorio!\n");
				exit(-1);
			}
		}else{
			strcpy(directorio,".");
			num=1;
		}
	}

	if (num=1){
		do{
			printf("\nEliga una de estas opciones: \n\n");  
			printf("[1]-Numero de archivos \n");
			printf("[2]-Numero de subdirecctorios \n"); 
			printf("[3]-Fichero más grande \n"); 
			printf("[4]-Fichero más pequeño \n"); 
			printf("[5]-Espacio total ocupado \n"); 
			printf("[6]-Número de ficheros con permiso de lectura \n"); 
			printf("[7]-Número de ficheros con permiso de escritura\n"); 
			printf("[8]-Número de ficheros con permiso de ejecución \n"); 
			printf("[9]-Ficheros con permiso de ejecución para todos los usuarios\n"); 
			printf("[10]-Salir\n"); 
			scanf("%d",&seleccion);
		
			switch(seleccion){
			case 1:
				printf("Numero de archivos: \n");
				sprintf(cmd,"ls -l %s| grep ^- | wc -l ", directorio);   //guardamos en cmd el numero de archivos del directorio pasado
				system(cmd);
				break;
			case 2:
				printf("Numero de directorios: \n");
				sprintf(cmd,"ls -l %s| grep ^d | wc -l",directorio);
				system(cmd);
				break;
			case 3:
				printf("Archivo de mayor tamaño: \n");
				sprintf(cmd,"ls -lS %s| grep ^- | head -1", directorio);
				system(cmd);
				break;
			case 4:
				printf("Archivo menor tamaño: \n");
				sprintf(cmd,"ls -lS %s| grep ^- | tail -1", directorio);
				system(cmd);
				break;
			case 5:
				printf("Total de espacio utilizado: \n");
				sprintf(cmd,"du -sh %s| cut -f1",directorio);
				system(cmd);
				break;
			case 6:
				printf("Archivos permiso de lectura: \n");
				sprintf(cmd,"ls -l %s| grep ^-r | wc -l",directorio);
				system(cmd);
				break;
			case 7:
				printf("Archivos permiso de ecritura: \n");
				sprintf(cmd,"ls -l %s| grep ^-.w | wc -l",directorio);
				system(cmd);
				break;
			case 8:
				printf("Archivos permiso de ejecucion: \n");
				sprintf(cmd,"ls -l %s| grep ^-..x | wc -l",directorio);
				system(cmd);
				break;
			case 9:
				printf("Archivos permiso ejecucion para todos los usuarios: \n");
				sprintf(cmd,"ls -l %s| grep ^-..x..x..x | wc -l",directorio);
				system(cmd);
				break;
			case 10:
				printf("Adios! \n");
				break;
			default: 
				printf("NO! Un número de 1-10!\n\n");
			}
		}while((seleccion!=10));
	}

free(directorio);
return 0;
}