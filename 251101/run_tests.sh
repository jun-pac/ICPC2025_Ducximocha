#!/bin/bash

# Compile the program
g++ -o J J.cpp -std=c++17 -O2

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Compilation successful!"
echo ""

# Run all test cases
data_dir=".cph/data"
total=0
passed=0
failed=0

for input_file in "$data_dir"/Mobilization-*.in; do
    # Extract test case number
    base_name=$(basename "$input_file" .in)
    ans_file="$data_dir/${base_name}.ans"

    if [ ! -f "$ans_file" ]; then
        echo "Warning: Answer file not found for $base_name"
        continue
    fi

    total=$((total + 1))

    # Run the program
    output=$(./J "$input_file")
    expected=$(cat "$ans_file")

    echo "Test: $base_name"
    echo "  Output:   $output"
    echo "  Expected: $expected"

    # Compare outputs with relative and absolute error check
    result=$(python3 checker.py "$output" "$expected")

    status=$(echo "$result" | cut -d'|' -f1)
    error=$(echo "$result" | cut -d'|' -f2)

    if [ "$status" = "PASSED" ]; then
        echo "  Result: ✓ PASSED (error: $error)"
        passed=$((passed + 1))
    else
        echo "  Result: ✗ FAILED (error: $error)"
        failed=$((failed + 1))
    fi
    echo ""
done

echo "================================"
echo "Summary: $passed/$total tests passed"
if [ $failed -gt 0 ]; then
    echo "$failed tests failed"
fi
