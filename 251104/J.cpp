#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int MOD = 998244353;
const int INF = 1000000000;

int n, p, ins[N];

void solve() {
    cin >> n >> p;
    if(n == 2) {
        cout << p; return;
    }
    if(n == 1) {
        cout << 0; return;
    }
    for(int i = 1, u, v; i < n; i ++) {
        cin >> u >> v;
        ins[u] ++;
        ins[v] ++;
    }
    int l = 0;
    for(int i = 0; i < n; i ++) {
        if(ins[i] == 1) l ++;
    }
    int a = p/l;
    if(p == a*l) cout << 2 *a;
    else if(p == a*l+1) cout << 2*a+1;
    else cout << 2*a+2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}