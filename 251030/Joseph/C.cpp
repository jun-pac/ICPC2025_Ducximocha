

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

int n, k, t[N];

bool test(ll time) {

    ll cnt = 0;

    for(int i = 0; i < k; i ++) {
        if(time / t[i] == 0) return 0;
        cnt += ((time / t[i] + 1) / 2) * 4;
        if(cnt >= n-i-1) return 1;
    }
    return 0;

}

void Solve(int tt){
    cin >> n >> k;
    k = min(n, k);
    for(int i = 0; i < n; i ++) {
        cin >> t[i];
    }
    sort(t,t+n);

    ll l = 1, h = 2e4 * 1e6 * 10 + 10;
    while(l < h) {
        ll m = l+h>>1;
        if(test(m)) {
            h = m;
        } else {
            l = m+1;
        }
    }
    cout << l;

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

