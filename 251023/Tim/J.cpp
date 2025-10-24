#include <bits/stdc++.h>

using namespace std;

int n, m, a[105], ans[105];

int main() {
    cin.tie(NULL)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i = 1; i <= m; i++) {
        cin>>a[i];
    }
    while(n>0) {
        bool updated = false;
        for(int i = 1; i <= m; i++) {
            if(n==0)break;
            if(a[i] > 0) {
                updated = true;
                a[i]--;
                ans[i]++;
                n--;
            }
        }
        if(!updated) break;
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
}