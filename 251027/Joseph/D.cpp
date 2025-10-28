

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

int n, m, a[N], P[N];
vector<int> x;

void Solve(int tt){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> P[i];
        a[i] = (i-1)*100;
    }
    x.resize(m);
    for(auto&i: x) cin >> i;
    x.push_back(-1e9); x.push_back(1e9);
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    long long ans =0;
    // cout << "Yo, what?"
    for(int p = 1, i = 0; i+1 < x.size(); i ++) {
        vector<array<int,3>> rg;
        while(p <= n && a[p] < x[i]) p ++;
        while(p <= n && a[p] <= x[i+1]) {
            rg.push_back({max(x[i]+1,2*a[p]-x[i+1]+1),min(x[i+1],2*a[p]-x[i]),P[p]});
            p ++;
        }
        p = max(1, p-1);
        sort(rg.begin(),rg.end());
        long long cur = 0;
        priority_queue<array<int,2>> pq;
        for(auto[l,r,v]: rg) {
            // cout << l << " " << r<< " " << v << "\n";
            cur += v;
            pq.push({-(r+1),-v});
            while(pq.size() && -pq.top()[0] <= l) {
                cur += pq.top()[1]; pq.pop();
            }
            ans = max(ans, cur);
        }
        // cout << "\n";
    }
    cout << ans;
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

