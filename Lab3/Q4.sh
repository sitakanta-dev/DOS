#!/bin/bash

# Prompt the user for a number
echo "Enter a number:"
read number

# Check if the number is a five-digit integer
if [ $number -ge 10000 ] && [ $number -le 99999 ]; then
    # Initialize sum variable
    sum=0

    # Calculate the sum of digits
    while [ $number -gt 0 ]; do
        digit=$((number % 10))   # Get the last digit
        sum=$((sum + digit))     # Add the digit to the sum
        number=$((number / 10))  # Remove the last digit
    done

    echo "The sum of the digits is: $sum"
else
    echo "Error: Please enter a valid five-digit number."
fi

