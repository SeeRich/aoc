#!/bin/bash

# Start measuring time
start_time=$(date +%s.%N)

./install/bin/day1 --input inputs/day1.txt

# Stop measuring time
end_time=$(date +%s.%N)

# Calculate the elapsed time in seconds with nanosecond precision
elapsed_time=$(echo "$end_time - $start_time" | bc)

# Convert seconds to microseconds
elapsed_microseconds=$(echo "$elapsed_time * 1000000" | bc)

# Print the elapsed time
echo "Elapsed time: ${elapsed_microseconds} microseconds"