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

int n, a[N];

map<long long,int> counts(int l, int r) {
    map<long long,int> mp;
    if(l >= r) return mp;
    for(int i = 0; i < (1<<(r-l)); i ++) {
        long long sum = 0;
        for(int j = 0; j < r-l; j ++) {
            if(i&1<<j) sum += a[l+j];
        }
        mp[sum] ++;
    }
    return mp;
}

void Solve(int tt){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<long long,int> l = counts(0,n/2), r = counts(n/2,n);
    for(auto[a,c]: l) {
        
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

