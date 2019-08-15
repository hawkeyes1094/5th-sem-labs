#!/bin/bash

echo "enter n"
read n
i=1
factorial=1
while [ $i -le $n ]
do
factorial=$((factorial*i))
i=$(($i+1))
done
echo "$n! = $factorial"
