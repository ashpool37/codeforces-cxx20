#!/bin/sh

# Usage: ./new-problem.sh 42 a The Problem Title

function tolower() {
    tr '[:upper:]' '[:lower:]'
}
function toupper() {
    tr '[:lower:]' '[:upper:]'
}

export contest_number="$1"
export problem_letter_lower="$(printf '%s' "$2" | tolower)"
export problem_letter_upper="$(printf '%s' "$2" | toupper)"
shift 2
export problem_title="$@"
export problem="${contest_number}${problem_letter_lower}-$(slugify "${problem_title}")"

mkdir "problems/${problem}"
mkdir "problems/${problem}/.vscode"
j2 -o "problems/${problem}/Makefile" templates/Makefile.j2
j2 -o "problems/${problem}/.vscode/launch.json" templates/launch.json.j2
j2 -o "problems/${problem}/README.md" templates/README.md.j2
j2 -o "problems/${problem}/main.cpp" templates/main.cpp.j2
cp templates/.clangd "problems/${problem}/.clangd"
