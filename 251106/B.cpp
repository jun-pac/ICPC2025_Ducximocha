#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int n, m;
string g[N], ans[N];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        cin >> g[i];
        ans[i] = string(m, '.');
        for(int j= 0; j < m; j++) {
            if(g[i][j] == '#') ans[i][j] = '#';
        }
    }
    for(int j = 0; j < m; j ++) {
        queue<int> ids;
        for(int i = n-1; i >= 0; i--) {
            if(g[i][j] == '#') {
                while(ids.size()) ids.pop();
            } else {
                ids.push(i);
                if(g[i][j] == 'a') {
                    ans[ids.front()][j] = 'a';
                    ids.pop();
                }
            }
        }
    }
    for(int i = 0; i< n; i ++) {
        cout << ans[i] << "\n";
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}