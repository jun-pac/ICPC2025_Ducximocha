

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

bool pos[10][10];
pii datas[4];
void Solve(int tt){
    ll n;
    cin>>n;
    n=n+n/13+15;
    int kk=0;
    while(kk<4){
        if(pos[(n/10)%10][n%10]) n=n+n/13+15;
        else{
            pos[(n/10)%10][n%10]=1;
            datas[kk++]={(n/10)%10,n%10};
            n=n+n/13+15;
            // cout<<"d "<<datas[i].fi<<' '<<datas[i].se<<'\n';
            // kk++;
        }
    }
    int cnt=0, kcnt=0;
    while(cnt<4){
        kcnt++;
        int x;
        cin>>x;
        int a=x/10;
        int b=x%10;
        if(pos[a][b]){
            cnt++;
            pos[a][b]=0;
            cout<<"You hit a wumpus!\n";
            if(cnt==4){
                cout<<"Your score is "<<kcnt<<" moves.\n";
                return;
            }
        }
        int mn=100;
        rng(i,0,9) rng(j,0,9){
            if(pos[i][j]) mn=min(mn,abs(i-a)+abs(j-b));
        }
        // cout<<"cnbt "<<cnt<<'\n';
        cout<<mn<<'\n';
        // if(kcnt>251) break;
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

