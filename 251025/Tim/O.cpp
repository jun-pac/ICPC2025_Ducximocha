#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
map<int, int> lst;

signed main() {
    set<int> used;
    cin>>n>>m;
    for(int i = 1; i <= m; i++) {
        int x;cin>>x;
        used.insert(x);
        lst[x] = i;
        int ans = 0;
        for(auto [p, q] : lst) {
            ans += i - q;
        }
        ans += (n - used.size()) * i;
        cout << ans << '\n';
    }
}