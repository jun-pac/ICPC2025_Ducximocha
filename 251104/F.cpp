#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=a; i<=b; i++)

const int N = 100005;
const int MOD = 998244353;
const int INF = 1000000000;

using ll=long long;
#define pb push_back

pair<int,int> datas[N];
int temp[6];
string names[N];

void solve() {
    int n;
    cin>>n;
    rng(i,0,n-1){
        string s;
        cin>>s;
        names[i]=s;
        int num;
        cin>>num;
        int res=0;
        res=10*num;
        rng(j,0,5){
            int x;
            cin>>x;
            temp[j]=x;
            res+=x;
        }
        sort(temp, temp+6);
        res-=temp[0];
        res-=temp[5];
        datas[i]={res, -i};
    }
    sort(datas,datas+n);
    reverse(datas,datas+n);
    int cnt=0, prev=-1; // cnt: strictly greater num
    
    rng(i,0,n-1){
        if(datas[i].first!=prev){
            prev=datas[i].first;
            cnt=i;
            if(cnt>2) break;            
        }
        cout<<names[-datas[i].second]<<' '<<datas[i].first<<'\n';
    }
    // rng(i,0,min(1000,rescnt)-1) cout<<names[-datas[i].second]<<' '<<datas[i].first<<'\n';
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}