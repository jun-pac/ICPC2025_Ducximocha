

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

int n, k, cnt[26][26], dp[26];

string s;
vector<int> adj[26];

int DFS(int c) {
    if(dp[c] != 0) return dp[c];
    int ans = 1;
    for(int i: adj[c]) {
        ans = max(ans, DFS(i) + 1);
    }
    dp[c] = ans;
    return ans;
}

void Solve(int tt){
    cin >> n >> k;

    for(int i = 0; i < n; i ++) {
        cin >> s;
        for(int j = 0; j < k; j ++) {
            for(int l = j+1; l < k; l ++) {
                cnt[s[j]-'A'][s[l]-'A'] ++;
            }
        }
    }
    for(int i = 0; i < k; i ++) {
        for(int j = 0; j < k; j ++) {
            if(cnt[i][j] != n) continue;
            adj[i].push_back(j);
        }
    }
    int ans = 0;
    for(int i = 0; i < 26; i ++) {
        ans = max(ans, DFS(i));
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

