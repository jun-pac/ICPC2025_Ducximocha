#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    vector<int> cur, nxt;
    cur.resize(n);
    for(auto&i: cur) cin >> i;
    for(int i = 29; i >= 0; i --) {
        for(int j: cur) {
            if(j&1<<i) {
                nxt.push_back(j);
            }
        }
        if(nxt.size() >= k) {
            swap(cur, nxt);
        }
        nxt.clear();
    }
    int v = (1LL<<30)-1;
    for(int i = 0; i < k; i ++) {
        v &= cur[i];
    }
    cout << v;
}