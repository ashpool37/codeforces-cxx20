#!/bin/sh

problem="$1"
mkdir "${problem}"
mkdir "${problem}/.vscode"
sed "s/%PROBLEM%/${problem}/g" .templates/Makefile.template \
    > "${problem}/Makefile"
sed "s/%PROBLEM%/${problem}/g" .templates/launch.json.template \
    > "${problem}/.vscode/launch.json"
cp .templates/.clangd "${problem}/.clangd"
cp .templates/main.cpp "${problem}/main.cpp"
