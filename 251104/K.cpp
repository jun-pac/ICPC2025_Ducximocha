#include <bits/stdc++.h>
using namespace std;

const int N = 4000005;
const int MOD = 998244353;
const int INF = 1000000000;
const int len = 1<<22;

int n, a[N], b[N], tree[len<<1];

void build(int x, int y, int p) {
    if(x == y) tree[p] = 1;
    else {
        int z = x+y>>1;
        build(x,z,p*2);
        build(z+1,y,p*2+1);
        tree[p] = tree[p*2] + tree[p*2+1];
    }
}

int findKth(int k) {

    int x = 0, y = len-1, p = 1;

    while(x < y) {
        int z = x+y>>1;
        p <<= 1;
        if(tree[p] >= k) {
            y = z;
        } else {
            k -= tree[p];
            x = z+1;
            p ++;
        }
    }

    return x;

}

void update(int x, int v) {
    tree[x+len] = 0;
    for(x = (x+len)>>1; x >= 1; x >>= 1) {
        tree[x] = tree[x*2] + tree[x*2+1];
    }
}


void solve() {
    cin >> n;
    n /= 2;
    build(0,len-1,1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    vector<int> A, B;
    for(int i = 1; i <= n; i ++) {
        int v = findKth(a[i]);
        A.push_back(v + 1);
        update(v,0);
        v = findKth(b[i]);
        B.push_back(v + 1);
        update(v,0);
    }
    for(int i: A) cout << i << " "; cout << "\n";
    for(int i: B) cout << i << " "; cout << "\n";
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}