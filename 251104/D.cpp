#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int MOD = 1e9+7;
const int INF = 1000000000;

int n, k, t;

map<vector<int>, int> mp[100];
// int n, k, t;

int ncr[101][101], fact[101], ifact[101];

int inv(int v) {
    int r = 1;
    for(int i = 0; i < 30; i ++) {
        if(MOD-2&1<<i) r = 1LL*r*v%MOD;
        v = 1LL*v*v%MOD;
    }
    return r;
}

void solve() {
    cin >> n >> k >> t;
    vector<int> init(n+1,0); init[1] = n;
    mp[0][init] = 1;
    ncr[0][0] = 1;
    fact[0] = 1;
    ifact[0] = 1;
    for(int a = 1; a <= 100; a ++) {
        fact[a] = (1LL *fact[a-1] * a) % MOD;
        // cout << fact[a] << " ";
        ncr[a][0] = 1;
        ifact[a] = inv(fact[a]);
        for(int b = 1; b < a; b ++) {
            ncr[a][b] = (ncr[a-1][b-1] + ncr[a-1][b]) % MOD;
        }
        ncr[a][a] = 1;
    }

    for(int i = 0; i < k; i ++) {
        for(auto[vt,cnt]: mp[i]) {
            for(int j = 1; j <= n; j ++) {
                if(vt[j] == 0) continue;
                for(int nk = 1; nk < j && nk <= (j-nk); nk ++) {
                    vector<int> nvt = vt;
                    nvt[nk] ++;
                    nvt[j-nk] ++;
                    nvt[j] --;
                    mp[i+1][nvt] = (mp[i+1][nvt] + 1LL * cnt * vt[j] % MOD * (nk == j-nk ? (j/2) : j) % MOD) % MOD;
                }    
            }
            for(int j = 1; j <= n; j ++) {
                if(vt[j] == 0) continue;
                for(int l = j; l <= n; l ++) {
                    if(vt[l] == 0) continue;
                    if(l == j && vt[l] == 1) continue;
                    vector<int> nvt = vt;
                    nvt[l] --; nvt[j] --;
                    nvt[l+j] ++;
                    int mult = cnt;
                    if(l == j) mult = 1LL * mult * (ncr[vt[j]][2] % MOD) % MOD;
                    else mult = 1LL * mult * vt[j] % MOD * vt[l] % MOD;
                    mp[i+1][nvt] = (mp[i+1][nvt] + 1LL * mult % MOD * j % MOD * l % MOD) % MOD;
                }
            }
        }
    }

    while(t--) {
        vector<int> v(n);
        for(auto&i: v) cin >> i;
        vector<bool> vs(n+1, 0);
        v.insert(v.begin(), 0);
        vector<int> cnt(n+1,0);
        int vss = 1;
        vss = ifact[n];
        for(int i = 1; i <= n; i ++) {
            // int c = v[i];
            if(vs[i]) continue;
            int c = i, sz = 1;
            while(v[c] != i) {
                vs[v[c]] = 1;
                sz ++;
                c = v[c];
            }
            vs[i] = 1;
            cnt[sz] ++;
            vss = 1LL*vss*ifact[sz-1]%MOD;
            vss = 1LL*vss*fact[sz]%MOD;
            // cout << sz << " ";
        }
        for(int i = 1; i <= n; i ++) {
            vss = 1LL*vss*fact[cnt[i]]%MOD;
        }
        // int v = 1LL*vss*mp[k][cnt]%MOD;
        cout << 1LL*vss*mp[k][cnt]%MOD << "\n";
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();

}

/*
6 15 1
4 5 1 2 6 3
*/