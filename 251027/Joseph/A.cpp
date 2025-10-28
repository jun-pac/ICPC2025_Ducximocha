

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

int n;
vector<int> vt[11];

void Solve(int tt){
    cin >> n;



    for(int i = 1; i <= 10; i++) {
        vt[i].clear();
    }
    while(n--) {
        int a, b; cin >> a >> b;
        vt[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= 10; i ++) {
        sort(vt[i].begin(),vt[i].end());
        if(vt[i].empty()) {
            cout << "MOREPROBLEMS\n"; return;
        }
        ans += vt[i].back();
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

