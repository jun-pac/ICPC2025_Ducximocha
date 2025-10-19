#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+5;
int t, n, a[MAXN], st[4*MAXN], le[MAXN], ri[MAXN];
map<int, int> compress;

void update(int i, int l, int r, int q, int v) {
    if(l > q || r < q) return;
    if(l==r) {
        st[i] = max(st[i], v);
        return;
    }
    int m = (l+r)/2;
    update(2*i, l, m, q, v);
    update(2*i + 1, m+1, r, q, v);
    st[i] = max(st[2*i], st[2*i+1]);
}

int query(int i, int l, int r, int ql, int qr) {
    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return st[i];
    int m = (l+r)/2;
    return max(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
}

void reset() {
    compress.clear();
    for(int i = 0; i <= 4 * n; i++) {
        st[i] = le[i] = ri[i] = 0;
    }
}

int main() {
    cin.tie(NULL)->sync_with_stdio(0);
    cin>>t;
    while(t--) {
        cin>>n;
        reset();
        set<int> s;
        for(int i = 1; i <= n; i++) {
            cin>>a[i];
            s.insert(a[i]);
        }
        int counter= 0;
        for(int x : s) {
            compress[x] = counter;
            counter++;
        }
        for(int i = 1; i <= n; i++) a[i] = compress[a[i]];
        for(int i = 1; i <= n; i++) {
            le[i] = query(1, 0, counter, 0, a[i] - 1) + 1;
            update(1, 0, counter, a[i], le[i]);
        }
        for(int i= 0; i <= 4 * n; i++) {
            st[i] = 0;
        }
        for(int i= n; i >= 1; i--) {
            ri[i] = query(1, 0, counter, 0, a[i] - 1) + 1;
            update(1, 0, counter, a[i], ri[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(le[i] <= 1 || ri[i] <= 1) continue;
            ans = max(ans, le[i] + ri[i] - 1);
        }
        cout << ans << '\n';
    }
}