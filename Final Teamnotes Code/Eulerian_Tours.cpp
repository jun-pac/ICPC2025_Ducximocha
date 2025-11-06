#include <bits/stdc++.h>
using namespace std;

// Eulerian Paths -- a path that goes through every edge exactly once
// Eulerian Tours - eulerian path that starts and ends at the same node

// a graph can have an Eulerian cycle (not path!) if and only if every node 
// has an even degree.

// The condition of existence for an eulerian path in a directed graph
// is: At most one node has out[i] - in[i]=1 and at most one node has 
// in[i] - out[i] = 1. This property is because an Eulerian path or 
// cycle leaves a node the same number of times it enters the node. 
// In a directed graph the exception are the start node and the end node.

{
    // Eulerian Tour

    int n, m;
    vector<vector<pair<int, int>>> g;
    vector<int> path;
    vector<bool> seen;

    void dfs(int node) {
        while (!g[node].empty()) {
            auto [son, idx] = g[node].back();
            g[node].pop_back();
            if (seen[idx]) { continue; }
            seen[idx] = true;
            dfs(son);
        }
        path.push_back(node);
    }

    int main() {
        cin >> n >> m;

        vector<int> degree(n, 0);
        g.resize(n);
        degree.resize(n);
        seen.resize(m);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back({y, i});
            g[y].emplace_back({x, i});
            degree[x]++;
            degree[y]++;
        }

        for (int node = 0; node < n; node++) {
            if (degree[node] % 2) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }

        dfs(0);

        if (path.size() != m + 1) {
            cout << "IMPOSSIBLE";
        } else {
            for (int node : path) { cout << node + 1 << ' '; }
        }
        cout << endl;
    }
}

{

    // Eulerian Path
    
    int n, m;
    vector<vector<int>> g;
    vector<int> in, out, path;

    void dfs(int node) {
        while (!g[node].empty()) {
            int son = g[node].back();
            g[node].pop_back();
            dfs(son);
        }
        path.push_back(node);
    }

    int main() {
        cin >> n >> m;

        g.resize(n + 1);
        in.resize(n + 1);
        out.resize(n + 1);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            out[x]++;
            in[y]++;
        }

        bool flag = true;
        for (int node = 2; node < n && flag; node++) {
            if (in[node] != out[node]) { flag = false; }
        }
        if (out[1] != in[1] + 1 || out[n] != in[n] - 1 || !flag) {
            cout << "IMPOSSIBLE";
            return 0;
        }

        dfs(1);

        reverse(path.begin(), path.end());
        if (path.size() != m + 1 || path.back() != n) {
            cout << "IMPOSSIBLE";
        } else {
            for (auto node : path) { cout << node << ' '; }
        }
    }
}