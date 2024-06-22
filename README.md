# Codeforces Solutions in C++20

An ongoing quest to solve all Codeforces problems [ordered by popularity](https://codeforces.com/problemset?order=BY_SOLVED_DESC&locale=en) and learn some modern C++ in the process.

All solutions are original and released into the Public Domain. Please see LICENSE for details.

The C++ version might be upgraded in the future following adoption by Codeforces.

## Usage

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

Then, run `./new-problem.sh $CONTEST_NUMBER $PROBLEM_LETTER $PROBLEM_TITLE`.

Example for the problem [1791 A: Codeforces Checking](https://codeforces.com/problemset/problem/1791/A?locale=en):

`./new-problem.sh 1791 a Codeforces Checking`

### Building and debugging in vscodium

Each directory created and populated using `new-problem.sh` can be opened in Visual Studio Code or [vscodium](https://vscodium.com/) as a self-contained project. Use the following great extensions to make the most out of the setup:

* [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd),
* [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb).

To build a project, run `make` in the project directory. Use `make run` to build the project and run it right away. Use `make clean` to clean up any built executables, object files, and dependency files.

To debug the project, first build it using `make`. Then use Run -> Start Debugging.

## Unsolved problems

Solutions for the following problems included in the repository do not yet pass all Codeforces tests.

* `1936b-pinball`

## Thanks

* Mike Mirzayanov for [Codeforces](https://codeforces.com/).
* [cppreference.com](https://en.cppreference.com) for the always-up-to-date C++ reference.
