
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 400030
#define MOD 1000000007
#define MAX_DIGIT 62

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

string s;
string sr;
ll p1=4999;
ll h1[N], h1_reverse[N];
ll p1pow[N];

void Solve(){
    int n;
    cin>>n;
    cin>>s;
    sr.resize(n);
    rng(i,0,n) p1pow[i]=(i==0?1:p1pow[i-1]*p1)%MOD;
    // rng(i,0,n-1) cout<<p1pow[i]<<' '; cout<<'\n';

    rng(i,0,n-1) sr[i]=s[n-1-i];
    rng(i,0,n-1){
        h1[i]=((i==0?0:h1[i-1])*p1+(s[i]-'a'))%MOD;
        h1_reverse[i]=((i==0?0:h1_reverse[i-1])*p1+(sr[i]-'a'))%MOD;
    }

    // rng(i,0,n-1) cout<<h1[i]<<' '; cout<<'\n';
    // rng(i,0,n-1) cout<<h1_reverse[i]<<' '; cout<<'\n';
    int mx=1;
    rng(i,2,n){
        ll val1=(h1[n-1]-(i==n?0:h1[n-1-i])*p1pow[i]%MOD)%MOD;
        ll val1_rev=(h1_reverse[i-1])%MOD;
        
        val1=(val1+MOD)%MOD;
        val1_rev=(val1_rev+MOD)%MOD;
        
        // cout<<val1<<' '<<val1_rev<<'\n';
        if(val1==val1_rev) mx=max(mx,i);
    }

    cout<<n-mx<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

