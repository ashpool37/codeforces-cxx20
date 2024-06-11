#!/bin/sh

problem="$1"
mkdir "${problem}"
sed "s/%PROBLEM%/${problem}/g" Makefile.template \
    > "${problem}/Makefile"
cp .clangd "${problem}/.clangd"
cp main.cpp "${problem}/main.cpp"
