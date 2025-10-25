

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

#define N 100005
#define MOD 998244353
#define INF 1000000007 

pll datas[N]; // pos, weight = idx+1, using weight as a idx
vc<int> edges[N][30];
ll dist[N][30];
ll ans[N];

void Solve(int tt){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1){
        cin>>datas[i].fi;
        datas[i].se=i+1;
    }
    datas[n]={0,0};

    sort(datas,datas+n+1);
    rng(u,0,29){
        ll span=(1LL<<u);
        set<pll> st; //{pos, idx}
        // st.insert(datas[0]);
        int l=0, r=0;

        rng(i,0,n){
            while(r<n+1 && datas[r].fi<=datas[i].fi+span){
                if(datas[r].se!=0) st.insert({datas[r].se,datas[r].fi});
                r++;
            }
            while(l<n+1 && datas[l].fi<datas[i].fi-span){
                if(datas[l].se!=0) st.erase({datas[l].se,datas[l].fi});
                l++;
            }
            auto it=st.end();
            for(int m=0; m<k; m++){
                if(it==st.begin()) break;
                it=prev(it); // current
                edges[datas[i].se][u].pb((it->first)); // weight
                // if((it->second)==1 && datas[i].se!=1) cout<<"what?"<<datas[i].se<<' '<<datas[i].fi<<' '<<u<<' '<<(it->second)<<'\n';
                // cout<<"idx1 lev idx2 "<<datas[i].se<<' '<<u<<' '<<(it->second)<<'\n';
            }
        }   
    }
    rng(i,0,n) fill(dist[i],dist[i]+30,INF);
    queue<pii> q;
    dist[0][0]=0;
    q.push({0,0});
    while(!q.empty()){
        pii temp=q.front();
        q.pop();
        int idx=temp.fi;
        int lev=temp.se;
        if(lev-1>=0 && dist[idx][lev-1]==INF){
            dist[idx][lev-1]=dist[idx][lev]+1;
            q.push({idx,lev-1});
        }
        if(lev+1<30 && dist[idx][lev+1]==INF){
            dist[idx][lev+1]=dist[idx][lev]+1;
            q.push({idx,lev+1});
        }
        for(auto next: edges[idx][lev]){
            if(dist[next][lev]==INF) {
                dist[next][lev]=dist[idx][lev]+1;
                q.push({next,lev});
            }
        }
    }

    fill(ans,ans+n+1, INF);
    rng(i,1,n){
        rng(j,0,29) ans[i]=min(ans[i],dist[i][j]); 
        cout<<(ans[i]==INF?-1:ans[i])<<'\n';
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

