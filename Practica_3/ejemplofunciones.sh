#!/bin/bash
function sumar()
{
	result=`expr $1 + $2`
	echo $result
}

function restar()
{
	result=`expr $1 - $2`
	echo $result
}

function multiplicar()
{
	result=`expr $1 \* $2`
	echo $result
}

while true
do
	echo Introduzca un numero del 1-3 o pulse 0 para salir
	echo [1]-SUMAR  [2]-RESTAR  [3]-MULT  [0]-OUT
	read input
	case $input in
		1) echo Ha seleccionado Sumar
			echo Introduzca un numero
			read num1
			echo Introduzca otro numero
			read num2
			suma=`sumar $num1 $num2`
			echo La suma de $num1 y $num2 es: $suma;;
		2) echo Ha seleccionado Restar
			echo Introduzca un numero
			read num1
			echo Introduzca otro numero
			read num2
			resta=`restar $num1 $num2`
			echo La resta de $num1 y $num2 es: $resta;;
		3) echo Ha seleccionado Multiplicar
			echo Introduzca un numero
			read num1
			echo Introduzca otro numero
			read num2
			mult=`multiplicar $num1 $num2`
			echo La multiplicacion de $num1 y $num2 es: $mult;;
		0) echo Adios tio
			exit 0;;
		*) echo No, un num del 1-3 o 0 bobo;;
	esac
done
