#include <bits/stdc++.h>
using namespace std;
long long query(long long v) {
    long long sum = 0;
    for(long long i = 1; i <= v;) {
        long long x = v/i;
        long long j = v/x;
        sum += (j-i+1) * x;
        i = j+1;
    }
    return sum;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n, m; cin >> n >> m;
    cout << query(m) - query(n-1) << "\n";
}