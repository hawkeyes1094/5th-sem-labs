#!/bin/bash

sum=0
while test $# != 0
do
	sum=$(($sum + $1))
	shift
done
echo "sum = $sum"


#sum=0
#for i in $*
#do
#        sum=$(($sum + i))
#done
#echo $sum

