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

#define N 505
#define MOD 998244353
#define INF 1000000007 

int n, m, ml[N][N];
string g[N];

void Solve(int tt){
    
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        cin >> g[i];
        for(int md = 0; md < m; md ++) {
            int l = 1;
            while(md-l >= 0 && md+l < m && g[i][md-l] == g[i][md+l]) {
                l ++;
            }
            l --;
            for(int j = md-l; j <= md+l; j ++) {
                ml[i][j] = max(ml[i][j], (l+1)*2-1);
            }
        }
        for(int md = 0; md+1 < m; md ++) {
            if(g[i][md] != g[i][md+1]) continue;
            int l = 1;
            while(md-l >= 0 && md+1+l < m && g[i][md-l] == g[i][md+1+l]) {
                l ++;
            }
            l --;
            for(int j = md-l; j <= md+1+l; j ++) {
                ml[i][j] = max(ml[i][j], (l+1)*2);
            }
        }
    }
    int fin = 0;
    for(int j = 0; j < m; j ++) {
        for(int md = 0; md < n; md ++) {
            int l = 1;
            while(md-l >= 0 && md+l < n && g[md-l][j] == g[md+l][j]) {
                l ++;
            }
            l --;
            int ans = 0;
            for(int i = md-l; i <= md+l; i ++) {
                ans = max(ans, ml[i][j]);
            }
            fin = max(fin, ans * ((l+1)*2-1));
        }
        for(int md = 0; md+1 < m; md ++) {
            if(g[md][j] != g[md+1][j]) continue;
            int l = 1;
            while(md-l >= 0 && md+1+l < n && g[md-l][j] == g[md+1+l][j]) {
                l ++;
            }
            l --;
            int ans = 0;
            for(int i = md-l; i <= md+l+1; i ++) {
                ans = max(ans, ml[i][j]);
            }
            fin = max(fin, ans * ((l+1)*2));
        }
    }
    cout << fin;

    
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

