

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

int n,k;
string datas[1001];


void Solve(int tt){
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    ll mx=0;
    rng(ans,0,(1<<k)-1){
        ll ws=k;
        rng(i,0,n-1){
            ll temp=0;
            rng(j,0,k-1){
                if((ans&(1<<j))) temp+=(datas[i][j]=='T'?1:0);
                else temp+=(datas[i][j]=='T'?0:1);
            }
            ws=min(ws,temp);
        }
        mx=max(mx,ws);
    }
    cout<<mx<<'\n';
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

