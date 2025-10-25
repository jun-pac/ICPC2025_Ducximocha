

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

#define N 105
#define MOD 998244353
#define INF 1000000007 

int n, m;
bool dp[N][N][N], dp2[N][N], vs[N][N][N];
vector<array<int,2>> adj[N];
bool works(int t1, int t2) {
    // cout << t1 << " " << t2 << "\n";
    if(t1 == 6) return 1;
    return t1 == t2;
}
void DFS(int a, int b, int c) {
    if(dp[a][b][c]) return;
    dp[a][b][c] = 1;
    // cout << a << " " << b << " " << c << "\n";
    for(auto[na,t]: adj[a]) {
        if(!works(t, 0)) continue;
        dp2[a][na] = dp2[na][a] = 1;
        DFS(na, b, c);
    }
    for(auto[nb,t]: adj[b]) {
        if(!works(t, 2)) continue;
        dp2[b][nb] = dp2[nb][b] = 1;
        DFS(a, nb, c);
    }
    for(auto[nc,t]: adj[c]) {
        if(!works(t, 4)) continue;
        dp2[c][nc] = dp2[nc][c] = 1;
        DFS(a, b, nc);
    }

    if(a == b) {
        for(auto[na,t]: adj[a]) {
            if(!works(t, 1)) continue;
            dp2[a][na] = dp2[na][a] = 1;
            DFS(na, na, c);
        }
    }

    if(a == c) {
        for(auto[na,t]: adj[a]) {
            if(!works(t, 5)) continue;
            dp2[a][na] = dp2[na][a] = 1;
            DFS(na, b, na);
        }
    }

    if(b == c) {
        for(auto[nb,t]: adj[b]) {
            if(!works(t, 3)) continue;
            dp2[b][nb] = dp2[nb][b] = 1;
            DFS(a, nb, nb);
        }
    }
    
    // RYB = abc
    // a - 0
    // b - 2
    // c - 4
    // ab - 1
    // ac - 5
    // bc - 3
    
}
void Solve(int tt){
    cin >> n >> m;
    int a, b, c; cin >> a >> b >> c;
    while(m--) {
        int u, v; char t;
        cin >> u >> v >> t;
        int t2;
        // cout << u << " " << v << " "<< t << "\n";
        if(t == 'R') {
            t2 = 0;
        } else if(t == 'O') {
            t2 = 1;
        } else if(t == 'Y') {
            t2 = 2;
        } else if(t == 'G') {
            t2 = 3;
        } else if(t == 'B') {
            t2 = 4;
        } else if(t == 'P') {
            t2 = 5;
        } else if(t == 'X') {
            t2 = 6;
        }
        adj[u].push_back({v,t2});
        adj[v].push_back({u,t2});
    }

    DFS(a,c,b);

    for(int a = 1; a <= n; a ++) {
        for(auto[b,t]: adj[a]) {
            if(t == 6) continue;
            if(!dp2[a][b]) {
                cout << "0"; return;
            }
        }
    }
    cout << "1";

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

