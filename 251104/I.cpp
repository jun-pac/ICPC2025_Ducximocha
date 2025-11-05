#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 998244353;
const int INF = 1000000000;

int n, m;
int a[N], b[N];

void solve() {
    cin >> n >> m;

    long long v = 0;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        v += a[i] + 1;
    }
    for(int i = 1; i <= m; i ++) {
        cin >> b[i];
        v -= b[i] + 1;
    }

    if(v > 0) cout << "ALICE";
    else if(v < 0) cout << "BOB";
    else cout << "TIED";

    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}