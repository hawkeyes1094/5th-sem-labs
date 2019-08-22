#!/bin/bash

echo "The name of this script is $0"
echo "The first arguement is $1"
echo "A list of all arguements is $*"
echo "This script places the date into a temporary file"
echo "called $1.$$"
date >$1.$$ #redirect the output of the file
ls $1.$$ #list the file
cat $1.$$ #output the file
rm $1.$$ #remove the file

