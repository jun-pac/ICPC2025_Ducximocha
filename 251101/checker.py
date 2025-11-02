#!/usr/bin/env python3
import sys

def check_error(output, expected, threshold=0.005):
    """Check if output matches expected within error threshold"""
    try:
        out_val = float(output.strip())
        exp_val = float(expected.strip())

        # Calculate absolute error
        abs_error = abs(out_val - exp_val)

        # Calculate relative error
        if exp_val == 0:
            rel_error = abs_error if out_val != 0 else 0.0
        else:
            rel_error = abs_error / abs(exp_val)

        # Use minimum of absolute and relative error
        min_error = min(abs_error, rel_error)

        # Check if within threshold
        passed = (abs_error < threshold) or (rel_error < threshold)

        return passed, min_error
    except:
        return False, float('inf')

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: checker.py <output> <expected>")
        sys.exit(1)

    passed, error = check_error(sys.argv[1], sys.argv[2])

    if passed:
        print(f"PASSED|{error:.6f}")
    else:
        print(f"FAILED|{error:.6f}")
