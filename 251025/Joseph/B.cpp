

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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

int n, c, w[N];
long long s[N];
bitset<N> wk;

void Solve(int tt){
    cin >> n >> c;
    for(int i = 1; i <= n; i ++) cin >> w[i];
    sort(w+1,w+1+n);
    for(int i = 1; i <= n; i ++) {
        s[i] = s[i-1] + w[i];
    }
    wk[0] = 1;
    int ans = s[n];
    for(int i = n; i >= 1; i --) {
        int v = max(0LL, c - s[i-1] - w[i] + 1);
        for(int s2 = 0; s2+s[i-1] <= c; s2 ++) {
            if(!wk[s2]) continue;
            if(c - s[i-1] - s2 < w[i]) {
                ans = min(ans, (int)s[i-1]+s2);
            }
        }
        wk |= wk << w[i];
    }
    cout << ans;
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

