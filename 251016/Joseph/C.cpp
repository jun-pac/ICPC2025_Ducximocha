// 7z e name.zip [And enter the password]
// 7z -P password name.zip
// ./A < name.txt > output.txt

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

int n, D, L, v[N];

bool works(long long T) {

    vector<int> cnt(n+1,0);

    for(int i = 1; i <= n; i ++) {
        if(v[i]+L > T) return false;
        long long c = (T - v[i] - L) / D;
        if(c <= n) cnt[c] ++;
    }
    long long vs = 1;
    for(int i = 0; i <= n; i ++) {
        vs -= cnt[i];
        if(vs < 0) return false;
        vs = min(n+1LL, vs*2);
    }

    return true;

}
void Solve(int tt){
    cin >> n >> D >> L;
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
    }
    long long l = 0, h = 1e17, ans;
    while(l <= h) {
        long long m = (l+h)>>1;
        if(works(m)) {
            ans =m;
            h = m-1;
        } else {
            l = m+1;
        }
    }
    cout << ans << "\n";
    
    // cout<<"Case #"<<tt<<": ";   
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

