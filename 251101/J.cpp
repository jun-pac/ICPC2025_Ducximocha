
// #include <bits/stdc++.h>
// using namespace std;
// #define fi first
// #define se second
// #define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
// #define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
// #define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
// #define pb push_back
// #define all(x) x.bg,x.ed
// template<class t> using vc=vector<t>;
// typedef long long ll;
// using pii=pair<int,int>;
// using pll=pair<ll,ll>;

// #define N 500030
// #define MOD 998244353
// #define INF 1000000007 

// long double h[N], p[N];
// int n, b, c[N];

// void Solve(int tt){
//     long double ans = 0;
//     cin >> n >> b;
//     for(int i = 0; i < n; i ++) {
//         cin >> c[i] >> h[i] >> p[i];
//         h[i] /= c[i]; p[i] /= c[i];
//         ans = max(ans, h[i] * p[i]);
//         for(int j = 0; j < i; j ++) {
//             if((p[i]-p[j]) * (h[i] - p[j]) >= 0) continue;
//             if(h[i] == h[j] || p[i] == p[j]) continue;
//             long double hv = (h[j] * (p[i] - p[j]) - p[j] * (h[i] - h[j]));
//             long double alpha = -(h[j] * (p[i] - p[j]) + p[j] * (h[i] - h[j])) / 2 / (h[i] - h[j]) / (p[i] - p[j]);
//             if(0<=alpha && alpha<=1) ans = max(ans, - hv * hv / 4 / (h[i] - h[j]) / (p[i] - p[j]));
//             // ans = max(ans, - hv * hv / 4 / (h[i] - h[j]) / (p[i] - p[j]));

//             // ans = max(ans, - hv * hv / 4 / (h[i] - h[j]) / (p[i] - p[j]));
//         }
//     }
//     cout << setprecision(15) << fixed << ans * b * b;
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int t=1;
//     // cin>>t;
//     rng(tt,0,t-1){
//         Solve(tt+1);
//     }
//     return 0;
// }



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

long double h[N], p[N];
int n, b, c[N];

void Solve(int tt){
    long double ans = 0;
    cin >> n >> b;
    for(int i = 0; i < n; i ++) {
        cin >> c[i] >> h[i] >> p[i];
        h[i] /= c[i]; p[i] /= c[i];
        // cout << h[i] << " " << p[i] << '\n';
        ans = max(ans, h[i] * p[i]);
        for(int j = 0; j < i; j ++) {
            // cout << "??? ";
            // (p[i]-p[j]) << " " << h[i]
            if((p[i]-p[j]) * (h[i] - h[j]) >= 0) continue;
            long double hv = (h[j] * (p[i] - p[j]) - p[j] * (h[i] - h[j]));
            // cout << hv << " ??\n";
            long double alpha = -(h[j] * (p[i] - p[j]) + p[j] * (h[i] - h[j])) / 2 / (h[i] - h[j]) / (p[i] - p[j]);
            if(0<=alpha && alpha<=1) ans = max(ans, - hv * hv / 4 / (h[i] - h[j]) / (p[i] - p[j]));
        }
    }
    cout << setprecision(15) << fixed << ans * b * b;
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



