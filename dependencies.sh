#!/bin/bash

[ ! -d ./obj ] && mkdir obj
[ ! -d ./bin ] && mkdir bin

if [ ! -d sfml ]
then
  echo "Instalando dependências =)"
  wget https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz
  tar -xvf SFML-2.5.1-linux-gcc-64-bit.tar.gz
  mv SFML-2.5.1 sfml
  rm SFML-2.5.1-linux-gcc-64-bit.tar.gz
fi