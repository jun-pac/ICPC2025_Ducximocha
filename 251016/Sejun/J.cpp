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

int datas[1001][1001];

void Solve(int tt){
    
    int n,k;
    cin>>n>>k;
    datas[0][0]=1;
    int cnt=(k==1?1:0);

    rng(i,1,n){
        rng(j,0,i){
            datas[i][j]=(datas[i-1][j]+datas[i-1][j-1])%k;
            if(datas[i][j]==0) cnt++;
        }
    }
    cout<<cnt<<'\n';
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

