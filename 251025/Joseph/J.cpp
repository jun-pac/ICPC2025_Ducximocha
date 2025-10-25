

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

#define N 500030
#define MOD 998244353
#define INF 1000000007 

ll pw[N];

ll f(string n) {
    if(n == "0") return 0;
    if(n.size() == 1) {
        return n[0] - '0';
    }
    ll ans = 0;
    for(int i = 0; i < n.size(); i ++) {
        if(i == 0) {
            ans = (ans + 1LL * max(0, n[i] - '1') * pw[n.size() - i - 1]) % MOD;
            for(int j = 0; j+1 < n.size(); j ++) {
                ans = (ans + 1LL * pw[n.size() - j - 1]) % MOD;
            }
        } else {
            ans = (ans + 1LL * max(0, n[i] - '0' - ((i != 0 && n[i-1] < n[i]) ? 1 : 0)) * pw[n.size() - i - 1]) % MOD;
        }
        if(i != 0 && n[i] == n[i-1]) break;
        if(i == n.size() - 1) ans ++;
    }
    return ans;
}

void Solve(int tt){
    pw[0] = 1;
    for(int i = 1; i < N; i ++) {
        pw[i] = 9LL*pw[i-1]%MOD;
    }
    string l, r; cin >> l >> r;
    for(int i = int(l.size())-1; i >= 0; i --) {
        if(l[i] == '0') {
            l[i] = '9';
        } else {
            l[i] --;
            break;
        }
    }
    cout << ((f(r) - f(l))%MOD + MOD) % MOD;
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

