

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

int n, v, t[N], a[N], dp[N];
// vector<int> tree[N];

vector<int> tree;
int len;

void update(int a, int v) {
    a += len;
    tree[a] = max(tree[a], v);
    for(a >>= 1; a >= 1; a >>= 1) {
        tree[a] = max(tree[a*2], tree[a*2+1]);
    }
}
int query(int a, int b) {
    int res = -1e9;
    for(a += len, b += len; a <= b; a >>= 1, b >>= 1) {
        if(a&1) res = max(res, tree[a++]);
        if(~b&1) res = max(res, tree[b--]);
    }
    return res;
}

void solve(int l, int r) {
    int m = l+r>>1;
    if(l >= r) {
        // dp[l] = max(dp[l], 1);
        return;
    }
    solve(l,m);
    vector<array<int,2>> vt;
    for(int i = l; i <= r; i ++) {
        // cout << "(" << i << ", " << dp[i] << ") ";
        vt.push_back({a[i], i});
    }
    sort(vt.begin(),vt.end());
    vector<long long> cc;
    for(auto[a,i]: vt) {
        cc.push_back(1LL * t[i] * v - a);
    }
    sort(cc.begin(),cc.end());
    cc.erase(unique(cc.begin(),cc.end()),cc.end());
    len = 1;
    while(len <= 5+cc.size()) len <<= 1;
    tree = vector<int>(len*2,-1e9);
    for(auto[a,i]: vt) {
        long long id = 1LL*t[i]*v - a;
        int cid = 1 + (lower_bound(cc.begin(),cc.end(),id)-cc.begin());

        if(i > m) {
            // cout << "queried at " << cid << ": " << query(cid)+1 << "\n";
            dp[i] = max(dp[i], query(0,cid) + 1);
        } else {
            // cout << "updated at " << cid << ": " << dp[i] << "\n";
            update(cid, dp[i]);
        }
    }
    cc.clear();
    for(auto[a,i]: vt) {
        cc.push_back(1LL * t[i] * v + a);
    }
    sort(cc.begin(),cc.end());
    cc.erase(unique(cc.begin(),cc.end()),cc.end());
    len = 1;
    while(len <= 5+cc.size()) len <<= 1;
    tree = vector<int>(len*2,-1e9);
    reverse(vt.begin(),vt.end());
    for(auto[a,i]: vt) {
        long long id = 1LL*t[i]*v + a;
        int cid = 1 + (lower_bound(cc.begin(),cc.end(),id)-cc.begin());
        
        if(i > m) {
            // cout << "queried at " << cid << ": " << query(cid)+1 << "\n";
            dp[i] = max(dp[i], query(0,cid) + 1);
        } else {
            //  cout << "updated at " << cid << ": " << dp[i] << "\n";
            update(cid, dp[i]);
        }
    }
    for(int i = l; i <= r; i ++) {
        // cout << "(" << i << ", " << dp[i] << ") ";
        // vt.push_back({a[i], i});
    }
    // cout << "\n";
    solve(m+1,r);
}


void Solve(int tt){
    cin >> n >> v;
    t[0] = a[0] = 0;
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = -1e9;
    }
    solve(0,n);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        // cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    cout << ans;
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

