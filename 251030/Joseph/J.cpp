

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

int n, a[N], nxt[N];

void Solve(int tt){
    cin >> n;

    nxt[n+1] = n+1;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = n; i>= 1; i--) {
        if(a[i] == 1) nxt[i] = nxt[i+1];
        else nxt[i] = i;

    }

    long long maxv = 2000000000000000LL;


    long long ans = 0;
    for(int l = 1; l < n; l ++) {
        int r = l+1;
        long long sum = a[l] + a[r], prod = 1LL * a[l] * a[r];

        while(prod <= maxv) {
            int nr = nxt[r+1];
            int cnt = nr - r;
            // cout << l<< " " << r << "\n";
            // cout << sum << " " << prod << "\n\n";
            // cout << sum+cnt-1 << "\n";

            if(prod >= sum && prod <= sum+cnt-1) {
                ans ++;
            }

            if(nr == n+1 || (__int128)prod * a[nr] > maxv) break;
            prod = prod * a[nr];
            sum = sum + a[nr] + cnt - 1;
            r = nr;

        }

    }

    cout << ans;

}

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

