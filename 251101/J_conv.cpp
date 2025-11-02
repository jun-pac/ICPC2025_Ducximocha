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
using pll=pair<long double,long double>;
using ld=long double;

#define N 500030
#define MOD 998244353
#define INF 1000000007 

long double h[N], p[N], c[N];
int n, b;


pair<long double,long double> datas[N]; // Vertices // Convex hull algorithm never permute initial vertices.
int sorted_idx[N]; // Idx of 'sorted' datas.
int ans[N]; // Elements of convex hull

inline bool CCW(const pair<long double,long double>& a, const pair<long double,long double>& b, const pair<long double,long double>& c){
    return (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi)>0; 
}

inline long long dist(const pair<long double,long double>& a, const pair<long double,long double>& b){
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}

class comp_c{
public:
    pair<long double,long double> mp;
    comp_c(pair<long double,long double> minpos){
        mp=minpos;
    }
    bool operator()(int a_idx, int b_idx){
        pair<long double,long double> a=datas[a_idx], b=datas[b_idx];
        long double com=(a.fi-mp.fi)*(b.se-mp.se)-(a.se-mp.se)*(b.fi-mp.fi);
        if(com==0) return dist(a,mp)<dist(b,mp);
        else return com>0;
    }
};

// bool compare_t(int a_idx, int b_idx){
//     pair<long double,long double> a=datas[a_idx], b=datas[b_idx];
//     long double com=(a.fi-mp.fi)*(b.se-mp.se)-(a.se-mp.se)*(b.fi-mp.fi);
//     if(com==0) return dist(a,mp)<dist(b,mp);
//     else return com>0;

//     return 
// }
int convex_hull(int n){ // # number of vertices
    for(int i=0; i<n; i++) sorted_idx[i]=i;
    pair<ld,ld> pd={0.0,0.0};
    sort(sorted_idx,sorted_idx+n, comp_c(pd));
    
    // Phase 2: Get Convexhull
    int st[N]; // Elements of st are the idx of datas 
    int cur=0, st_cnt=0; // cur : # of visited elements of s, st_cnt : # of elements in stack
    while(cur<n){
        while(st_cnt>=2 && !CCW(datas[st[st_cnt-2]],datas[st[st_cnt-1]],datas[sorted_idx[cur]])) st_cnt--;
        st[st_cnt++]=sorted_idx[cur++];
    }
    for(int i=0; i<st_cnt; i++) ans[i]=st[i]; // Counter clockwise, starts with leftmost vertices.
    return st_cnt;
}



void Solve(int tt){
    // long double ans = 0;
    cin >> n >> b;
    ld res=0;

    for(int i = 0; i < n; i ++) {
        cin >> c[i] >> h[i] >> p[i];
        h[i] /= c[i]; p[i] /= c[i];
        datas[i]={h[i],p[i]};
        res=max(res,h[i]*p[i]);
    }
    int m = convex_hull(n);
        
    for(int i = 0; i < m; i ++) {
        // cout << h[i] << " " << p[i] << '\n';
        ld h1=datas[ans[i]].fi;
        ld p1=datas[ans[i]].se;
        int j=(i-1+m)%m;
        res=max(res,h1*p1);
        ld h2=datas[ans[j]].fi;
        ld p2=datas[ans[j]].se;

        if((p1-p2) * (h1 - h2) >= 0) continue;
        long double hv = (h2 * (p1 - p2) - p2 * (h1 - h2));
        ld alpha = -(h2 * (p1 - p2) + p2 * (h1 - h2)) / 2 / (h1 - h2) / (p1 - p2);
        if(0<=alpha && alpha<=1) res = max(res, - hv * hv / 4 / (h1 - h2) / (p1 - p2));
    }

    cout << setprecision(15) << fixed << res * b * b;
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

