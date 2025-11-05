#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int MOD = 998244353;
const int INF = 1000000000;

int n, m, dp[1<<18];

bool ins[100][100];

void solve() {
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        while(k--) {
            int v; cin >> v;
            ins[i][v] = 1;
        }
    }

    for(int bt = 0; bt < (1<<m); bt ++) {
        for(int a = 0; a < n; a ++) {

        }
    }


    for(int i = 1; i < (1<<n); i ++) {
        if(__builtin_popcount(i) == 1) {
            dp[i] = 0;
            continue;
        }
        dp[i] = INF;
        for(int j = 0; j < m; j ++) {
            int l = 0, r = 0;
            for(int k = 0; k < n; k ++) {
                if(~i&1<<k) continue;
                if(ins[k][j]) l |= 1<<k;
                else r |= 1<<k;
            }
            if(l && r) {
                dp[i] = min(dp[i], dp[l] * __builtin_popcount(l) / __builtin_popcount(i) + dp[r] * __builtin_popcount(r) / __builtin_popcount(i) + 1);
            }
        }
    }
    // cout << "Yooo...\n";
    if(dp[(1<<n)-1] >= 100000) {
        cout << "not possible";
    } else {
        // dp[(1<<n)-1] += n;
        cout << setprecision(15) << fixed << (long double)dp[(1<<n)-1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
// 2 + 2 + 2 + 3 + 3
// = 12