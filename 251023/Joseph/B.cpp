

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

long double p[N], pr[N], ps[N], dp[1<<20], dp2[1<<20];
int n;

void Solve(int tt){
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
    }
    dp[(1<<n)-1] = 1;
    long double ans = 0;
    for(int i = (1<<n)-1; i > 0; i --) {
        if(__builtin_popcount(i) == 2) continue;
        long double tot = 1, tot2 = 1;
        for(int j = 0; j < n; j ++) {
            if(i&1<<j) {
                tot *= p[j];
                tot2 *= 1-p[j];
            }
        }
        // cout << tot << " " << tot2 << "\n";
        long double sum = 0;
        for(int j = 0; j < n; j ++) {
            if(i&1<<j) {
                sum += tot / p[j] * (1-p[j]);
                sum += tot2 / (1-p[j]) * p[j];
                // cout << tot/p[j]*(1-p[j]) << " ";
            }
        }
        if(__builtin_popcount(i) == 2) {
            sum /= 2;
        }
        // cout << sum << "??\n";
        ans += dp[i] / sum;
        for(int j = 0; j < n; j ++) {
            if(~i&1<<j) continue;
            dp[i-(1<<j)] += dp[i] * (tot / p[j] * (1-p[j]) + tot2 / (1-p[j]) * p[j]) / sum;
        }
    }
    cout << setprecision(15) << fixed << ans << "\n";
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

