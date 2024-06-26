# Usage

These instructions are mostly for myself if I ever forget how to use this repo.

This repo includes some tooling to make starting work on new problems easier. Use the included script to create:
* a `main.cpp` containing a Hello World,
* a `.clangd` to configure the clangd language server,
* a POSIX-compliant Makefile,
* and a README linking to the problem statement on Codeforces.

To begin working on a new problem, first make sure these are installed:
* a POSIX-compliant shell,
* a POSIX-compliant `make`,
* [`j2cli`](https://pypi.org/project/j2cli/),
* [`python-slugify`](https://pypi.org/project/python-slugify/).

Then, run `scripts/new-problem.sh $CONTEST_NUMBER $PROBLEM_LETTER $PROBLEM_TITLE`.

Example for the problem [1791 A: Codeforces Checking](https://codeforces.com/problemset/problem/1791/A?locale=en):

`scripts/new-problem.sh 1791 a Codeforces Checking`

## Building and debugging in vscodium

Each directory created and populated using `scripts/new-problem.sh` can be opened in Visual Studio Code or [vscodium](https://vscodium.com/) as a self-contained project. Use the following great extensions to make the most out of the setup:

* [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd),
* [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb).

To build a project, run `make` in the project directory. Use `make run` to build the project and run it right away. Use `make clean` to clean up any built executables, object files, and dependency files.

To debug the project, first build it using `make`. Then use Run -> Start Debugging.

## Updating README

To update the statistics below ensure that these are installed in addition to the above prerequisites:

* `bc`.

First, update `templates/problem-count` with the total number of problems that are in the Codeforces problem set.

Then, run `scripts/update-readme.sh`.

When making other changes to the README, edit `templates/global-README.md.j2` and run `scripts/update-readme.sh` rather than editing the `README.md` directly.