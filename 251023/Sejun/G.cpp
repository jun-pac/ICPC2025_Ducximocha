

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

string s;
int cnt[26];
void Solve(int tt){
    int n;
    cin>>s;
    n=s.size();
    int idx=0;
    bool flag=0;
    rng(j,1,7){
        bool temp=1;
        idx=j-7;
        while(idx<n){
            int r=min(n-1,idx+6);
            fill(cnt,cnt+26,0);
            rng(i,max(0,idx),r){
                if(cnt[s[i]-'A']>0){
                    temp=0;
                    break;
                }
                cnt[s[i]-'A']++;
            }
            idx+=7;
        }
        if(temp){
            flag=1;
        }
    }
    
    cout<<flag<<'\n';
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

