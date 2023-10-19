#!/bin/bash
#author: hansolo
#date: 2023-10-19

for f in 'find /data/ -type f -name "*.txt"'
do
  echo "$f"
done
