#!/bin/bash

# Prompt the user to enter a character
echo "Enter a character:"
read char

# Check if more than one character is entered
if [ ${#char} -ne 1 ]; then
    echo "You have entered more than one character."
else
    # Check if the character is a lowercase alphabet
    if [[ "$char" =~ [a-z] ]]; then
        echo "You entered a lower case alphabet."
    # Check if the character is an uppercase alphabet
    elif [[ "$char" =~ [A-Z] ]]; then
        echo "You entered an upper case alphabet."
    # Check if the character is a digit
    elif [[ "$char" =~ [0-9] ]]; then
        echo "You have entered a digit."
    # If none of the above, it's a special symbol
    else
        echo "You have entered a special symbol."
    fi
fi

