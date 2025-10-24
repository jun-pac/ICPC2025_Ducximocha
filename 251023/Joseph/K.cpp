

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

int n, dp[10][19683], bt1[10][19683];
string g[10], bt2[10][19683];

void Solve(int tt){
    cin >> n;
    for(int i = 0; i <= n; i ++) {
        cin >> g[i];
    }
    for(int i = 0; i < (1<<n); i ++) {
        vector<int> l(n+1,0), r(n+1,0);
        string c = "";
        for(int j = 0; j < n; j ++) {
            if(i&1<<j) {
                c += "\\";
                l[j] ++;
                r[j+1] ++;
            } else {
                c += "/";
                l[j+1] ++;
                r[j] ++;
            }
        }
        bool w = 1;
        for(int j = 0; j <= n; j ++) {
            if(g[0][j] == '+') continue;
            if(g[0][j] - '0' != l[j]) {
                w = 0;
            }
        }
        if(w) {
            int res = 0;
            for(int i: r) {
                res = res*3+i;
            }
            dp[1][res] = 1;
            bt1[1][res] = 0;
            bt2[1][res] = c;
        }
    }
    int mxv = powl(3,n+1);
    for(int i = 1; i < n; i ++) {
        for(int j = 0; j < mxv; j ++) {
            if(!dp[i][j]) continue;
            assert(bt2[i][j].size());
            // cout << i << " " << j << "\n";
            vector<int> l;
            for(int z = 0, y = j; z <= n; z ++) {
                l.push_back(y%3);
                y /= 3;
            }
            reverse(l.begin(),l.end());
            for(int k = 0; k < (1<<n); k ++) {
                vector<int> r(n+1, 0);
                vector<int> nl;
                for(int z: l) nl.push_back(z);
                string s;
                for(int o = 0; o < n; o ++) {
                    if(k&1<<o) {
                        nl[o] ++;
                        r[o+1] ++;
                        s += "\\";
                    } else {
                        s += "/";
                        nl[o+1] ++;
                        r[o] ++;
                    }
                }
                bool w = 1;
                for(int o = 0; o <= n; o ++) {
                    if(g[i][o] == '+') continue;
                    if(nl[o] != g[i][o]-'0') {
                        w = 0;
                    }
                }
                if(w) {
                    int res = 0;
                    for(int i: r) {
                        res = res*3+i;
                    }
                    if(!dp[i+1][res]) {
                        dp[i+1][res] = 1;
                        bt1[i+1][res] = j;
                        bt2[i+1][res] = s;
                    }
                }
            }
        }
    }
    for(int i = 0; i< mxv; i++) {
        vector<int> l;
        if(!dp[n][i]) continue;
        int oi = i;
        while(l.size() <= n) {
            l.push_back(oi%3);
            oi /= 3;
        }
        reverse(l.begin(),l.end());
        bool w = 1;
        for(int j = 0; j <= n; j ++) {
            if(g[n][j] == '+') continue;
            if(g[n][j]-'0' != l[j]) {
                w = 0;
            }
        }
        if(w) {
            int j = i;
            i = n;
            vector<string> ans;
            while(i) {
                ans.push_back(bt2[i][j]);
                vector<int> vt;
                int oj = j;
                while(oj) {
                    vt.push_back(oj%3); oj /= 3;
                }
                reverse(vt.begin(),vt.end());
                j = bt1[i][j];
                i --;
            }
            reverse(ans.begin(),ans.end());
            for(auto i: ans) {
                cout << i << "\n";
            }
            return;
        }
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

