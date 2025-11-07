#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int n, k, x[N], t[N];

void solve() {
    cin >> n >> k;
    vector<array<int,2>> a, b;
    for(int i = 1; i <= n; i ++) {
        cin >> x[i] >> t[i];
        if(x[i] < 0) {
            a.push_back({-x[i],t[i]});
        } else if(x[i] > 0) {
            b.push_back({x[i],t[i]});
        }
    }
    int lft = 0;
    reverse(b.begin(),b.end());
    long long ans = 0;
    for(auto[x,t]: a) {
        if(t > lft) {
            ans += (t-lft+k-1)/k*x*2;
            lft += ((t-lft+k-1)/k) * k;
        }
        lft -= t;
    }
    lft = 0;
    for(auto[x,t]: b) {
        if(t > lft) {
            ans += (t-lft+k-1)/k*x*2;
            lft += ((t-lft+k-1)/k) * k;
        }
        lft -= t;
    }
    cout << ans;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}