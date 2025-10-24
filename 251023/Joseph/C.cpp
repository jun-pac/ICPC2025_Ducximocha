

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

#define N 55
#define MOD 998244353
#define INF 1000000007 

int k, n, t, s[N];
long double p[N], dp[N][N][5005];

void Solve(int tt){
    cin >> n >> k >> t;
    vector<tuple<int, long double, int>> vt;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i] >> s[i];
        vt.push_back({s[i], p[i], i});
    }
    sort(vt.begin(),vt.end());
    dp[0][0][0] = 1;
    vector<pair<int, long double>> ans;
    for(int z = 0; z < n; z ++) {
        auto[_,__,i] = vt[z];
        long double fin = 0;
        for(int l = 0; l < k; l ++) {
            for(int j = 0; j <= t; j ++) {
                if(j + s[i] <= t && l + (n-z) >= k) {
                    long double sum = dp[z][l][j] * p[i];
                    for(int v = z-l+1; v <= z; v ++) {
                        sum *= v;
                    }
                    for(int v = 1; v <= l; v ++) {
                        sum /= v;
                    }
                    for(int v = n-z-k+l+1; v <= n-z-1; v ++) {
                        sum *= v;
                    }
                    for(int v = k-l; v <= k-1; v ++) {
                        sum *= v;
                    }
                    for(int v = n-k+1; v <= n-1; v ++) {
                        sum /= v;
                    }
                    fin += sum;
                }
                dp[z+1][l+1][j + s[i]] += dp[z][l][j] * p[i];
                dp[z+1][l+1][j] += dp[z][l][j] * (1 - p[i]);
                dp[z+1][l][j] += dp[z][l][j];
            }
        }
        ans.push_back({i,fin});
    }
    sort(ans.begin(),ans.end());
    cout << setprecision(15) << fixed;
    for(auto[a,v]: ans) {
        cout << v << "\n";
    }


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

