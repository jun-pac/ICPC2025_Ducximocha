

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

int n, e, m, p[N];
long double x[N], y[N];

int get(int a) {
    if(p[a] != a) p[a] = get(p[a]);
    return p[a];
}

void join(int a, int b) {
    a = get(a); b = get(b);
    p[a] = b;
}

void Solve(int tt){
    cin >> n >> e >> m;
    for(int i = 1; i <= n; i ++) {
        if(i <= e) p[i] = 1;
        else p[i] = i;
        cin >> x[i] >> y[i];
    }
    while(m--) {
        int a, b; cin >> a >> b;
        join(a,b);
    }
    vector<tuple<long double, int, int>> vt;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(i == j) continue;
            long double ds = sqrtl(powl(x[i] - x[j],2) + powl(y[i] - y[j], 2));
            vt.push_back({ds,i,j});
        }
    }
    sort(vt.begin(),vt.end());
    long double ans = 0;
    for(auto[ds,a,b]: vt) {
        if(get(a) == get(b)) continue;
        ans += ds;
        join(a,b);
    }
    cout << setprecision(15) << fixed <<  ans;



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

