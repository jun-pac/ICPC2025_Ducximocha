#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int MOD = 998244353;
const int INF = 1000000000;

int n, m;
vector<int> c[N];
int bt[N];

void solve() {
    cin >> n >> m;

    for(int i = 0; i< n; i ++) {
        int k; cin >> k;
        c[i].resize(k);
        for(auto&j: c[i]) cin >> j;
    }
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int cnt = 0;
        for(int j: c[i]) {
            if(!bt[j]) {
                cnt ++;
                bt[j] = 2;
            }
        }
        for(int j = 0; j < n; j ++) {
            int cur = 0;
            for(int k: c[j]) {
                if(bt[k] == 0) {
                    cur = -1;
                    break;
                }
                if(bt[k] == 2) {
                    cur = 1;
                }
            }
            if(cur == 1) {
                cnt --;
            }
        }
        if(cnt <= 0) {
            for(int j = 0; j < i; j ++) {
                int cur = 0;
                for(int k: c[j]) {
                    if(bt[k] == 0) {
                        cur = -1;
                        break;
                    }
                    if(bt[k] == 2) {
                        cur = 1;
                    }
                }
                if(cur == 1) {
                    // cout << j << " removed!\n";
                    ans --;
                }
            }
            for(int j: c[i]) {
                if(bt[j] == 2) {
                    bt[j] = 1;
                    // cout << j << "\n";
                    ans ++;
                }
            }
        } else {
            for(int j: c[i]) {
                if(bt[j] == 2) {
                    bt[j] = 0;
                    // cout << j << "\n";
                    // ans ++;
                }
            }
            // cout << i << " added!\n";
            ans ++;
        }
    }

    cout << ans << "\n";



}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}