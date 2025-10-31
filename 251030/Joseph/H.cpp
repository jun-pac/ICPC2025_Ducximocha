

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

int n, m, v[N];
map<int,vector<int>> mp;

void Solve(int tt){
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        string s; cin >> s;
        if(s[1] != '.') s.erase(s.begin()+2);
        else s.erase(s.begin() + 1);
        v[i] = stoi(s);
        if(!mp.count(v[i])) mp[v[i]] = vector<int>();
        mp[v[i]].push_back(i);
    }

    const int B = 100;

    mt19937 random((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
    // const ll B = uniform_int_distribution<ll>(0, n-1)(random);


    // for(int i = 0; i< 100; i ++) {
    //     cout << uniform_int_distribution<ll>(0, 100)(random) << "\n";
    // }
    while(m--) {
        int l, r; cin >> l >> r;

        bool w = 0;
        for(int z = 0; z < B; z ++) {

            // uniform_int_distribution<int> dist(1, n);

            int i = uniform_int_distribution<ll>(l, r)(random);

            // cout << i << " "

            // cout << i << "??\n";

            int vs = v[i];

            int cnt = upper_bound(mp[vs].begin(),mp[vs].end(),r)-lower_bound(mp[vs].begin(),mp[vs].end(),l);

            if(cnt >= (r-l+1) / 2 + 1) {
                cout << "usable\n"; 
                w = 1;
                break;
            }
                
        }
        if(!w) cout << "unusable\n";

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

