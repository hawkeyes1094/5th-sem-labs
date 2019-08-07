#!/bin/bash

case $1 in
*.c)
gcc $1
;;
*.h | *.sh)
#do nothing
;;
*)
echo "unknown filetype"
;;
esac
