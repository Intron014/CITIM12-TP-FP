#!/bin/bash

project_name="$1"

if [ -z "$project_name" ]; then
    echo "Usage: ./build_and_run.sh <project_name>"
    exit 1
fi

project_folder="./$project_name"

if [ ! -d "$project_folder" ]; then
    echo "Project '$project_name' does not exist."
    exit 1
fi

# Compile and run the project
gcc "$project_folder/main.c" -o "$project_folder/main"
if [ $? -eq 0 ]; then
    "$project_folder/main"
else
    echo "Compilation failed."
fi
