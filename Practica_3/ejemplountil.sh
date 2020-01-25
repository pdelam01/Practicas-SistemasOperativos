#!/bin/bash
numFiles=`ls | wc -l`
count=0
until test $count -eq $numFiles
do
	count=`expr $count + 1`
	echo He encontrado $count fichero/s
done
