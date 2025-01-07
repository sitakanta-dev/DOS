#!/bin/bash

# Prompt for internal marks
echo "Enter the internal marks:"
read internal_mark

# Prompt for attendance percentage
echo "Enter the attendance percentage:"
read attendance_percentage

# Check conditions for allowance
if [ "$internal_mark" -ge 20 ] && [ "$attendance_percentage" -ge 75 ]; then
    echo "Allowed for Semester"
else
    echo "Not Allowed for Semester"
fi

