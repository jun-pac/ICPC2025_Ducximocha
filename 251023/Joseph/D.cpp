

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
using ld = long double;

int n;
long long x[N], y[N], pr[N];

long long area(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long a = x2-x1, b = y2-y1;
    long long c = x3-x1, d = y3-y1;
    // cout<<"B1 "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
    return abs(a*d - b*c);
}

ld val(int id, ld p) {
    ld sum = pr[id-1];
    sum += (pr[id] - pr[id-1]) * (2 * p - 1);
    sum -= pr[n-1] - pr[id];
    
    return sum;
}

void Solve(int tt){
    cin >> n;
    cout << setprecision(15)<< fixed;
    for(int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
        // cout<<x[i]<<' '<<y[i]<<'\n';
    }
    pr[1]=0;
    for(int i = 2; i < n; i ++) {
        pr[i] = pr[i-1] + area(x[1], y[1], x[i], y[i], x[i+1], y[i+1]);
    }
    for(int i = 2; i < n; i ++) {
        ld l = 0, h = 1;
        for(int z = 0; z < 100; z ++) {
            ld m = (l+h)/2;
            if(val(i,m) > 0) {
                h = m;
            } else {
                l = m;
            }
            // cout << l<<' '<<h<<' '<<val(i,m) << "\n";
        }
        // cout << l << " " << h << "\n";
        // cout << h-l << "\n";
        // cout << val(i,l) << "\n";
        // cout << abs(val(i,l))/pr[n-1] << "\n";
        if(abs(val(i,l))/pr[n-1] < 1e-6) {
            cout << fixed << setprecision(15);
            cout << x[i]+(x[i+1]-x[i])*l << " " << y[i]+(y[i+1]-y[i])*l;
            return;
        }
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

