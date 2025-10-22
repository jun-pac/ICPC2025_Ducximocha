

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


int n,m,jp[N][18],dpt[N];
vc<int> edges[N];

queue<int> ord;

bool isRoot(int a, int b) {
    if(dpt[a] > dpt[b]) return 0;
    for(int i = 0; i < 18; i ++) {
        if((dpt[b] - dpt[a])&1<<i) b = jp[b][i];
    }
    return a == b;
}

void DFS(int c) {
    sort(edges[c].begin(),edges[c].end());
    int l, r;
    for(int i = 1; i < 18; i ++) {
        jp[c][i] = jp[jp[c][i-1]][i-1];
    }
    for(int i: edges[c]) {
        dpt[i] = dpt[c] + 1;
        jp[i][0] = c;
        DFS(i);
    }
    // if(edges[c].empty()) {
    //     l = r = c;
    // } else {

    // }
    // cout << c << " ";
    ord.push(c);
}

void Solve(int tt){
    cin>>n>>m;
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        // a--, b--;
        edges[a].pb(b);
        // edges[b].pb(a);
    }
    
    DFS(1);
    // cout << "\n";
    for(int i = 0; i < m; i ++) {
        int v; cin >> v;
        while(ord.size() && !isRoot(v, ord.front())) ord.pop();
        if(ord.empty()) {
            cout << i; return;
        }
    }
    cout << m;
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

