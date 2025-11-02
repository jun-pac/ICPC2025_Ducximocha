

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


void Solve(int tt){
    ll x,y,x1,y1,x2,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    if(x1<=x && x<=x2){
        cout<<min(abs(y-y1), abs(y-y2))<<'\n';
        return;
    }
    if(y1<=y && y<=y2){
        cout<<min(abs(x-x1), abs(x-x2))<<'\n';
        return;
    }
    else{
        ll d1=(x-x1)*(x-x1)+(y-y1)*(y-y1);
        ll d2=(x-x2)*(x-x2)+(y-y1)*(y-y1);
        ll d3=(x-x1)*(x-x1)+(y-y2)*(y-y2);
        ll d4=(x-x2)*(x-x2)+(y-y2)*(y-y2);
        ll mn=min(min(d1,d2),min(d3,d4));
        cout<<fixed;
        cout.precision(12);
        double ans=sqrt((ll)mn);
        cout<<ans<<'\n';
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

