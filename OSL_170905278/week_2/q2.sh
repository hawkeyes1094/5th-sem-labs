#!/bin/bash

echo "enter directory path"
read $1
echo "enter regular expression"
read $2
ls $1 | grep -e "$2"

