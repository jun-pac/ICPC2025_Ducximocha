#include <bits/stdc++.h>
using namespace std;

#define N 100000

vector<int> g[N];
int tin[N], tout[N], timer;

void dfs(int u, int p = -1) {
    tin[u] = ++timer;
    for(int v : g[u]) {
        if(v != p) dfs(v, u);
    }
    tout[u] = timer;
}

// Check if u is ancestor of v
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
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

    timer = 0;
    dfs(1);

    // Subtree of node u is [tin[u], tout[u]]
    // Can use segment tree/BIT on this range
}
