

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

bool vs[22][400], op[22][400], cl[22][400];
int n;

bool dfs(int r, int a) {
    if(r == 21) return 1;
    if(vs[r][a]) return 0;
    vs[r][a] = 1;
    if(!cl[r][a] && dfs(r, (a-1+360)%360)) return 1;
    if(!cl[r][(a+1)%360] && dfs(r, (a+1)%360)) return 1;
    if(r > 1 && op[r-1][a] && dfs(r-1, a)) return 1;
    if(op[r][a] && dfs(r+1, a)) return 1;
    return 0;
}

void Solve(int tt){
    cin >> n;

    for(int i = 1; i <= 21; i++) {
        for(int j = 0; j < 360; j ++) {
            vs[i][j] = 0;
            op[i][j] = 1;
            cl[i][j] = 0;
        }
    }

    while(n--) {
        char t; 
        cin >> t;
        if(t == 'C') {
            int r, t1, t2; cin >> r>> t1 >> t2;
            for(int i = t1; i != t2; i = (i + 1) % 360) {
                op[r][i] = 0;
            }
        } else {
            int r1, r2, t; cin >> r1 >> r2 >> t;
            for(int i = r1+1; i <= r2; i ++) {
                cl[i][t] = 1;
            }
        }
    }

    for(int i = 0; i < 360; i ++) {
        if(dfs(1,i)) {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
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

