#!/bin/bash
count=1
for param in "$@"; do
  echo "Parâmetro $count: $param"
  count=$((count + 1))
done
