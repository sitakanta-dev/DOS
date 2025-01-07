#!/bin/bash

# Prompt for input
echo "Enter Ramesh's basic salary:"
read basic_salary

# Calculate dearness allowance (40% of basic salary)
da=$(echo "0.40 * $basic_salary" | bc -l)

# Calculate house rent allowance (20% of basic salary)
hra=$(echo "0.20 * $basic_salary" | bc -l)

# Calculate gross salary
gross_salary=$(echo "$basic_salary + $da + $hra" | bc -l)

# Display results
echo "Basic Salary: $basic_salary"
echo "Dearness Allowance (40%): $da"
echo "House Rent Allowance (20%): $hra"
echo "Gross Salary: $gross_salary"

