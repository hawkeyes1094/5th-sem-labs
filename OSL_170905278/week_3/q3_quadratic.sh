#!/bin/bash

#working
echo "Enter the coefficients of the quadratic equation"
echo "Enter a"
read a
echo "Enter b"
read b
echo "Enter c"
read c

delta=$(($b**2 - 4*$a*$c))
echo "delta = $delta"

if [ $delta -gt 0 ]
then
	echo "roots are real and unequal"
	sqrt_delta=$(bc <<< "scale=4; sqrt(($delta))")
	x1=$(bc <<< "scale=4; ((-1*$b)+$sqrt_delta)/(2*$a)")
	x2=$(bc <<< "scale=4; ((-1*$b)-$sqrt_delta)/(2*$a)")
	#x2=$(echo "scale=4; ((-1*$b)-$sqrt_delta)/(2*$a)" | bc 2> /dev/null)
	#echo "sqrt_delta = $sqrt_delta"
	echo "x1 = $x1"
	echo "x2 = $x2"

elif [ $delta -eq 0 ]
then
	echo "roots are real and equal"
	#x1=$(echo "scale=4; ((-1*$b)/(2*$a))" | bc 2> /dev/null)
	x1=$(bc <<< "scale=4; ((-1*$b)/(2*$a))")
	x2=$x1
	echo "x1 = $x1"
	echo "x2 = $x2"

else
	echo "roots are imaginary"
	delta=$((-1*$delta))
	sqrt_delta=$(bc <<< "scale=4; sqrt(($delta))")
	x1="$(bc <<< "scale=4;((-1*$b)/(2*$a))") + ($(bc <<< "$sqrt_delta/(2*$a)"))i"
	x2="$(bc <<< "scale=4;((-1*$b)/(2*$a))") - ($(bc <<< "$sqrt_delta/(2*$a)"))i"
	echo "x1 = $x1"
	echo "x2 = $x2"
fi
