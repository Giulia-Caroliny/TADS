#!/bin/bash
if [[ "$2" == *"$1"* ]]; then
  echo "$1 está contida em $2"
fi
