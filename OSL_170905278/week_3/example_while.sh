#!/bin/bash
#menu program
stop=0
while [ $stop -eq 0 ]
do
cat << ENDOFMENU
1 : print the date
2,3 : print the current working directory
4 : exit
ENDOFMENU
echo
echo "Your choice?"
read reply
echo
case $reply in
"1")
date
;;
"2"|"3")
pwd
;;
"4")
stop=1
;;
*)
echo "wait, that's illegal"
;;
esac
done
