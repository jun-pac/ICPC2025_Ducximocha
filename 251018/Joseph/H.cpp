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

int n, k;

vector<string> st[N];

void Solve(int tt){
    cin >> n >> k;
    for(int i = 0; i < n; i ++) {
        int l; cin >> l;
        st[i].resize(l);
        for(auto&j: st[i]) cin >> j;
    }
    int ans = 0;
    for(int i = 0; i < (1<<n); i ++) {
        if(__builtin_popcount(i) != k) continue;
        map<string,int> mp;
        for(int j = 0; j < n; j ++) {
            if(~i&1<<j) continue;
            for(auto l: st[j]) {
                mp[l] ++;
            }
        }
        bool w = 1;
        for(auto[a,b]: mp) {
            if(b*2 > k) w = 0;
        }
        if(w) ans ++;
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

