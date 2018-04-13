#!/usr/bin/env bash


gcc -g matrix_crawler_n_checker.c -o check -lm

make
./tema2_neopt input

echo "Neoptimizat"
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
make clean
rm out*

make
./tema2_opt_m input
echo "Optimizat cod"
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
make clean
rm out*

make
./tema2_opt_f input
echo "Optimizat flags"
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
make clean
rm out*

rm check
