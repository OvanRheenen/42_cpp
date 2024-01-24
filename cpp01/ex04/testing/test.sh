#!/bin/bash

EXE_PATH="../replace"
INFILE="input.txt"
OUTFILE="input.txt.replace"
MTFILE="empty.txt"

BOLD="\e[1m"
RESET="\033[0m"

# Test 1: valid input
printf $BOLD
echo "Test phase 1: Valid input"
echo ""
printf $RESET

# normal input
printf $BOLD
echo "normal input"
printf $RESET
echo "Original file content:"
cat $INFILE
echo ""
echo "Replacing 'test' with 'hi'"
$EXE_PATH $INFILE test hi
echo "Modified file content:"
cat $OUTFILE
echo ""
echo ""

# empty string input 1
printf $BOLD
echo "empty string input 1"
printf $RESET
echo "Original file content:"
cat $INFILE
echo ""
echo "Replacing 'test' with '""' (empty string)"
$EXE_PATH $INFILE test ""
echo "Modified file content:"
cat $OUTFILE
echo ""
echo ""

# empty string input 2
printf $BOLD
echo "empty string input 2"
printf $RESET
echo "Original file content:"
cat $INFILE
echo ""
echo "Replacing '""' (empty string) with 'hi'"
$EXE_PATH $INFILE "" hi
echo "Modified file content:"
cat $OUTFILE
echo ""
echo ""

# non existent string input
printf $BOLD
echo "non existent string input"
printf $RESET
echo "Original file content:"
cat $INFILE
echo ""
echo "Replacing 'hello' with 'hi'"
$EXE_PATH $INFILE hello hi
echo "Modified file content:"
cat $OUTFILE
echo ""
echo ""

# empty input file
printf $BOLD
echo "empty input file"
printf $RESET
echo "Original file content:"
cat $MTFILE
echo ""
echo "Replacing 'hello' with 'hi'"
$EXE_PATH $MTFILE hello hi
echo "Modified file content:"
cat "$MTFILE.replace"
echo ""
echo ""


# Test 2: Invalid input
printf $BOLD
echo "Test phase 2: Invalid input"
echo ""
printf $RESET

# no permission input file
printf $BOLD
echo "no permission to input file"
touch no_permission.txt
chmod 000 no_permission.txt
printf $RESET
$EXE_PATH no_permission.txt test hi
echo ""
rm no_permission.txt
# non existent input file
printf $BOLD
echo "non existent input file"
printf $RESET
$EXE_PATH non_existent_file.txt test hi
echo ""
# no arguments
printf $BOLD
echo "no arguments"
printf $RESET
$EXE_PATH
echo ""
# insufficient amount of args
printf $BOLD
echo "not right amount of args"
printf $RESET
echo "./replace 1 2"
$EXE_PATH 1 2
echo ""
echo "./replace 1 2 3 4 5 6"
$EXE_PATH 1 2 3 4 5 6
echo ""

rm *.replace