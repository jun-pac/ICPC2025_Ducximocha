// Bipartite matching

#include <bits/stdc++.h>
using namespace std;

#define N 100000

vector<int> edges[N];
vector<int> rev_edges[N]; // To find maximum independent set.
int pre[N];
bool visited[N];

bool DFS(int idx){
    // Bipartite matching
    if(visited[idx]) return false;
    visited[idx]=true;
    for(int i=0; i<edges[idx].size(); i++){
        int next=edges[idx][i];
        if(pre[next]==-1 || (!visited[pre[next]] && DFS(pre[next]))){
            pre[next]=idx;
            return true;
        }
    }
    return false;
}

void find_matching(int n) {
    int result = 0;
    fill(pre, pre+n+1, -1);
    for(int i = 1; i <= n; i ++) {
        fill(visited,visited+n+1,0);
        if(DFS(i)) result ++;
    }
}