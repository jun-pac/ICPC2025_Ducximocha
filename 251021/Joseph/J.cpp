

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

int n, m, dp[10][1<<8][2];
string g[N];
vector<string> poss;
string ch = "ICP";
void gen(int i, int j, string cur) {
    if(j == m) {
        poss.push_back(cur);
        return;
    }
    if(g[i][j] == '?') {
        for(int c = 0; c < 3; c ++) {
            cur.push_back(ch[c]);
            gen(i, j+1, cur);
            cur.pop_back();
        }
    } else {
        cur.push_back(g[i][j]);
        gen(i, j+1, cur);
    }
}

void Solve(int tt){
    cin >> n >> m;
    for(int i = 0; i< n; i ++) {
        cin >> g[i];
    }
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i ++) {
        poss.clear(); gen(i, 0, "");
        for(int j = 0; j< (1<<m-1); j ++) {
            for(int k = 0; k < 2; k ++) {
                for(auto ns: poss) {
                    bool w = k;
                    int nj = 0;
                    for(int ni = 0; ni+1 < m; ni ++) {
                        if(ns[ni] == 'P' && ns[ni+1] == 'C') {
                            if(j&1<<ni) w = 1;
                        }
                        if(ns[ni] == 'I' && ns[ni+1] == 'C') {
                            nj |= 1<<ni;
                        }
                    }
                    dp[i+1][nj][w] = (dp[i+1][nj][w] + dp[i][j][k]) % MOD;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < (1<<m-1); i++) {
        for(int j = 1; j < 2; j ++) {
            sum = (sum + dp[n][i][j]) % MOD;
        }
    }
    cout << sum;
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

