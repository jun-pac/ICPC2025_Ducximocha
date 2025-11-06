#include <bits/stdc++.h>
using namespace std;

#define N 100000

vector<int> g[N];
int parent[N], depth[N], sz[N];
int head[N], pos[N], timer;

void dfs_sz(int u, int p = -1) {
    sz[u] = 1;
    parent[u] = p;
    for(int &v : g[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
}

void dfs_hld(int u, int p = -1) {
    pos[u] = ++timer;
    for(int v : g[u]) {
        if(v == p) continue;
        head[v] = (v == g[u][0] ? head[u] : v);
        dfs_hld(v, u);
    }
}

int lca(int u, int v) {
    while(head[u] != head[v]) {
        if(depth[head[u]] < depth[head[v]]) swap(u, v);
        u = parent[head[u]];
    }
    return depth[u] < depth[v] ? u : v;
}

// Query path from u to v (use segment tree on pos[])
void path_query(int u, int v) {
    while(head[u] != head[v]) {
        if(depth[head[u]] < depth[head[v]]) swap(u, v);
        // Query segment tree: [pos[head[u]], pos[u]]
        u = parent[head[u]];
    }
    if(depth[u] > depth[v]) swap(u, v);
    // Query segment tree: [pos[u], pos[v]]
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    depth[1] = 0;
    dfs_sz(1);
    head[1] = 1;
    timer = 0;
    dfs_hld(1);

    // pos[u] = position of node u in segment tree
    // Use segment tree for path/subtree queries
}
