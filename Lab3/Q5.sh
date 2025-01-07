#!/bin/bash

# Prompt for input
echo "Enter the cost price of the item:"
read cost_price

echo "Enter the selling price of the item:"
read selling_price

# Check if the seller made a profit or incurred a loss
if [ $(echo "$selling_price > $cost_price" | bc) -eq 1 ]; then
    # Calculate profit
    profit=$(echo "$selling_price - $cost_price" | bc)
    echo "Profit made: $profit"
elif [ $(echo "$selling_price < $cost_price" | bc) -eq 1 ]; then
    # Calculate loss
    loss=$(echo "$cost_price - $selling_price" | bc)
    echo "Loss incurred: $loss"
else
    echo "No profit, no loss (selling price equals cost price)."
fi

