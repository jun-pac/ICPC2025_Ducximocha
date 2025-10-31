

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

#define N 500030
#define MOD 998244353
#define INF 1000000007 

struct TwoSatSolver {
    int n_vars;
    int n_vertices;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices), used(n_vertices), order(), comp(n_vertices, -1), assignment(n_vars) {
        order.reserve(n_vertices);
    }
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n_vertices, false);
        for (int i = 0; i < n_vertices; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n_vertices, -1);
        for (int i = 0, j = 0; i < n_vertices; ++i) {
            int v = order[n_vertices - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n_vars, false);
        for (int i = 0; i < n_vertices; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }

    // static void example_usage() {
    //     TwoSatSolver solver(3); // a, b, c
    //     solver.add_disjunction(0, false, 1, true);  //     a  v  not b
    //     solver.add_disjunction(0, true, 1, true);   // not a  v  not b
    //     solver.add_disjunction(1, false, 2, false); //     b  v      c
    //     solver.add_disjunction(0, false, 0, false); //     a  v      a
    //     assert(solver.solve_2SAT() == true);
    //     auto expected = vector<bool>(True, False, True);
    //     assert(solver.assignment == expected);
    // }
} scc;

int n, l[N], r[N], x[N];

void addEdge(int lft, int rgt, int v) {
    if(lft == -1) {
        if(v) scc.add_disjunction(rgt, 0, rgt, 0);
        else scc.add_disjunction(rgt, 1, rgt, 1);
    } else {
        // lft --;
        if(v) {
            scc.add_disjunction(lft, 0, rgt, 0);
            scc.add_disjunction(lft, 1, rgt, 1);
        } else {
            scc.add_disjunction(lft, 1, rgt, 0);
            scc.add_disjunction(lft, 0, rgt, 1);
        }
    }
}

void Solve(int tt){
    
    cin >> n;
    
    for(int i = 0; i < n; i ++) {
        cin >> l[i] >> r[i] >> x[i];
    }
    
    for(int value = 0; value < 2; value ++) {
        
        scc = TwoSatSolver(n+10);
        // init_sat();
        
         scc.add_disjunction(n-1, !value, n-1, !value);

        for(int i = 0; i < n; i ++) {
            int lft = i - l[i];
            int rgt = i + r[i];

            if(lft < 0) {
                addEdge(n+lft-1, rgt, (x[i] - value + 2) % 2);
            } else if(rgt >= n) {
                addEdge(lft, rgt-n, (x[i] - value + 2) % 2);
            } else {
                addEdge(lft-1, rgt, x[i]);
            }

        }

        get_scc();
        bool works = r_sat_DFS();

        if(works) {
            
        }

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

