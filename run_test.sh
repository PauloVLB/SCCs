#!/bin/bash

make spy

ini=1
fim=37

if [ $# -eq 1 ]
then
    ini=$1
    fim=$1
fi

for (( i=$ini; i<=$fim; i++ ))
do
    ./spy $i > generated_output/$i
    
    White='\033[0;37m'
    DIFF=$(diff generated_output/$i output/H_$i)

    Green='\033[0;32m'
    Red='\033[0;31m'

    if [ "$DIFF" == "" ]
    then
        echo -e "${White}Teste $i: ${Green}Passou"
    else
        echo -e "${White}Teste $i: ${Red}Falhou"
    fi
done
