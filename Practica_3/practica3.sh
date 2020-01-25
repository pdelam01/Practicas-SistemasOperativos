#!/bin/bash
Error(){
	echo Error, ha de introducir el nombre de 1 directorio solo
}

Ejercicio(){
cd $* >/dev/null		#a partir de aqui siempre nos trabaja con el directorio que le hemos pasado por $*
	while true
	do
	echo Eliga una de estas opciones 
	echo [1]-Numero de archivos
	echo [2]-Numero de subdirecctorios
	echo [3]-Fichero más grande
	echo [4]-Fichero más pequeño
	echo [5]-Espacio total ocupado
	echo [6]-Número de ficheros con permiso de lectura
	echo [7]-Número de ficheros con permiso de escritura
	echo [8]-Número de ficheros con permiso de ejecución
	echo [9]-Ficheros con permiso de ejecución para todos los usuarios
	echo [10]-Salir
echo 
	read input
	case $input in
		1) numero=`ls -l | grep ^- | wc -l`
			echo Numero de archivos: $numero
			echo ;;
		2) numerod=`ls -l | grep ^d | wc -l`
			echo Numero de directorios: $numerod
			echo ;;
		3) numFilesMayor=`ls -lS | grep ^- | head -1`
			echo Archivo de mayor tamaño: $numFilesMayor
			echo ;;
		4) numFilesMenor=`ls -lS | grep ^- | tail -1` #Ordena | selecciona los - (ficheros) | tail (menor) head (mayor)
			echo Archivo menor tamaño: $numFilesMenor
			echo ;;
		5) total=`du -sh | cut -f1 ` #du (disk usage) sh (muestra el total)
			echo Total de espacio utilizado: $total
			echo ;;
		6) lectura=`ls -l | grep ^-r | wc -l`
			echo Archivos permiso de lectura: $lectura #si fuesen directorios, seria ^d
			echo ;; 
		7) escritura=`ls -l | grep ^-.w | wc -l`
			echo Archivos permiso de ecritura: $escritura #busca archivos | selecciona los ficheros que tengan r,w,x | cuenta
			echo ;;  
		8) ejecutable=`ls -l | grep ^-..x | wc -l`
			echo Archivos permiso de ejecucion: $ejecutable
			echo ;;
		9) ejecucionTodos=`ls -l | grep ^-..x..x..x | wc -l`
			echo Archivos permiso ejecucion para todos los usuarios: $ejecucionTodos
			echo ;;
		10) echo Adios! 
			exit 0;;
		*) echo NO! Un número de 1-10!;;
	esac
done
}

if test $# -gt 1 #Si el número de argumentos que se le dan al script es menor que 1, salta
then
Error
	elif test -d $1
	then
		echo $1 Es un directorio
		echo 
		Ejercicio $*
	elif test -f $1
	then
		echo $1 Es un fichero, necesito un directorio!
	else
		echo No existe el argumento que me has pasado!
fi
