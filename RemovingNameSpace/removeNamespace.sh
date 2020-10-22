#!/bin/bash
dirName="$1"
echo "$1/fileNames.txt"
ls "$1/" > "$1/fileNames.txt"