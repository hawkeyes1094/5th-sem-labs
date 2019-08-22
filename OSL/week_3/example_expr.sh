#!/bin/bash

x=1
echo "x=1"
x=`expr $x + 1`
echo "x = x + 1"
echo $x
x=`expr 2 + 3 \* 5`
echo "x = 2 + 3 * 5"
echo $x
echo "4 > 5 is "`expr \(4 \> 5\)`
echo "length of \"cat\" is "`expr length "cat"`
echo "substring of \"donkey\" is "`expr substr "donkey" 4 3`
