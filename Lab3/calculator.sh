#!/bin/bash

# Check if exactly three arguments are provided
if [ "$#" -ne 3 ]; then
    echo "Invalid input"
    echo "Enter input in the following format: op1 operator op2"
    exit 1
fi

# Assign arguments to variables
op1=$1
operator=$2
op2=$3

# Perform the operation based on the operator
case "$operator" in
    "+")
        result=$((op1 + op2))
        ;;
    "-")
        result=$((op1 - op2))
        ;;
    "x"|"*")
        result=$((op1 * op2))
        ;;
    "/")
        if [ "$op2" -eq 0 ]; then
            echo "Division by zero is not allowed."
            exit 1
        fi
        result=$((op1 / op2))
        ;;
    "%")
        result=$((op1 % op2))
        ;;
    "^")
        result=$((op1 ** op2))
        ;;
    *)
        echo "Invalid input"
        echo "Operator must be one of: +, -, x, /, %, ^"
        exit 1
        ;;
esac

# Display the result in the specified format
echo "$op1 $operator $op2 = $result"

