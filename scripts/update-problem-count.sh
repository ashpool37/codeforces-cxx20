#!/bin/sh

curl -s https://codeforces.com/api/problemset.problems | jq '.result.problems | length' > templates/problem-count