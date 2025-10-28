

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

#define N 1530
#define MOD 998244353
#define INF 1000000007 

bitset<N> bt[N];
int n, a[N][N];
array<int,2> id[N*N];


void Solve(int tt){
    cin >> n;
    
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            id[a[i][j]] = {i,j};
        }
    }

    long long ans = 1LL * n * (n-1) * n * (n-1) / 4;
    for(int i = 1; i <= n*n; i ++) {
        auto[x,y] = id[i];
        for(int nx = 1; nx <= n; )
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

