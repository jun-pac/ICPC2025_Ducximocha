
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define pb push_back
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 400030

pair<double, double> datas[N];
vc<pair<double, double>> inout;
priority_queue<double>;

void Solve(){
    ll n;
    double a,b;
    double r;
    cin>>n>>a>>b;
    cin>>r;
    rng(i,0,n-1){
        cin>>datas[i].fi>>datas[i].se;   
    }
    rng(i,0,n-1){
        double x= datas[i].fi;
        double y= datas[i].se;
        
        double temp=(a*x+b*y)*(a*x+b*y)-(a*a+b*b)*(x*x+y*y);
        if (temp < 0){
            continue;
        }
        else{
            double v1 = (a*x+b*y);
            double v2 = sqrt(temp);
            double t1, t2;
            t1 = (v1-v2)/(a*a+b*b);
            t2 = (v1+v2)/(a*a+b*b);
            inout.pb({t1,t2});
        }
        
    }
    sort(inout.begin(), inout.end());
    for(auto ptemp: inout){
        
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

