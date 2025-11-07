#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int v[3][2];

void solve() {
    for(int i = 0; i < 3; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    for(int i = 0; i< (1<<3); i ++) {
        vector<array<int,2>> vt;
        for(int j = 0; j < 3; j ++) {
            if(i&1<<j) vt.push_back({v[j][0],v[j][1]});
            else vt.push_back({v[j][1],v[j][0]});
        }
        sort(vt.begin(),vt.end());
        if(vt[0][0] == vt[1][0] && vt[1][0] == vt[2][0]) {
            if(vt[0][1] + vt[1][1] + vt[2][1] == vt[0][0]) {
                cout << "YES\n"; return;
            }
        }
        if(vt[0][0] == vt[1][0] && vt[0][1] + vt[1][1] == vt[2][1] && vt[2][1] == vt[0][0] + vt[2][0]) {
            cout << "YES\n";
            return;
        }
        swap(vt[0], vt[2]);
        if(vt[0][0] == vt[1][0] && vt[0][1] + vt[1][1] == vt[2][1] && vt[2][1] == vt[0][0] + vt[2][0]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}