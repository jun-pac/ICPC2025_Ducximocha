#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

struct TwoSat {
    int n_vars;
    int n_vert;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSat(int _n) : n_vars(_n), n_vert(2 * _n), adj(2 * _n), adj_t(2 * _n), used(2 * _n), order(), comp(2 * _n, -1), assignment(2 * _n) {
        order.reserve(2 * _n);
    }

    void dfs1(int v) {
        used[v] = 1;
        for(int u: adj[v]) {
            if(!used[u]) {
                dfs1(u);
            }
        }
        order.push_back(v);
    }

    void dfs2(int v, int c1) {
        comp[v] = c1;
        for(int u: adj_t[v]) {
            if(comp[u] == -1) {
                dfs2(u, c1);
            }
        }
    }

    bool solve_2SAT() {
        order.clear(); used.assign(n_vert, false);
        for(int i = 0; i < n_vert; i ++) {
            if(!used[i]) {
                dfs1(i);
            }
        }

        comp.assign(n_vert, -1);
        for(int i = 0, j = 0; i < n_vert; i ++) {
            int v = order[n_vert - i - 1];
            if (comp[v] == -1) {
                dfs2(v, j++);
            }
        }

        assignment.assign(n_vars, false);
        for(int i = 0; i< n_vert; i += 2) {
            // cout << comp[i] << " " << comp[i+1] << " ";
            if(comp[i] == comp[i+1]) {
                return 0;
            }
            assignment[i/2] = comp[i] > comp[i+1];
        }

        return 1;
    }

    // a -> b
    void add_disjunction(int a, bool na, int b, bool nb) {
        a = 2*a^na;
        b = 2*b^nb;
        int neg_a = a^1;
        int neg_b = b^1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }

};

int n, x[N], y[N];
TwoSat ts(1);
bool test(int p) {
    ts = TwoSat(n);
    // TwoSat ts(n+10);
    for(int i = 0; i < n; i ++) {
        for(int j = i+1; j < n; j ++) {
            if(x[i] == x[j]) {
                if(abs(y[i] - y[j]) <= p*2) {
                    // cout << i << " " << j << "\n";
                    ts.add_disjunction(i, 1, j, 1);
                    // ts.add_disjunction(i, 1, j, 0);
                    // ts.add_disjunction(i, 0, j, 1);
                    // ts.add_disjunction(j, 0, i, 0);
                }
            }
            if(y[i] == y[j]) {
                if(abs(x[i] - x[j]) <= p*2) {
                    ts.add_disjunction(i, 0, j, 0);
                    // cout << "! " << i << " " << j << "\n";
                    // ts.add_disjunction(j, 1, i, 1);
                }
            }
        }
    }
    // for(auto i: ts.adj) {
    //     for(auto j: i) cout << j << " "; cout << "\n";
    // }
    return ts.solve_2SAT();
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> x[i] >> y[i];
    }
    int l = 0, h = 1000005;
    while(l < h) {
        int m = (l+h+1)>>1;
        if(test(m)) {
            l = m;
        } else {
            h = m-1;
        }
    }
    // cout << test(100) << "\n";
    if(l > 1000000) cout << "UNLIMITED";
    else cout << l;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}