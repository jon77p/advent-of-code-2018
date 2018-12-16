#!/bin/bash

# Gets an array of all arguments passed to the script (variable length)
ARGS=("$@")
# Get the first argument (file to run)
runfile=${ARGS[0]}
# Remove first argument from the array
unset ARGS[0]

gcc -ansi -Wall -pedantic $runfile.c -o $runfile && ./$runfile "${ARGS[@]}"
