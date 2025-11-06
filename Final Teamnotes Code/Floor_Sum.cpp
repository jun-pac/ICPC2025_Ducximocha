// calculates for(i = 1; i <= n; i ++) sum += n/i
long long floor_sum(long long n) {
    long long c = 1;
    long long sum = 0;
    while(c <= n) {
        long long v = n/c;
        long long cp = n / v;
        sum += (cp - c + 1) * v;
        c = cp+1;
    }
    return sum;
}