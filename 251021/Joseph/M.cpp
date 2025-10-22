

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


int l, h, n, p[N], dp[N][2], s[N];

int query(int L, int R) {
    if(L > R) return 0;
    return s[R] - s[L-1];
}

vector<int> dv[N];

void Solve(int tt){
    cin >> n >> l >> h;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i];
        s[i] = s[i-1] + p[i];
    }
    for(int i = l; i <= h; i ++) {
        for(int j = i; j <= n; j += i) {
            dv[j].push_back(i);
        }
    }
    long long sum = 0;

    int ans1 = 0, ans2 = 1e9;
    for(int lng = l; lng <= h; lng ++) {
        vector<int> cnt(lng+1, 0);
        for(int i = 1; i <= lng; i ++) {
            cnt[(i+1)%lng] += query(1, i) > 0;
        }
        for(int i = 2; i <= n; i ++) {
            cnt[i%lng] += query(i, min(i+lng-1,n)) > 0;
        }
        for(int i = 1; i <= n; i++) {
            ans1 = max(ans1, cnt[i%lng]);
            ans2 = min(ans2, cnt[i%lng]);
        }
    }
    cout << ans2 << " " << ans1;
    
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

