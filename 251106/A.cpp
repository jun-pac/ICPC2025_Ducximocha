#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

string s[N];
bool adj[26][26];
int l, n, ins[26];

bool isLoop(int c, int rt, int& bt) {
    if(c != rt)
    bt |= 1<<c;
    if(c == rt && bt > 0) return 1;
    
    for(int i = 0; i < l; i ++) {
        if(adj[c][i] && (~bt&1<<i) && isLoop(i, rt, bt)) {
            return 1;
        }
    }

    return 0;
}

int counts1(int c, int&bt) {
    if(bt&1<<c) return 0;
    int cnt = 1;
    bt |= 1<<c;
    for(int i = 0; i < l; i ++) {
        if(adj[c][i]) cnt += counts1(i, bt);
    }
    return cnt;
}

int counts2(int c, int&bt) {
    if(bt&1<<c) return 0;
    int cnt = 1;
    bt |= 1<<c;
    for(int i = 0; i < l; i ++) {
        if(adj[i][c]) cnt += counts2(i, bt);
    }
    return cnt;
}

void solve() {
    char t;
    cin >> t >> n;
    l = t-'a'+1;
    for(int i = 0; i< n; i ++) {
        cin >> s[i];
        if(i) {
            if(s[i].size() <= s[i-1].size() || (s[i-1] != s[i].substr(0, s[i-1].size()))) {
                for(int j = 0; j < s[i-1].size(); j ++) {
                    if(s[i-1][j] != s[i][j]) {
                        adj[s[i-1][j]-'a'][s[i][j]-'a'] = 1;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0; i < l; i ++) {
        for(int j = 0; j < l; j ++) {
            if(adj[i][j]) {
                // cout << (char)(i+'a') << " "<< (char)(j+'a') << "\n";
                ins[j] ++;
            }
        }
    }
    queue<int> que;
    for(int i = 0; i < l; i ++) {
        int bt = 0;
        if(isLoop(i, i, bt)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    // cout << l << "\n";
    string ans(l, ' ');
    for(int i = 0; i < l; i ++) {
        int b1 = 0, b2 = 0;
        // cout << counts1(i,b1) << " " << counts2(i,b2) << "\n";
        b1 = 0, b2 = 0;
        if(counts1(i, b1) + counts2(i, b2) != l+1) {
            
            cout << "AMBIGUOUS"; return;
        }
        b1 = 0, b2 = 0;
        ans[l-counts1(i,b1)] = 'a' + i;
    }
    cout << ans;

    

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}