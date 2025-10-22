

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

int s, t, n;

array<int,2> mh[N];

void Solve(int tt){
    cin >> s >> t >> n;
    for(int i = 0; i < n; i++) {
        auto&[m,h] = mh[i];
        cin >> m >> h;
    }
    sort(mh,mh+n);
    vector<array<int,2>> mv;
    for(int i = 0; i < n; i ++) {
        auto[m,h] = mh[i];
        m = max(m, t);
        m = min(m, s);
        while(mv.size() && mv.back()[1] >= h) mv.pop_back();
        mv.push_back({m,h});
    }
    if(mv.back()[0] < s) {
        cout << "-1"; return;
    }
    while(mv.size() >= 2 && mv[mv.size()-2][0] >= s) mv.pop_back();
    int pr = s;
    reverse(mv.begin(),mv.end());
    long double ans = 0;
    for(int i = 0; i < mv.size(); i ++) {
        int nxt;
        if(i+1 == mv.size()) nxt = t;
        else nxt = mv[i+1][0];
        ans += mv[i][1] * log2l((long double)pr / nxt);
        pr = nxt;
    }
    cout << setprecision((15)) << fixed << ans;
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

