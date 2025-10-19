// 7z e name.zip [And enter the password]
// 7z -P password name.zip
// ./A < name.txt > output.txt

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
vector<int> adj[N];

long double ans;

long double DFS(int c, int p, long double cost) {
    long double ans = 1/cost;
    for(int i: adj[c]) {
        if(i == p) continue;
        ans += DFS(i, c, cost * adj[i].size());
    }
    return ans;
}

void Solve(int tt){
    
    cin >> n;
    for(int i = 1, u, v; i < n; i ++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long double sum = 0;
    for(int i = 1; i <= n; i ++) {
        sum += DFS(i, -1, 1);
    }
    cout << fixed << setprecision(15) << sum/n << "\n";
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

