#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    cin>>n>>k;
    long double sum = 0;
    for(int  i= 0; i < k; i++) {
        int x;cin>>x;
        sum += x;
    }
    long double mn_sum = sum + -3 * (n - k);
    long double mx_sum = sum + 3 * (n - k);
    cout << fixed << setprecision(6) << mn_sum / (long double) n << ' ' << mx_sum / (long double) n;
}