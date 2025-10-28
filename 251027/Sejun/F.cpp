

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

pii datas[N];


void Solve(int tt){
    int n,m;
    cin>>n>>m;
    rng(i,0,m-1) cin>>datas[i].fi>>datas[i].se;
    int mnr=0, mnw=0;
    rng(i,0,m-1) mnr=max(mnr,datas[i].fi);
    rng(i,0,m-1) mnw=max(mnw,datas[i].se);
    if(mnr+mnw>n) cout<<"IMPOSSIBLE\n";
    else{
        rng(i,0,mnr-1) cout<<"R";
        rng(i,0,n-1-mnr) cout<<"W";
        cout<<"\n";
    }
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

