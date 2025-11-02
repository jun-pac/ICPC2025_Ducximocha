

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

#define N 2100
#define MOD 998244353
#define INF 1000000007 

int n, m, c, x, y, v[N];
string g[N];

vector<int> edges[N];
int flow[N][N]; // Use map if N is larger than 20000
int capa[N][N];
int levels[N];
bool visited[N];
int work[N];
 
void add_edge(int a, int b, int c){ // edge a->b (c)
    // this is NOT bidirectional!
	edges[a].push_back(b); flow[a][b]=0; capa[a][b]=c;
	edges[b].push_back(a); flow[b][a]=0; capa[b][a]=0;
	// If capa accumulate, 
    //edges[a].push_back(b); flow[a][b]=0; capa[a][b]=c;
	//edges[b].push_back(a); flow[b][a]=0; capa[b][a]=0;
}
 
void level_BFS(int s){
	fill(visited,visited+N,false);
	queue<pair<int,int>> q;
	q.push({s,0});
	while(!q.empty()){
		int idx=q.front().first;
		int level=q.front().second;
		q.pop();
		if(visited[idx]) continue;
		levels[idx]=level;
		visited[idx]=true;
		for(int i=0; i<edges[idx].size(); i++){
			int next=edges[idx][i];
			if(!visited[next] && capa[idx][next]>flow[idx][next]){
				q.push({next,level+1});
			}
		}
	}
}
 
int main_DFS(int idx, int f, int t){
	visited[idx]=true;
	if(idx==t || f==0) return f;
	for(int &i=work[idx]; i<edges[idx].size(); i++){
		int next=edges[idx][i];
		if(!visited[next] && levels[next]==levels[idx]+1 && capa[idx][next]>flow[idx][next]){
			int f_temp=main_DFS(next,min(f,capa[idx][next]-flow[idx][next]),t);
			if(f_temp==0) continue;
			flow[idx][next]+=f_temp;
			flow[next][idx]-=f_temp;
			return f_temp;
		}
	}
	return 0;
}
 
int DINIC(int s, int t){
	int result=0;
	while(true){
		levels[t]=-1;
		level_BFS(s);
		if(levels[t]==-1) break;
 
		fill(work,work+N,0);
		while(true){
			fill(visited,visited+N,false);
			int f_temp=main_DFS(s,INF,t);
			if(f_temp==0) break;
			result+=f_temp;
		}
	}
	return result;
}

int getId(int x, int y) {
    return x*m+y;
}

void Solve(int tt){
    cin >> m >> n >> c;
    for(int i = 0; i < n; i ++) {
        cin >> g[i];
        for(int j = 0; j < m; j ++) {
            if(g[i][j] == 'B') {
                x = i; y = j;
            }
        }
    }
    for(int i = 0; i < c; i++) {
        cin >> v[i];
    }
    int s = 2000, t = 2001;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                add_edge(getId(i,j)*2+1, t, 1e9);
            }
            if(g[i][j] == 'B') {
                add_edge(s, getId(i,j)*2, 1e9);
            }
            int c;
            if(g[i][j] == 'B' || g[i][j] == '.') c = 1e9;
            else c = v[g[i][j] - 'a'];
            add_edge(getId(i,j)*2,getId(i,j)*2+1,c);
            if(i + 1 < n) {
                add_edge(getId(i,j)*2+1, getId(i+1,j)*2, 1e9);
            }
            if(i - 1 >= 0) {
                add_edge(getId(i,j)*2+1, getId(i-1,j)*2, 1e9);                
            }
            if(j + 1 < m) {
                add_edge(getId(i,j)*2+1, getId(i,j+1)*2, 1e9);
            }
            if(j - 1 >= 0) {
                add_edge(getId(i,j)*2+1, getId(i, j-1)*2,1e9);
            }
        }
    }
    // cout << "??\n";
    // for(int i = 0; i < n; i )
    int v = DINIC(s,t);

    if(v == 1e9) cout << "-1";
    else cout << v;
    
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

