#!/bin/sh

problem="$1"
mkdir "${problem}"
mkdir "${problem}/.vscode"
sed "s/%PROBLEM%/${problem}/g" Makefile.template \
    > "${problem}/Makefile"
sed "s/%PROBLEM%/${problem}/g" launch.json.template \
    > "${problem}/.vscode/launch.json"
cp .clangd "${problem}/.clangd"
cp main.cpp "${problem}/main.cpp"
