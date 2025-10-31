

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

int n, m, ins[N], dp[N][2];

vector<int> adj[N], radj[N];

array<vector<long long>, 3> calculate() {

    for(int i = 1; i <= n; i ++) {
        ins[i] = 0;
        dp[i][0] = dp[i][1] = 0;
    }
    for(int i = 1; i <= n; i ++) {
        for(int j: radj[i]) {
            ins[j] ++;
        }
    }
    vector<long long> dp1(n+1,0), dp2(n+1,0), dp3(n+1,0), dp4(n+1,0);

    // dp1 -> max length
    // dp2 -> second max
    // dp3 -> max count
    // dp4 -> 

    queue<int> que;

    for(int i = 1; i <= n; i ++) {
        dp1[i] = 0;
        dp2[i] = 1;
        dp3[i] = -1e9;
        if(ins[i] == 0) {
            que.push(i);
        }
    }

    while(que.size()) {
        int c = que.front(); que.pop();

        for(int i: adj[c]) {
            if(dp1[i] + 1 == dp1[c]) {
                dp2[c] += dp2[i];
                // dp3[c] = max(dp3[c], dp3[i] + 1);
            } else if(dp1[i] + 1 > dp1[c]) {
                dp3[c] = dp1[c];
                dp1[c] = dp1[i] + 1;
                dp2[c] = dp2[i];
            } else if(dp1[i] + 1 > dp3[c]) {
                dp3[c] = dp1[i] + 1;
            }
        }

        for(int i: radj[c]) {
            ins[i] --;
            if(ins[i] == 0) {
                que.push(i);
            }
        }
    }

    for(auto&i: dp3) i = max(i, 0LL);

    return {dp1, dp2, dp3};

}

void Solve(int tt){
    cin >> n >> m;

    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    auto[dp4, dp5, dp6] = calculate();
    swap(adj, radj);
    auto[dp1, dp2, dp3] = calculate();
    swap(adj, radj);
    
    int maxLen = 0;
    for(int i: dp1) {
        maxLen = max(maxLen, i);
    }

    long long count = 0;

    for(int i = 1; i <= n; i ++) {
        if(dp1[i] == maxLen) count += dp2[i];
    }

    long long ans = maxLen;

    // cout << maxLen << "\n";


    // cout << "dp1: ";
    // for(int i = 1; i <= n; i ++) {
    //     cout << dp1[i] << " ";
    // } cout << "\n";
    // cout << "dp2: ";
    // for(int i = 1; i <= n; i ++) {
    //     cout << dp2[i] << " ";
    // } cout << "\n";
    // cout << "dp3: ";
    // for(int i = 1; i <= n; i ++) {
    //     cout << dp3[i] << " ";
    // } cout << "\n";
    // cout << "dp4: ";
    // for(int i = 1; i <= n; i ++) {
    //     cout << dp4[i] << " ";
    // } cout << "\n";
    // cout << "dp5: ";
    // for(int i = 1; i <= n; i ++) {
    //     cout << dp5[i] << " ";
    // } cout << "\n";
    // cout << "dp6: ";
    // for(int i = 1; i <= n; i ++) {
    //     cout << dp6[i] << " ";
    // } cout << "\n";

    for(int i = 1; i <= n; i ++) {
        for(int j: adj[i]) {
            if(dp1[i] + dp4[j] + 1 == maxLen) {
                if(dp2[i] * dp5[j] == count) {
                    // cout << i << " " << j << ":\n";
                    // cout << dp1[i] << " " << dp2[i] << " "<< dp3[i] << "\n";
                    // cout << dp6[i] << "\n";
                    // cout << dp4[j] << " " << dp5[j] << " "<< dp6[j] << "\n\n";
                    ans = min(ans, dp1[i] + dp6[i]);
                }
            }
        }
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

