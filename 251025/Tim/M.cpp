#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 55;
int x[MAXN], n;

signed main() {
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>x[i];
    sort(x+1, x+n+1);
    int ans = 0;
    for(int i=  1; i <= n; i++) {
        for(int j = i +1; j <= n; j++) {
            for(int k=  j + 1; k <= n; k++) {
                if(x[i] + x[j] > x[k]) ans += (1LL<<(k-j-1));
            }
        }
    }
    cout << ans;
}