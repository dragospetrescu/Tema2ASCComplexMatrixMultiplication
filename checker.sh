module load utilities/intel_parallel_studio_xe_2016
gcc -g matrix_crawler_n_checker.c -o check -lm

echo "GCC"
echo ""
make clean
rm out*
make
echo "Neoptimizat gcc"
./tema2_neopt input
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
rm out*


echo "Optimizat cod gcc"
./tema2_opt_m input
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
rm out*


echo "Optimizat flags gcc"
./tema2_opt_f input
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
rm out*


echo "BLAS gcc"
./tema2_blas input
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
rm out*

echo "============================"
echo ""

echo "ICC"
echo ""
make clean
rm out*
make -f Makefile.icc
echo "Neoptimizat icc"
./tema2_neopt input
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
rm out*


echo "Optimizat cod icc"
./tema2_opt_m input
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
rm out*


echo "Optimizat flags icc"
./tema2_opt_f input
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
rm out*


echo "BLAS icc"
./tema2_blas input
for i in {1..5}
do
    echo -n "Test $i ... "
    ./check ref/"ref$i" "out$i"
done
echo ""
rm out*

rm check

