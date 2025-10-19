
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

vector<array<int,2>> edg;
vector<bool> vs, ex;
vector<int> adj[N];

int dp[N][4];

void DFS(int c, int p) {
    vs[c] = 1;
    dp[c][0] = 1; dp[c][1] = 0;
    dp[c][2] = -1; dp[c][3] = 0;
    vector<int> vt = {0,0,0};
    for(int i: adj[c]) {
        if(i == p || !ex[i] || vs[i]) continue;
        DFS(i, c);
        vt[2] = dp[i][1]-dp[i][0];
        vs[i] = 0;
        sort(vt.begin(),vt.end());
        dp[c][0] += dp[i][0];
        dp[c][1] += dp[i][0];
    }
    dp[c][0] += vt[0] + vt[1];
    dp[c][1] += vt[0];
    vt = {0,0,0};
    for(int i: adj[c]) {
        if(i == p || !ex[i] || vs[i]) continue;
        vt[2] = dp[i][3]-dp[i][2];
        sort(vt.begin(),vt.end());
        vs[i] = 1;
        dp[c][2] += dp[i][2];
        dp[c][3] += dp[i][2];
    }
    dp[c][2] += vt[0] + vt[1];
    dp[c][3] += vt[0];
}

array<int,2> calculateCost(int root, vector<bool> exx) {
    ex = exx;
    vector<int> v;
    for(int i = 1; i <= n; i ++) {
        if(ex[i]) v.push_back(i);
    }
    vector<int> ins(n+1,0);
    vs = vector<bool>(n+1,0);
    DFS(root,-1);
    int ans = dp[root][1];
    int ans2 = -dp[root][3];
    for(int i: v) {
        if(!vs[i]) {
            DFS(i, -1);
            ans += dp[i][0];
            ans2 -= min(dp[i][3]+1, dp[i][2]);
        }
    }
    return {ans,ans2};
}

bool isConnected(int a, int b) {
    if(a > b) swap(a,b);
    if(a == -1) return 1;
    for(auto[u,v]: edg) {
        if(u == a && v == b) return 1;
    }
    return 0;
}

void Solve(int tt){
    cin >> n >> k;
    vector<bool> exx(n+1,1);
    for(int i = 1; i < n; i ++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edg.push_back({a,b});
    }
    int p = -1;
    vector<int> ans;
    for(int z = 0; z < n; z ++) {
        for(int c = 1; c <= n; c ++) {
            if(!exx[c]) continue;
            exx[c] = 0;
            auto[l,r] = calculateCost(c, exx);

            if(!isConnected(p, c)) {
                l ++; r ++;
            }
            // cout << c << " " << l << " " << r << " " << "\n";
            if(l <= k && k <= r) {
                if(!isConnected(p,c)) {
                    k --;
                }
                p = c;
                ans.push_back(c);
                break;
            }
            exx[c] = 1;
        }
        if(p == -1) {
            cout << "-1"; return;
        }
    }
    assert(ans.size()==n);
    for(int i: ans) cout << i << " ";

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

