

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

int n, m;

vector<array<int,2>> adj[N];
vector<int> vt;

vector<long long> calculate(int st) {

    priority_queue<array<long long,2>> pq;
    vector<long long> ds(n+1, 1e18);
    ds[st] = 0;
    pq.push({0,st});
    while(pq.size()) {
        auto[d,c] = pq.top(); pq.pop();
        d = -d;
        if(d != ds[c]) continue;
        for(auto[i,v]: adj[c]) {
            if(ds[i] > d + v) {
                ds[i] = d+ v;
                pq.push({-ds[i], i});
            }
        }
    }
    return ds;

}

vector<long long> ds[N];

void Solve(int tt){
    cin >> n >> m;
    while(m--) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    vt.resize(7);
    for(int& i: vt) cin >> i;

    for(int i: vt) {
        // cout << i << "WOW!\n";
        ds[i] = calculate(i);
    }
    ds[1] = calculate(1);

    sort(vt.begin(),vt.end());

    long long inf = 1e18;
    long long ans = inf;
    do {
        int pr = 1;
        long long cur = 0;
        for(int i: vt) {
            // cout << ds[pr].size() << " " << ds[pr][i] << "\n";
            cur += ds[pr][i];
            pr = i;
        }
        ans = min(ans, cur);
    } while(next_permutation(vt.begin(),vt.end()));
    if(ans == inf) cout << "-1";
    else cout << ans;
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

