

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define pb push_back
#define all(x) x.bg,x.ed
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 5000030
#define MOD 998244353
#define INF 1000000007 

int n, k, m, num[100], a[100], fact[N];

int inv(int v) {
    int b = MOD-2;
    int r = 1;
    while(b) {
        if(b&1) r = 1LL*r*v%MOD;
        v = 1LL*v*v%MOD;
        b >>= 1;
    }
    return r;
}

int NPR(int n, int r) {
    return 1LL*fact[n]*inv(fact[n-r])%MOD;
}
int NCR(int n, int r) {
    return 1LL*fact[n]*inv(fact[r])%MOD*inv(fact[n-r])%MOD;
}

void Solve(int tt){
    cin >> n >> k >> m;
    if(k > 30 || (1LL<<k)-1 > m) {
        cout << 0; return;
    }
    fact[0] = 1;
    for(int i = 1; i < N; i ++) {
        fact[i] = 1LL*fact[i-1] * i % MOD;
    }
    for(int nn = 1; nn <= m; nn ++) {
        int val = nn;
        vector<int> vt;
        for(int j = 1; j <= m; j <<= 1) {
            if(nn&j) continue;
            vt.push_back(j);
        }
        int sum = 0;
        for(int j = (int)vt.size()-1; j >= 0; j --) {
            if(val + vt[j] <= m) {
                val += vt[j];
                sum += 1<<j;
            }
        }
        sum ++;
        if(sum >= n)
            num[__builtin_popcount(nn)] = (num[__builtin_popcount(nn)] + NPR(sum, n)) % MOD;
    }
    int ans = 0;
    for(int i = k, v = 1<<k; v-1 <= m; i ++, v <<= 1) {
        for(int j = k; j < i; j ++) {
            a[i] = (a[i] - 1LL*NCR(i,j)*a[j]%MOD + MOD)%MOD;
        }
        a[i] ++;
        ans = (ans + 1LL * a[i] * num[i]) % MOD;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

