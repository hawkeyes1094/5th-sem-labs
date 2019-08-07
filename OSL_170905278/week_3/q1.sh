#!/bin/bash

echo "Enter number"
read n
if [ $(($n % 2)) -eq 0 ]
then
echo "$n is an even number"
else
echo "$n is an odd number"
fi
