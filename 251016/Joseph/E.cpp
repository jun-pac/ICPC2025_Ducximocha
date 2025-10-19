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

#define N 1000030
#define MOD 998244353
#define INF 1000000007 

int n, m;

int p[N], sz[N];

int get(int a) {
    if(a != p[a]) p[a] = get(p[a]);
    return p[a];
}

void join(int a, int b) {
    a = get(a); b = get(b);
    if(a == b) return;
    p[a] = b;
    sz[b] += sz[a];
}

void Solve(int tt){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        p[i] = i;
        sz[i] = 1;
    }
    if(n == 1) {
        cout << "0\n";
        return;
    }
    int cnt = 0;
    while(m--) {
        int u, v; cin >> u >> v;
        join(u,v);
        cnt ++;
        if(sz[get(u)] == n) {
            cout << cnt << "\n"; return;
        }
    }
    cout << "-1\n";

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

