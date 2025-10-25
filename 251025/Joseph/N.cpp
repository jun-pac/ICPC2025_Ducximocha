

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

#define N 100005
#define MOD 998244353
#define INF 1000000007 

vector<int> adj[N][30];
vector<array<int,2>> xv;
int n, k, ds[N][30], mvs[N];

void Solve(int tt){
    cin >> n >> k;
    xv.resize(n);
    for(int i = 0; i < n; i ++) {
        auto&[x,v] = xv[i];
        v = i + 1;
        cin >> x;
    }
    for(auto&i: mvs) i = -1;
    xv.push_back({0,0});
    n ++;
    sort(xv.begin(),xv.end());
    for(int j = 0; j < 30; j ++) {
        set<array<int,2>> st;
        for(int l = 0, r = 0, i = 0; i < n; i ++) {
            while(r < n && xv[r][0] - xv[i][0] <= (1LL<<j)) {
                st.insert({xv[r][1], r});
                r ++;
            }
            while(l < n && xv[i][0] - xv[l][0] > (1LL<<j)) {
                st.erase({xv[l][1], l});
                l ++;
            }
            for(auto it = st.end(); it != st.begin() && adj[i][j].size() < k; ) {
                it = prev(it);
                auto[v,id] = *it;
                if(xv[id][0] != 0) adj[i][j].push_back(id);
                if(id == i) {
                    mvs[id] = j;
                }
            }
        }
    }
    int st;
    for(int i = 0; i < n; i ++) if(xv[i][0] == 0) st = i;
    queue<array<int,2>> que; que.push({st,0});
    ds[st][0] = 1;
    while(que.size()) {
        auto[c1,c2] = que.front(); que.pop();
        if(c2 && 0 == ds[c1][c2-1]) {
            ds[c1][c2-1] = ds[c1][c2] + 1;
            que.push({c1,c2-1});
        }
        if(c2 + 1 < 30 && 0 == ds[c1][c2+1]) {
            ds[c1][c2+1] = ds[c1][c2] + 1;
            que.push({c1,c2+1});
        }
        for(int i: adj[c1][c2]) {
            if(ds[i][c2] == 0) {
                ds[i][c2] = ds[c1][c2] + 1;
                que.push({i,c2});
            }
        }
    }
    vector<int> ans(n,1e9);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= mvs[i]; j ++) {
            if(ds[i][j] == 0) continue;
            ans[xv[i][1]] = min(ans[xv[i][1]], ds[i][j]-1);
        }
        if(mvs[i] == -1) {
            ans[xv[i][1]] = ds[i][0];
        }
    }
    for(int i = 1; i < n; i ++) {
        if(ans[i] == (int)1e9) cout << "-1\n";
        else cout << ans[i] << "\n";
    }
    
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

