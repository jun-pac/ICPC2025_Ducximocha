

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

string get(string s) {
    string r = "";
    for(char i: s) {
        // letter number or space
        if(i == ' ') return "";
        if('0' <= i  && i <= '9') return "";
        if(i == 'u') {
            r += "1";
        } else if(i == 'm') {
            r += "0";
        } else if('a' <= i && i <= 'z' || 'A' <= i && i <= 'Z') {
            return "";
        }
    }
    return r;
}

void Solve(int tt){
    string r = "";
    string s;
    while(cin >> s) {
        r += get(s);
    }
    for(int i = 0; i< r.size(); i += 7) {
        int rs = 0;
        for(int j = 0; j < 7; j ++) {
            rs = rs*2+r[j+i]-'0';
        }
        cout << (char)rs;
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

