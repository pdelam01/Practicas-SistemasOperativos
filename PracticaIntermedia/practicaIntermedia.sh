#!/bin/bash

echo -e "                                                                                             "
echo -e "██████╗ ███████╗███████╗████████╗ █████╗ ██╗   ██╗██████╗  █████╗ ███╗   ██╗████████╗███████╗"
echo -e "██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗██╔══██╗████╗  ██║╚══██╔══╝██╔════╝"
echo -e "██████╔╝█████╗  ███████╗   ██║   ███████║██║   ██║██████╔╝███████║██╔██╗ ██║   ██║   █████╗  "
echo -e "██╔══██╗██╔══╝  ╚════██║   ██║   ██╔══██║██║   ██║██╔══██╗██╔══██║██║╚██╗██║   ██║   ██╔══╝  "
echo -e "██║  ██║███████╗███████║   ██║   ██║  ██║╚██████╔╝██║  ██║██║  ██║██║ ╚████║   ██║   ███████╗"
echo -e "╚═╝  ╚═╝╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝   ╚═╝   ╚══════╝"
echo -e "                                                                                             "

while true
do	
	echo -e "\nIntroduzca un numero del 1-4 \n"
	echo -e "[1]-Mostrar codigo del programa" 
	echo -e "[2]-Compilacion programa"  
	echo -e "[3]-Ejecutar programa"  
	echo -e "[4]-Salir \n"
	read input
	case $input in
		1) echo -e "Ha seleccionado: Mostrar el programa \n"
			cat practicaIntermedia.c
			sleep 5;;
		2) echo -e "Ha seleccionado: Compilar el programa \n"
			echo -e "Compilando..."
			sleep 3
			gcc -o restaurante practicaIntermedia.c
			echo "Compilado!";;
		3) echo -e "Ha seleccionado: Ejecutar el programa \n"
			#Comprobamos si existe el archivo restaurante que se genera al compilar el programa
			if test -f restaurante
			then
				#Comprobamos que el ejecutable "restaurante" que se crea al compilar tiene permisos de ejecucion
				if test -x restaurante 
				then
					echo Introduzca el numero de pinches que desea tener en la cocina: 
					read numPinches
					echo -e "Ejecutando..."
					./restaurante $numPinches
				else
					echo -e "No tienes los permisos de ejecucion!"
				fi
			else
				echo -e "No puedes ejecutar el programa sin antes compilarlo!"
			fi;;
		4) echo -e "Ha seleccionado Salir. Adios! \n"
			exit 0;;			
		*) echo -e "Opcion invalida! \n";;
	esac
done
			
