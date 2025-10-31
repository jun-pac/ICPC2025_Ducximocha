

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

#define N 1000030
#define MOD 1000000007
#define INF 1000000007 

int n, m, l[N], r[N], t[N], sm[N], nxt[N];
int dp[5005][5005];

void Solve(int tt){
    cin >> n >> m;
    vector<array<int,2>> rg1;
    for(int i = 0; i < m; i ++) {
        cin >> l[i] >> r[i];
        string ty; cin >> ty;
        if(ty == "same") t[i] = 0;
        else t[i] = 1;

        if(t[i] == 0) {
            sm[l[i] + 1] ++;
            sm[r[i] + 1] --;
        } else {
            if(l[i] != r[i])
            rg1.push_back({l[i], r[i]});
            else {
                cout << "0"; return;
            }
        }
    }
    sort(rg1.begin(),rg1.end());
    vector<array<int,2>> rg;
    for(auto[l,r]: rg1) {
        while(rg.size() && rg.back()[1] >= r) {
            rg.pop_back();
        }
        if(rg.empty() || rg.back()[0] != l) {
            rg.push_back({l,r});
        }
    }

    for(int i = 1; i <= n; i++) {
        sm[i] += sm[i-1];
    }
    for(int i = 1; i <= n; i++) {
        sm[i] = min(1, sm[i]);
    }

    if(rg.empty()) {
        // might cause problems double check
        int r = 1;
        for(int i = 1; i <= n; i++) {
            if(!sm[i]) r = 2 * r % MOD;
        }
        cout << r << "\n"; return;
    }
    // if(rg.back() != array<int,2>({1,n}))
    //     rg.insert(rg.begin(), {1,n});
    rg.push_back({n+1,n+1});
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j < rg.size(); j ++) {
            auto[l,r] = rg[j];
            if(l > i) {
                nxt[i] = j;
                break;
            }
        }
    }
    dp[1][0] = 2;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < rg.size(); j ++) {
            // if(dp[i][j]) {
            //     cout << i << " " << j << ": " << dp[i][j] << "\n";
            // }
            if(rg[j][1] != i) {
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
            }
            if(i != 1 && sm[i] == 0) {
                dp[i+1][nxt[i-1]] = (dp[i+1][nxt[i-1]] + dp[i][j]) % MOD;
            }
        }
    }
    
    cout << dp[n+1][rg.size()-1];

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

