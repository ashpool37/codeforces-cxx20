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

mkdir "${problem}"
mkdir "${problem}/.vscode"
j2 -o "${problem}/Makefile" .templates/Makefile.j2
j2 -o "${problem}/.vscode/launch.json" .templates/launch.json.j2
j2 -o "${problem}/README.md" .templates/README.md.j2
cp .templates/.clangd "${problem}/.clangd"
cp .templates/main.cpp "${problem}/main.cpp"
