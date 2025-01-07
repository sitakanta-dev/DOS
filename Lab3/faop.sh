#!/bin/bash

# Prompt user for input
echo "Enter the first number:"
read num1
echo "Enter the second number:"
read num2

# Display operation menu
echo "Choose an operation:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"

# Get the user's choice
read choice

# Perform the selected operation using bc
if [ "$choice" -eq 1 ]; then
    result=$(echo "$num1 + $num2" | bc -l)
    echo "Result of addition: $result"
elif [ "$choice" -eq 2 ]; then
    result=$(echo "$num1 - $num2" | bc -l)
    echo "Result of subtraction: $result"
elif [ "$choice" -eq 3 ]; then
    result=$(echo "$num1 * $num2" | bc -l)
    echo "Result of multiplication: $result"
elif [ "$choice" -eq 4 ]; then
    if (( $(echo "$num2 != 0" | bc -l) )); then
        result=$(echo "$num1 / $num2" | bc -l)
        echo "Result of division: $result"
    else
        echo "Error: Division by zero is not allowed."
    fi
else
    echo "Invalid choice. Please select a number between 1 and 4."
fi

