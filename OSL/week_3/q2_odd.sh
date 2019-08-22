#!/bin/bash

echo "enter n"
read n
i=1
while [ $((n)) -gt 0 ]
do
echo $i
i=`expr $i + 2`
n=`expr $n - 1`
done
