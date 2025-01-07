# Assign arguments to variables
file1=$1
file2=$2

# Check if both files exist
if [ ! -f "$file1" ]; then
    echo "Error: File $file1 does not exist."
    exit 1
fi

if [ ! -f "$file2" ]; then
    echo "Error: File $file2 does not exist."
    exit 1
fi

# Compare the contents of the two files
if cmp -s "$file1" "$file2"; then
    echo "Files $file1 and $file2 have same content."
    # Delete the second file
    rm "$file2"
    echo "So $file2 is deleted."
else
    echo "Files $file1 and $file2 have different content."
fi

