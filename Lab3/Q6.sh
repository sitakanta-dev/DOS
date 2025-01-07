#!/bin/bash

# Check if a year is provided as an argument, if not, use the current year
if [ -z "$1" ]; then
    # No argument provided, use current year
    year=$(date +%Y)
else
    # Use the provided year
    year=$1
fi

# Leap year check logic
if [ $(($year % 4)) -eq 0 ]; then
    if [ $(($year % 100)) -eq 0 ]; then
        if [ $(($year % 400)) -eq 0 ]; then
            echo "$year is a leap year."
        else
            echo "$year is not a leap year."
        fi
    else
        echo "$year is a leap year."
    fi
else
    echo "$year is not a leap year."
fi

