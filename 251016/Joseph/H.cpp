// 7z e name.zip [And enter the password]
// 7z -P password name.zip
// ./A < name.txt > output.txt

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

string init;
int g, p;
bool dp[2][59049];

int toInt(string st) {
    int r = 0;
    for(int i = 0; i < st.size(); i ++) {
        r = r*3+((st[i] == 'L') ? 0 : (st[i] == 'F' ? 1 : 2));
    }
    return r;
}

string toString(int r) {
    string st;
    string ch = "LFR";
    for(int i = 0; i < g; i ++) {
        st.push_back(ch[r%3]);
        r /= 3;
    }
    reverse(st.begin(),st.end());
    return st;
}

void Solve(int tt){
    
    cin >> g >> p >> init;

    dp[0][toInt(init)] = 1;
    int pos = 1;
    for(int j = 0; j < g; j ++) pos *= 3;
    for(int i = 0; i < p; i ++) {
        for(int j = 0; j < pos; j ++) {
            if(dp[0][j] == 0) continue;
            string st = toString(j);
            for(int k = 0; k < g-1; k ++) {
                if(st[k] != 'R' && st[k+1] != 'L') {
                    string ns = st;
                    ns[k] = 'R';
                    ns[k+1] = 'L';
                    dp[1][toInt(ns)] = 1;
                }
            }
        }
        for(int j = 0; j < pos; j ++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    bool res = 0;
    for(auto&i: dp[0]) {
        res |= i;
    }
    if(res) {
        cout << "1";
    } else {
        cout << "0";
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

