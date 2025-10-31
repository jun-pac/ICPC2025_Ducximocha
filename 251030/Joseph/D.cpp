

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

int n, x[N], y[N], r[N], b;
long long d;

typedef long double ld;
const ld pi = acosl(0)*2;

ld getTheta(ll x, ll y) {
    if(y == 0) {
        if(x > 0) {
            return 0;
        }
        return pi;
    }
    if(x == 0) {
        if(y > 0) {
            return pi / 2;
        } else {
            return pi * 3 / 2; 
        }
    }
    if(x > 0) {
        ld v = atanl((ld)y/x);
        if(v < 0) return v+2*pi;
        return v;
    }
    // x < 0
    
    return pi - atanl((ld)(-y)/x);
}


// range is not neccesarily in [0,2pi]
array<ld, 2> getRange(ll x, ll y, ll r) {

    ll Rsqr = y*y + x*x;
    if(d*d + r*r >= Rsqr) {

        ld theta = getTheta(x,y);

        ld phi = asinl((ld)r/sqrtl(Rsqr));

        // cout << phi << "\n";

        return {theta-phi, theta + phi};

    } else {
        ld theta = getTheta(x,y);
        assert(abs((Rsqr + d*d - r*r) / (2 * sqrtl(Rsqr) * d)) <= 1);
        ld phi = acosl((Rsqr + d*d - r*r) / (2 * sqrtl(Rsqr) * d));

        // cout << phi << "\n";
        
        return {theta - phi, theta + phi};
    }

}

int sum[N];

void Solve(int tt){
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i] >> r[i];

        // x[i] *= -1;
        y[i] *= -1;
        // swap(x[i], y[i]);

        // cout << get
    }
    cin >> b >> d;
    vector<array<ld, 2>> vt;
    for(int i = 1; i <= n; i ++) {
        r[i] += b;
        
        ld Rsqr = 1LL * x[i] * x[i] + 1LL*y[i] * y[i];

        if(Rsqr > 1LL * (d + r[i]) * (d + r[i])) continue;

        auto[L,R] = getRange(x[i], y[i], r[i]);

        if(L < 0) {
            vt.push_back({0,R});
            vt.push_back({2*pi+L,2*pi});
        } else if(R > 2*pi) {
            vt.push_back({L,2*pi});
            vt.push_back({0,R-2*pi});
        } else {
            vt.push_back({L,R});
        }

    }

    sort(vt.begin(),vt.end());

    vector<ld> cc;

    for(auto[L,R]: vt) {
        cc.push_back(L);
        cc.push_back(R);
    }
    
    cc.push_back(0);
    cc.push_back(2*pi);
    sort(cc.begin(),cc.end());
    cc.erase(unique(cc.begin(),cc.end()),cc.end());



    for(auto[L,R]: vt) {
        int a = lower_bound(cc.begin(),cc.end(),L)-cc.begin();
        int b = lower_bound(cc.begin(),cc.end(),R)-cc.begin();
        
        sum[a] ++;
        sum[b] --;

    }

    long double ans = 0;

    for(int i = 0; i+1 < cc.size(); i ++) {
        if(i) sum[i] += sum[i-1];
        if(sum[i] == 0) {
            ans += cc[i+1] - cc[i];
        }
    }

    cout << setprecision(15) << fixed << ans / 2 / pi;
    
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;


    // vector<int> xs = {1,2,2,1,-1,-2,-2,-1};
    // vector<int> ys = {2,1,-1,-2,-1,-1,1,2} ;

    // for(int i = 0; i < xs.size(); i ++) {
    //     cout << getTheta(xs[i], ys[i]) << "\n";
    // }
        
}


/*
1.10715
0.463648
5.81954
5.17604
3.92699
3.60524
2.67795
2.03444
*/