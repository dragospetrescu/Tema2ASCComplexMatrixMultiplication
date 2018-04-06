#!/usr/bin/env bash

zip Tema2.zip Makefile* solver_* utils.h main.c input
scp Tema2.zip dragos.petrescu@fep.grid.pub.ro:ASC/Tema2
ssh dragos.petrescu@fep.grid.pub.ro ASC/Tema2/run.sh
rm Tema2.zip