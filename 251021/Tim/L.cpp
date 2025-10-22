#include <bits/stdc++.h>

using namespace std;

int n;
string s;

bool works(int x) {
    int a_games = 0, b_games = 0, a_cur = 0, b_cur = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'A') {
            a_cur++;
        }
        else {
            b_cur++;
        }
        if(a_cur == x) {
            a_games++;
            a_cur = 0;
            b_cur = 0;
        }
        else if(b_cur == x) {
            b_games++;
            a_cur = b_cur = 0;
        }
    }
    return a_games > b_games;
}

int main() {
    cin>>s;
    n = s.size();
    s = '.' + s;
    vector<int> ans;
    for(int i= 1; i <= n; i++) {
        if(works(i)) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for(int x : ans) cout << x << ' ';
}