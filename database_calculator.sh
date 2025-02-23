#!/bin/bash

# Check if the correct number of arguments is passed
if [ "$#" -ne 7 ]; then
    echo "Usage: $0 <executable> <checker> <output_file> <range_start> <range_end> <values_count> <repeat_count>"
    exit 1
fi

EXECUTABLE=$1
CHECKER=$2
OUTPUT_FILE=$3
RANGE_START=$4
RANGE_END=$5
VALUES_COUNT=$6
REPEAT_COUNT=$7

# Ensure the output file exists
touch "$OUTPUT_FILE"

# Check if the range is valid and large enough to generate unique numbers
if [ "$RANGE_START" -gt "$RANGE_END" ]; then
    echo "Invalid range: RANGE_START ($RANGE_START) is greater than RANGE_END ($RANGE_END)."
    exit 1
fi

if [ $((RANGE_END - RANGE_START + 1)) -lt "$VALUES_COUNT" ]; then
    echo "Range is too small to generate $VALUES_COUNT unique numbers."
    exit 1
fi

# Function to generate unique random numbers
generate_unique_numbers() {
    local count=$1
    local start=$2
    local end=$3
    local numbers=()
    
    while [ "${#numbers[@]}" -lt "$count" ]; do
        RAND=$((RANDOM % (end - start + 1) + start))
        if [[ ! " ${numbers[*]} " =~ " $RAND " ]]; then
            numbers+=("$RAND")
        fi
    done
    
    echo "${numbers[@]}"
}
echo "testing"
# Loop for the specified number of repetitions
for ((i=0; i<REPEAT_COUNT; i++)); do
    # Generate unique random numbers
    VALUES=$(generate_unique_numbers "$VALUES_COUNT" "$RANGE_START" "$RANGE_END")

    # Run the program with the unique numbers and count the output lines
    LINE_COUNT=$("$EXECUTABLE" $VALUES | tee >($CHECKER $VALUES >> $OUTPUT_FILE) | wc -l | awk '{print $1}')

    # Print a dot every 5th iteration
    if (( (i+1) % 5 == 0 )); then
        echo -n "."
    fi

    # Append the line count to the output file
    echo "$LINE_COUNT" >> "$OUTPUT_FILE"
done

echo

echo "Completed $REPEAT_COUNT runs. Results saved to $OUTPUT_FILE."
