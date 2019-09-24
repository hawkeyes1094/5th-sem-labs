#!/bin/bash

echo "directory path : $1"
#read path
#echo $1
echo "regular expression : $2"
#read regex
#echo $2
ls $1 | grep -e "$2"