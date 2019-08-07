#!/bin/bash

X=0
while [[ $X -le 10 ]]
do
	echo $X
	X=$((X+1))
done

#echo all the command line arguements
while [[ $# != 0 ]]
do
	echo $1
	#The shift command shifts arguements to the left
	shift
done
