

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

string a, b;

string gets(string s) {
    string r = "";
    int cnt = 0;
    for(char i: s) {
        if(i == 'B') cnt ++;
    }
    if(cnt%2) r = "B";
    for(char i: s) {
        if(i == 'B') continue;
        if(r.size() && r.back() == i) {
            r.pop_back();
            continue;
        }
        r.push_back(i);
    }
    return r;
}

void Solve(int tt){
    cin >> a >> b;
    if(gets(a) == gets(b)) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

