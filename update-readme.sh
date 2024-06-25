#!/bin/sh

export problems_total="$(cat .templates/problem-count)"
export problems_started="$(find problems -mindepth 1 -maxdepth 1 -type d -print | wc -l)"
export problems_unsolved="$(find problems -name .unsolved -print | wc -l)"
export problems_solved=$(printf '%s-%s\n' "$problems_started" "$problems_unsolved" | bc)
export solved_percent=$(printf 'scale=4; (%s-%s) * 100 / %s\n' "$problems_started" "$problems_unsolved" "$problems_total" | bc -l)

j2 -o README.md .templates/global-README.md.j2