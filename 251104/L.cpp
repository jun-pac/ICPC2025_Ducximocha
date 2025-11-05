#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MOD = 998244353;
const int INF = 1000000000;

int k, n;

vector<int> vt[4][4];
string ans[3];

void push(int a, int b, int id) {
    if(a == 3) {
        for(int i = 0; i < b; i ++) {
            ans[0].push_back(id);
            ans[1].push_back(id);
            ans[2].push_back(id);
        }
    } else if(a == 2) {
        for(int i = 0; i < b; i ++) {
            ans[0].push_back(id);
            ans[1].push_back(id);
        }
    }
}

int as[N], bs[N];

void solve() {
    cin >> k >> n;
    int id = 1;

    for(int i = 1; i <= k; i ++) {
        cin >> as[i];
    }

    for(int i = 1; i <= k; i ++) {
        cin >> bs[i];
    }

    for(int i = 1; i <= k; i ++) {
        int a= as[i], b = bs[i];
        int id = i;
        vt[a][b].push_back(id);
    }
    
    for(int a = 2; a <= 3; a ++) {
        int b = 3;
        while(vt[a][b].size()) {
            push(3,a,vt[a][b].back());
            vt[a][b].pop_back();
        }
    }

    while(vt[2][2].size()) {
        push(2,2,vt[2][2].back());
        vt[2][2].pop_back();
    }

    while(vt[1][3].size() && (int)ans[0].size() >= (int)ans[2].size() + 2) {
        int id = vt[1][3].back(); vt[1][3].pop_back();
        ans[2].push_back(id);
        ans[2].push_back(id);
        ans[2].push_back(id);
    }

    while(vt[1][2].size()) {
        int id = vt[1][2].back(); vt[1][2].pop_back();
        if(ans[0].size() > ans[2].size()) {
            ans[2].push_back(id);
            ans[2].push_back(id); 
        } else {
            ans[0].push_back(id);
            ans[1].push_back(id);
        }
    }

    while(vt[1][1].size()) {
        int id = vt[1][1].back(); vt[1][1].pop_back();
        int sz = min({ans[0].size(),ans[1].size(),ans[2].size()});
        for(int i = 0; i < 3; i ++) {
            if(ans[i].size() == sz) {
                ans[i].push_back(id);
                break;
            }
        }
    }

    assert(ans[0].size() == ans[1].size() && ans[1].size() == ans[2].size());

    while(vt[1][3].size()) {
        int id = vt[1][3].back(); vt[1][3].pop_back();
        for(int i = 0; i < 3; i ++) {
            ans[i].push_back(id);
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j: ans[i]) cout << j << " ";
        cout << "\n";
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}