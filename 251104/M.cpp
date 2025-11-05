#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int MOD = 999999937;
const int INF = 1000000000;

int n, a[N], b[N], c[N], ib[N], ic[N], lft[N], rgt[N];

const int len = 1<<19;

int tree[len<<1];

array<int,2> recur(int l1, int r1, int l2, int r2) {
    int rt = a[l1];
    int l = 0, h = r1-l1;
    while(l < h) {
        int m = l+h>>1;

        if(query(l1, l1 + m) <= ib[rt]) {
            l = m;
        } else {
            h = m-1;
        }

    }

    if(l == 0) {

        return {l1+1, l2+1};

        return;
    }

    lft[rt] = a[l1+1];


    auto[lp1, lp2] = recur(l1, l1+l, l2, l2+l);
    
    if(lp1 <= r1) {
        rgt[rt] = a[lp1];
        recur(lp1, r1, lp2, r2);
    }
    
    return {l1+l+1, l2+l+1};
}

int query(int a, int b) {
    int res = 0;
    for(a += len, b += len; a <= b; a >>= 1, b >>= 1) {
        if(a&1) res = max(res, tree[a++]);
        if(~b&1) res = max(res, tree[b--]);
    }
    return res;
}

void update(int a, int v) {
    tree[a+len] = v;
    for(a = (a+len)>>1; a >= 1; a >>= 1) {
        tree[a] = max(tree[a*2], tree[a*2+1]);
    }
}

int ans = 1;

array<int,2> DFS(int c) {
    if(!c) return {-1,-1};
    int minv = 1e9, maxv = 0;
    if(!lft[c]) {
        if(ic[c] == 0) return {INF, 0};
        else return {ic[c], ic[c]};
    }
    auto[a,b] = DFS(lft[c]);
    auto[c,d] = DFS(rgt[c]);
    if(!rgt[c]) {
        if(b != 0 && (b > ic[c] || a < ic[c])) {
            ans = ans * 2 % MOD;
        }
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
        ib[b[i]] = i;
    }
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
        ic[c[i]] = i;
        update(i, ib[a[i]]);
    }

    DFS(a[1]);

    cout << ans;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}