#!/bin/bash
echo Introduzca un numero entre el 1 y el 3
read input
case $input in
1) echo Has introducido el numero $input;;
2) echo Has introducido el numero $input;; 
3) echo Has introducido el numero $input;; 
*) echo "¡Un numero del 1-3 dios!";;
esac
