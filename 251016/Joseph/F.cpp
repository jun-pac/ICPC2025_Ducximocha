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

int n;
string s;
string ch = " 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_'{|}~";

vector<string> em = {
    ":)",
    ":-)",
    ":-(",
    ";-)",
    "xD",
    "^_^",
    "-_-",
    "^o^",
    "^^;",
    "(..)"
};
int getLength(string s) {
    int n = s.size();
    int ans = n;
    for(int i = 0; i < n; i++) {
        vector<string> st;
        st.push_back("");
        for(int j = 0; j <= 4; j ++) {
            if(i+j >= n) st.push_back("");
            else st.push_back(st.back() + (s[i+j]));
        }
        for(auto j: em) {
            if(st[j.size()] == j) {
                ans -= j.size()-1;
                i += j.size()-1;
                break;
            }
        }
    }
    return ans;
}

void Solve(int tt){
    getline(cin, s);
    n = s.size();
    int mxv = 0, mnv = 1e9;
    for(char a = 1; a <= 126; a ++) {
        for(char b = 1; b <= 126; b ++) {
            string ns = "";
            int cnt = 0;
            for(auto i: s) {
                if(i == a) {
                    cnt ++;
                    ns.push_back(b);
                }
                else ns.push_back(i);
            }
            mnv = min(mnv, getLength(ns));
            mxv = max(mxv, getLength(ns));
        }
    }
    cout << mnv << " " << mxv << "\n";
     
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

