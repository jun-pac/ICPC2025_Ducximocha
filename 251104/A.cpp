#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 998244353;
const int INF = 1000000000;

int n;
string s[N];
vector<array<int,2>> vtt[5];

void solve() {
    cin >> n;
    vector<int> vt = {0,1,2,3,4};
    sort(vt.begin(),vt.end());
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
        switch(s[i][0]) {
            case 'S':
                vtt[0].push_back({stoi(s[i].substr(1,10000000)), i});
                break;
            case 'W':
                vtt[1].push_back({stoi(s[i].substr(1,10000000)), i});
                break;
            case 'E':
                vtt[2].push_back({stoi(s[i].substr(1,10000000)), i});
                break;
            case 'R':
                vtt[3].push_back({stoi(s[i].substr(1,10000000)), i});
                break;
            case 'C':
                vtt[4].push_back({stoi(s[i].substr(1,10000000)), i});
                break;
            default:
                break;
        }
    }
    for(int i = 0; i < 5; i ++) {
        sort(vtt[i].begin(),vtt[i].end());
    }
    //'S', 'W', 'E', 'R', 'C'
    int ans = INF;
    do {
        if(vt.back() != 4) continue;
        vector<int> lis;
        vector<int> ord;
        for(int i = 0; i < 5; i ++) {
            for(auto[v,j]: vtt[vt[i]]) {
                ord.push_back(j);
            }
        }
        for(int i: ord) {
            auto it = lower_bound(lis.begin(),lis.end(),i);
            if(it == lis.end()) lis.push_back(i);
            else lis[it-lis.begin()] = i;
        }
        ans = min(ans, n - (int)lis.size());
    } while(next_permutation(vt.begin(),vt.end()));
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}