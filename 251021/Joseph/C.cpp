

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

int n, t[N], dp[N][1<<3][3];

void Solve(int tt){
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> t[i];
        for(int j = 0; j < (1<<3); j ++) {
            for(int k = 0; k < 3; k ++) {
                dp[i][j][k] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < (1<<3); j ++) {
            for(int k = 0; k < 3; k ++) {
                if((~j)&1<<k) continue;
                if(k == t[i]) {
                    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]+1);
                } else {
                    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                }
                for(int nk = 0; nk < 3; nk ++) {
                    if(j&1<<nk) continue;
                    dp[i][j|1<<nk][nk] = max(dp[i][j|1<<nk][nk], dp[i][j][k]);
                }
            }
        }
    }
    cout << max({dp[n+1][(1<<3)-1][0], dp[n+1][(1<<3)-1][1], dp[n+1][(1<<3)-1][2]});
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

