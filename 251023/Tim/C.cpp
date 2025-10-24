

#include <bits/stdc++.h>
using namespace std;
#define int long long
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

const int MAXN = 55, MAXT = 2505;
int n, k, t, ncr[MAXN][MAXN];
tuple<long double, int, int> ps[MAXN];
long double answers[MAXN], dp[MAXN][MAXN][MAXT];

bool cmp(tuple<long double, int, int> a, tuple<long double, int, int> b) {
    return get<1>(a) < get<1>(b);
}

void Solve(int tt){
    cin>>n>>k>>t;
    for(int i = 1; i <= n;i++) {
        long double u, v;
        cin>>u>>v;
        ps[i] = {u, v, i};
    }
    for(int i = 0; i <= n; i++) {
        ncr[i][0] = 1;
    }
    for(int i = 1;i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
    }
    sort(ps + 1, ps + n + 1, cmp);
    for(int i=  1; i <= n; i++) {
        //calc difficulty of problem i
        auto [p, s, idx] = ps[i];
        //cout << "calculating " << idx << ":\n";
        dp[0][0][0] = 1.0;
        dp[1][0][0] = 1.0;
        dp[1][1][get<1>(ps[1])] = get<0>(ps[1]);
        dp[1][1][0] = 1.0 - get<0>(ps[1]);
        for(int j = 2; j < i; j++) {
            auto [cp, cs, ix] = ps[j];
            for(int l = 0; l <= k -1; l++) {
                for(int m = 0; m <= t - s; m++)  {
                    //dont choose j
                    dp[j][l][m] = dp[j-1][l][m];
                    //choose j but it fails to solve
                    if(l > 0) dp[j][l][m] += (1.0 - cp) * dp[j-1][l - 1][m];
                    //choose j and it solves
                    if(m >= cs && l > 0) dp[j][l][m] += cp * dp[j-1][l-1][m - cs];
                }
            }
        }
        long double ans = 0;
        for(int l = 0; l <= k - 1; l++) {
            //cout << "l: " << l << '\n';
            int r = k - 1 - l;
            long double num_left = 0;
            for(int m = 0; m <= t - s; m++) {
                num_left += dp[i-1][l][m];
            }
            int num_right = ncr[n - i][r], denom = ncr[n-1][k-1];
            long double contrib = (long double) num_left / (long double) denom;
            contrib *= (long double) num_right;
            contrib *= (long double) p;
            //cout << num_left << ' ' << num_right << ' ' << denom << ' ' << contrib <<  '\n';

            ans += contrib;
        }
        //cout << ans << '\n';
        answers[idx] = ans;
    }
    for(int i = 1; i <= n; i++) {
        cout << fixed << setprecision(6) << answers[i] << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Solve(1);
    return 0;
}

