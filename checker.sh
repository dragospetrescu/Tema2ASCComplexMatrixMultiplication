#!/usr/bin/env bash

gcc -g matrix_crawler_n_checker.c -o check -lm
valgrind ./check ref/ref1 out1
rm check
