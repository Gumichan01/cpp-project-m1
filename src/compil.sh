#!/bin/bash

#
# Script de compilation du fremawork et du programme test
#

CURRENT_DIR=`pwd`;

cd framework
make 
cd ${CURRENT_DIR}
cd test
make
cd ${CURRENT_DIR}
