
# Assign arguments to variables
num1=$1
num2=$2
num3=$3

# Determine the smallest number
if [ "$num1" -le "$num2" ] && [ "$num1" -le "$num3" ]; then
    smallest=$num1
elif [ "$num2" -le "$num1" ] && [ "$num2" -le "$num3" ]; then
    smallest=$num2
else
    smallest=$num3
fi

# Display the smallest number
echo "The smallest number is: $smallest"

