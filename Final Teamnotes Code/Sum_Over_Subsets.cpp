

// works in 3^n
void naive_iteration(int n) {
    for (int x = 0; x < (1 << n); x++) {
        // iterate over all subsets of x directly
        for (int i = x; i > 0; i = (i - 1) & x) {

        }
    }
}

