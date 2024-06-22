# Codeforces Solutions in C++20

An ongoing quest to solve all Codeforces problems [ordered by popularity](https://codeforces.com/problemset?order=BY_SOLVED_DESC&locale=en) and learn some modern C++ in the process.

All solutions are original and released into the Public Domain. Please see LICENSE for details.

The C++ version might be upgraded in the future following adoption by Codeforces.

## Usage

This repo includes some tooling to make starting work on new problems easier. Use the included script to create:
* a `main.cpp` containing a Hello World,
* a `.clangd` to configure the clangd language server,
* and a POSIX-compliant Makefile.

To begin working on a new problem, first make sure these are installed:
* a POSIX-compliant shell,
* a POSIX-compliant `make`,
* `sed`.

Then, run `./new-problem.sh $PROBLEM_NAME`.

Replace `$PROBLEM_NAME` with the name of the problem following the convention.

Here's how the problem naming convention works.
1. First, write down the contest number.
2. Then, append the problem letter, in lower case.
3. Append a dash.
4. Finally, append the Codeforces problem title in the English locale, all in lower case, with any whitespace and punctuation replaced by dashes.

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
