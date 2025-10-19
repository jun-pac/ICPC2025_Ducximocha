

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

vector<int> pos[N];
int n, k[N];
vector<int> edges[N], rev_edges[N];
int pre[N];
bool visited[N];

bool DFS(int idx){
    // Bipartite matching
    if(visited[idx]) return false;
    visited[idx]=true;
    for(int i=0; i<edges[idx].size(); i++){
        int next=edges[idx][i];
        if(pre[next]==-1 || (!visited[pre[next]] && DFS(pre[next]))){
            pre[next]=idx;
            return true;
        }
    }
    return false;
}
void Solve(int tt){
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> k[i];
        vector<array<int,2>> vs(k[i]);
        for(auto&[a,b]: vs) {
            cin >> a >> b;
            a --; b --;
        }
        for(int j = 0; j < (1<<k[i]); j ++) {
            int v = 0;
            for(int l = 0; l < k[i]; l ++) {
                if(j&1<<l) {
                    v |= 1<<vs[l][0];
                } else {
                    v |= 1<<vs[l][1];
                }
            }
            if(__builtin_popcount(v) != k[i]) continue;
            pos[v].push_back(i);
            for(int j: pos[(~v)&((1<<15)-1)]) {
                if(k[i] <= 7) {
                    edges[i].push_back(j);
                    rev_edges[j].push_back(i);
                } else {
                    edges[j].push_back(i);
                    rev_edges[i].push_back(j);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        pre[i] = -1;
        sort(edges[i].begin(),edges[i].end());
        edges[i].erase(unique(edges[i].begin(),edges[i].end()),edges[i].end());
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(k[i] > 7) continue;
        for(int j = 1; j <= n; j ++) {
            visited[j] = 0;
        }
        if(DFS(i)) {
            ans ++;
        }
    }
    cout << ans << "\n";
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

