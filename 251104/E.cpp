#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 998244353;
const int INF = 1000000000;

int n, h[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> h[i];
    }
    vector<array<int,2>> vt;
    long long p = 0, q = 1;
    for(int i = 1; i <= n; i ++) {
        while(vt.size() && vt.back()[0] < h[i]) vt.pop_back();
        if(vt.size() && vt.back()[1] != i-1) {
            int j = vt.back()[1];

            long long np = 1LL * (i - j - 1) * (h[j] - h[j+1]) + (h[i] - h[j+1]);
            long long nq = h[j] - h[j+1];

            long long g = gcd(np,nq);

            np /= g; nq /= g;

            if(p * nq < np * q) {
                p = np;
                q = nq;
            }

            // (j+1-i) + (h[i] - h[j+1]) / (h[j] - h[j+1])

        }
        vt.push_back({h[i], i});
    }

    reverse(h+1, h+n+1);
    vt.clear();

    for(int i = 1; i <= n; i ++) {
        while(vt.size() && vt.back()[0] < h[i]) vt.pop_back();
        if(vt.size() && vt.back()[1] != i-1) {
            int j = vt.back()[1];

            long long np = 1LL * (i - j - 1) * (h[j] - h[j+1]) + (h[i] - h[j+1]);
            long long nq = h[j] - h[j+1];

            long long g = gcd(np,nq);

            np /= g; nq /= g;

            if(p * nq < np * q) {
                p = np;
                q = nq;
            }

            // (j+1-i) + (h[i] - h[j+1]) / (h[j] - h[j+1])

        }
        vt.push_back({h[i], i});
    }

    if(p == 0) cout << "0";
    else cout << p << "/" << q;


}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}