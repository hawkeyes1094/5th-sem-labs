#!/bin/bash

echo "Enter first operand"
read a
echo "Enter second operand"
read b
echo "Enter operator"
read op
case $op in
	"+")
	ans=$(($a + $b))
	;;
	"-")
	ans=$(($a - $b))
	;;
	"*")
	ans=$(($a * $b))
	;;
	"/")
	ans=$(($a / $b))
	;;
	*)
	echo "Invalid operator"
	exit
	;;
esac
echo "answer is $ans"
