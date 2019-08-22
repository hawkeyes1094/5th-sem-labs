#!/bin/bash

#echo "Enter the format of the file"
#read format
#echo "Format entered is $1"
echo "Files to be copied are "
ls *.$1
cp *.$1 $2/
