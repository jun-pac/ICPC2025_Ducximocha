

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

int n;
string s;
int dp[1<<9];

void Solve(int tt){
    cin >> s;
    n = s.size();
    for(auto&i: dp) i = 1e9;
    dp[0] = n;
    for(int i = 0; i < (1<<9); i ++) {
        for(int j = 0; j < 9; j ++) {
            if(i&1<<j) continue;
            int cur = dp[i];
            if(j == s[0]-'1') {
                cur += __builtin_popcount(i);
            }
            for(int k = 0; k < n; k ++) {
                if(s[k]-'1' == j) {
                    if(k-1 >= 0 && s[k-1]-'1' != j) {
                        if(i&1<<(s[k-1]-'1')) {
                            cur += __builtin_popcount(i);
                        } else {
                            cur -= __builtin_popcount(i);
                        }
                    }
                    if(k+1 < n && s[k+1]-'1' != j) {
                        if(i&1<<(s[k+1]-'1')) {
                            cur += __builtin_popcount(i);
                        } else {
                            cur -= __builtin_popcount(i);
                        }
                    }
                }
            }
            dp[i|1<<j] = min(dp[i|1<<j], cur);
        }
    }
    cout << dp[(1<<9)-1];
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

