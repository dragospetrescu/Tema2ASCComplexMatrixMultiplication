#!/usr/bin/env bash

#make
#./tema2_neopt input
gcc -g matrix_crawler_n_checker.c -o check -lm

echo "Neoptimizat"
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
rm check
