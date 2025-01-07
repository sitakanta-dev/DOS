#!/bin/bash

# Prompt the user to enter a day
echo "Enter a day (e.g., Monday, Tuesday, etc.):"
read day

# Convert the input to lowercase to handle case-insensitivity
day=$(echo "$day" | tr '[:upper:]' '[:lower:]')

# Check the entered day and display the corresponding message
case "$day" in
    "monday")
        echo "DOS class is at 10:00 AM in Room 101."
        ;;
    "wednesday")
        echo "DOS class is at 2:00 PM in Room 202."
        ;;
    "friday")
        echo "DOS class is at 11:00 AM in Room 303."
        ;;
    "sunday")
        echo "Holiday"
        ;;
    "tuesday"|"thursday"|"saturday")
        echo "No class on $day."
        ;;
    *)
        echo "Invalid day entered. Please enter a valid day."
        ;;
esac

