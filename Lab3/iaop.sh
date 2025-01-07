#!/bin/bash

# Prompt user for input
echo "Enter the first integer:"
read num1
echo "Enter the second integer:"
read num2

# Display operation menu
echo "Choose an operation:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Modulus"

# Get the user's choice
read choice

# Perform the selected operation
if [ "$choice" -eq 1 ]; then
    echo "Result: $((num1 + num2))"
elif [ "$choice" -eq 2 ]; then
    echo "Result: $((num1 - num2))"
elif [ "$choice" -eq 3 ]; then
    echo "Result: $((num1 * num2))"
elif [ "$choice" -eq 4 ]; then
    if [ "$num2" -ne 0 ]; then
        echo "Result: $((num1 / num2))"
    else
        echo "Error: Division by zero is not allowed."
    fi
elif [ "$choice" -eq 5 ]; then
    if [ "$num2" -ne 0 ]; then
        echo "Result: $((num1 % num2))"
    else
        echo "Error: Modulus by zero is not allowed."
    fi
else
    echo "Invalid choice. Please select a number between 1 and 5."
fi

