

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

#define N 808
#define MOD 998244353
#define INF 1000000007 


int n, a[N], dp[N][N], lft[N];

void Solve(int tt){
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[i] == a[i-1]) {
            lft[i] = lft[i-1];
        } else {
            lft[i] = i-1;
        }
        for(int j = i; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    for(int l = n; l >= 1; l --) {
        dp[l][l] = 1;
        for(int rp = l+1; rp <= n; rp ++) {
            for(int lp = l+1; lp <= rp; lp ++) {
                if(a[lp-1] == a[l]) {
                    if(a[rp] == a[l]) {
                        dp[l][rp] = min(dp[l][rp], dp[lp][lft[rp]] + dp[l][max(l,lft[lp-1])]);
                    } else {
                        dp[l][rp] = min(dp[l][rp], dp[lp][rp] + dp[l][max(l,lft[lp-1])]);
                    }
                } else {
                    if(a[rp] == a[l]) {
                        dp[l][rp] = min(dp[l][rp], dp[lp][lft[rp]] + dp[l][lp-1]);
                    } else {
                        dp[l][rp] = min(dp[l][rp], dp[lp][rp] + dp[l][lp-1]);
                    }
                }
            }
        }
    }
    int ans = dp[1][n];
    vector<int> fins(n+1, INF);
    fins[0] = 0;
    for(int r = 1; r <= n; r ++) {
        if(a[r] == 0) fins[r] = min(fins[r], fins[r-1]);
        for(int l = 1; l <= r; l ++) {
            fins[r] = min(fins[r], fins[l-1] + dp[l][r]);
        }
    }
    cout << fins[n];
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

