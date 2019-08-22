#!/bin/bash

echo "enter string"
read str
rev_str=$(echo $str | rev)

if [[ $str == $rev_str ]]
then
echo "string is palindrome"
else
echo "string is not palindrome"
fi
