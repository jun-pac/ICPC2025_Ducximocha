#include <bits/stdc++.h>
using namespace std;

#define N 100000

vector<int> g[N], gr[N];
bool vis[N];
int comp[N], num_scc;
vector<int> order;

void dfs1(int u) {
    vis[u] = true;
    for(int v : g[u]) {
        if(!vis[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u, int c) {
    comp[u] = c;
    for(int v : gr[u]) {
        if(comp[v] == -1) dfs2(v, c);
    }
}

// Kosaraju's algorithm
void find_scc(int n) {
    // First DFS to get finish times
    fill(vis, vis + n + 1, false);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs1(i);
    }

    // Second DFS on reversed graph in reverse order
    fill(comp, comp + n + 1, -1);
    num_scc = 0;
    reverse(order.begin(), order.end());
    for(int u : order) {
        if(comp[u] == -1) {
            dfs2(u, num_scc++);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u); // reversed graph
    }

    find_scc(n);

    // comp[u] = SCC id of node u (0 to num_scc-1)
    // Build condensation graph if needed
}
