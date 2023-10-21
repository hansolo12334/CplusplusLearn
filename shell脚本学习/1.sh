#!/bin/bash
#author: hansolo
#date: 2023-10-19
echo "hello what's your name?"
read Name
if [ $Name = "hansolo" ]
    then echo "hello $Name"
    suffix=$(date +%Y%m%d)
    for f in  $(find ./data/ -type f -name '*.txt' -o -name '*.cc')
    do
        if [ -e f ]
        then
            echo "$f" "is readable"
        fi

        echo "$f->$f""_""${suffix}"
    done
else
    echo "error name!"
fi

