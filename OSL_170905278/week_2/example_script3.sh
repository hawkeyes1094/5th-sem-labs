#!/bin/bash

echo "There are $# command line arguements : $@"
salutation="Hello"
echo $salutation
echo "The program $0 is now running"
echo "The first param is $1"
echo "The second param is $2"
echo "The param list is $*"
echo "THe user's home dir is $HOME"
echo "Please enter new greeting"
read salutation
echo $salutation
echo "The scipt is now complete"
exit 0

