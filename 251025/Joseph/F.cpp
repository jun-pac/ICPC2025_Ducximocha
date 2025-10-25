#include <bits/stdc++.h>

#define N 1000
#define INF 1000000007000000007LL

using namespace std;

vector<pair<int,long long>> edges[N]; // next, cost. // Must initialize after each testcase
int capa[N][N];
int flow[N][N];
bool inQ[N]; // (inQ[i]) means dist[i] changed ans need to be visited.
int pre[N];
long long dist[N];

void add_edge(int a, int b, long long w, int f){
    // a->b cost:w capa:f (Reverse edge has negative weight)
    edges[a].push_back({b,w}); capa[a][b]=f; flow[a][b]=0;
    edges[b].push_back({a,-w}); capa[b][a]=0; flow[b][a]=0;
}

void floyd_warshall(int s){ // maximum O(n*min(n,m))
    // Use floyd-warshall instead of dijkstra is because, negative weight edges exist
    // Only update pre[], dist[] 
    fill(inQ, inQ+N, false);
    fill(dist, dist+N, INF);
    queue<int> q;
    q.push(s);
    inQ[s]=true; // To maintain light queue
    dist[s]=0;
    while(!q.empty()){
        int idx=q.front(); inQ[idx]=false;
        q.pop();
        for(int i=0; i<edges[idx].size(); i++){
            int next=edges[idx][i].first; long long w=edges[idx][i].second; 
            if(capa[idx][next]-flow[idx][next]>0 && dist[idx]+w<dist[next]){
                dist[next]=dist[idx]+w;
                pre[next]=idx;
                if(!inQ[next]) q.push(next);
                inQ[next]=true;
            }
        }
        
    }
}

long long MCMF(int s, int t){
    // Return minimum cost for maximum flow
    long long res=0;
    while(true){
        floyd_warshall(s);
        if(dist[t]==INF) break;
        // Get flow
        int cur=t, ff=INF;
        while(cur!=s){
            ff=min(ff,capa[pre[cur]][cur]-flow[pre[cur]][cur]);
            cur=pre[cur];
        }
        // Flow update
        cur=t;
        while(cur!=s){
            flow[pre[cur]][cur]+=ff;
            flow[cur][pre[cur]]-=ff;
            cur=pre[cur];
        }
        res+=dist[t]*ff;
    }
    return res;
}

void resets() {
    for(auto&i: edges) i.clear();
    for(auto&i: capa) for(auto&j: i) j = 0;
    for(auto&i: flow) for(auto&j: i) j = 0;
    for(auto&i: pre) i = 0;
}

int n, m, s[N], g[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<array<int,2>> sg;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i] >> g[i];
        sg.push_back({s[i],g[i]});
    }


    // resets();

    // add_edge(1, 2, 100, 3);

    // cout << MCMF(1,2) << "\n";

    resets();

    long long minV = 1e18, maxV = 0;
    sort(sg.begin(),sg.end());

    for(int w = n-1; w < n; w ++) {
        resets();
        int S = 0, T = 1;
        for(int i = 0; i <= w; i ++) {
            auto[s,g] = sg[i];
            add_edge(S, i + 2, 0, g - (i != w));
            add_edge(i+w+3, T, 0, 1);
            for(int j = 0; j < i; j ++) {
                auto[s2,g2] = sg[j];
                add_edge(i+2, j+w+3, s ^ s2, 1);
            }
        }
        minV = min(minV, MCMF(S,T));
        resets();
        for(int i = 0; i <= w; i ++) {
            auto[s,g] = sg[i];
            add_edge(S, i + 2, 0, g - (i != w));
            add_edge(i+w+3, T, 0, 1);
            for(int j = 0; j < i; j ++) {
                auto[s2,g2] = sg[j];
                add_edge(i+2, j+w+3, -(s ^ s2), 1);
            }
        }
        maxV = max(maxV, -MCMF(S,T));

    }
    cout << minV << " " << maxV;

}