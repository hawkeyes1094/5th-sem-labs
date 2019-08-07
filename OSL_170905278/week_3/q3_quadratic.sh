#!/bin/bash

#not working
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
#sqrt_delta = $(bc <<< "scale=4;sqrt())
$x1 = $((-$b + $(bc <<< "scale=4;sqrt($delta)")) / 4*$a*$c)
echo $x1
fi
