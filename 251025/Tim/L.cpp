#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5+5;
int k, r, limit[MAXN];

signed main() {
    cin>>k>>r;
    for(int i = 1; i <= k; i++) {
        cin>>limit[i];
    }
    int ans = 0;
    for(int i =1; i <= r; i++) {
        int mn = 1e18;
        for(int j = 1; j <= k; j++) {
            int x;cin>>x;
            if(x!=0) mn = min(mn, (limit[j]/x));
        }
        int p;
        cin>>p;
        ans = max(ans, mn * p);
    }
    cout << ans;
}