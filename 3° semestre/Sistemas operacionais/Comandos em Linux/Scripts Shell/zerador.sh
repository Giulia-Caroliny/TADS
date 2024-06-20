#!/bin/bash
num=$1
while [ $num -ge 0 ]; do
  echo -n "$num "
  num=$((num - 1))
done
echo
