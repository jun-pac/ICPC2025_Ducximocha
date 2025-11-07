#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int n;

bool dones(vector<int> vt) {
    for(int i = 1; i < vt.size(); i ++) {
        if(vt[i] != vt[i-1]) return 0;
    }
    return 1;
}

vector<int> step(vector<int> vt) {
    vector<int> nvt;
    for(int i = 1; i < vt.size(); i ++) {
        nvt.push_back(vt[i]-vt[i-1]);
    }
    return nvt;
}

// vector<int> adds()

void solve() {
    int n; cin >> n;
    vector<int> vt(n);
    for(auto&i: vt) cin >> i;
    vector<vector<int>> vts(1,vt);
    for(int z = 0;; z ++) {
        if(dones(vt)) {
            vts.back().push_back(vts.back().back());
            for(int i = vts.size()-1; i > 0; i --) {
                vts[i-1].push_back(vts[i].back() + vts[i-1].back());
            }
            cout << z << " " << vts[0].back() << "\n";
            return;
        } else {
            vt = step(vt);
            vts.push_back(vt);
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}