

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

#define N 200030
#define MOD 998244353
#define INF 1000000007 

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

string os[N], g[N];
int n, m;
vector<vector<int>> sum;
vector<vector<vector<int>>> dp, mv;

int cost(int i, int l, int r) {
    return (r-l+1) - (sum[i][r] - sum[i][l-1]) + sum[i][l-1] + (sum[i][m] - sum[i][r]);
}

void Solve(int tt){
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> g[i];
    }
    if(m > n) {
        swap(g,os);
        swap(n,m);
        for(int i = 0; i < n; i ++) {
            g[i] = string(m,' ');
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                g[i][j] = os[j][i];
            }
        }
    }
    sum = vector<vector<int>>(n+2);
    dp = vector<vector<vector<int>>>(2, vector<vector<int>>(m+1, vector<int>(m+1, INF)));
    mv = vector<vector<vector<int>>>(2, vector<vector<int>>(m+1, vector<int>(m+1, INF)));
    for(int i = n; i >= 1; i --) {
        g[i] = g[i-1];
        g[i].insert(g[i].begin(),' ');
        sum[i] = vector<int>(m+1,0);
        for(int j = 1; j <= m; j ++) {
            sum[i][j] = sum[i][j-1] + g[i][j] - '0';
        }
    }
    // for(int i = 1; i <= n; i ++) {
    //     cout << g[i] << "\n";
    // }
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j<= m; j ++) {
            if(i != 1) dp[1][i][j] = INF;
            else dp[1][i][j] = cost(1,i,j);
            mv[1][i][j] = min(mv[1][i-1][j], dp[1][i][j]);
        }
    }
    
    for(int i = 2; i <= n; i ++) {
        for(int l = 1; l <= m; l ++) {
            for(int r = l; r <= m; r ++) {
                if(l == r) {
                    dp[(i&1)][l][r] = min(mv[~i&1][l-1][r-1], mv[(~i&1)][l][r]);
                } else {
                    dp[(i&1)][l][r] = min(dp[i&1][l][r-1], mv[(~i&1)][l][r]);
                }
                // cout << "(" <<  l << ", " << r << "): " << dp[1][l][r] << ", ";
                
            }
        }
        for(int l = 1; l <= m; l ++) {
            for(int r = l; r <= m; r ++) {
                dp[(i&1)][l][r] += cost(i,l,r);
                mv[(i&1)][l][r] = min(mv[i&1][l-1][r], dp[i&1][l][r]);
            }
        }
        // cout << "\n";
        

        
        for(auto&l: dp[~i&1]) for(auto&r: l) r = INF;
        for(auto&l: mv[~i&1]) for(auto&r: l) r = INF;
    }
    
    cout << mv[n&1][m][m];
    
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

