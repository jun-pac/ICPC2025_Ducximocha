

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

long long dp[10000005];

int a, b, c, d;


void Solve(int tt){
    cin >> a >> b >> c >> d;
    for(int m = max(c,d); m >= 1; m --) {
        int na = (a+m-1)/m, nb = b/m;
        int nc = (c+m-1)/m, nd = d/m;
        if(na > nb || nc > nd) dp[m] = 0;
        else if(na == nb && nc == nd) {
            dp[m] = gcd(na,nc) == 1;
        } else {
            dp[m] = 1LL * (nb - na + 1) * (nd - nc + 1);
            for(int nm = 2*m; min(b,d) >= nm; nm += m) {
                dp[m] -= dp[nm];
            }
        }
    }
    
    cout << dp[1];
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

