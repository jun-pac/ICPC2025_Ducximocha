#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3+5;
int n, ans;
vector<int> adj[MAXN];
string s;

stack<char> st;

void dfs(int x, int p, int a, int b, int c) {
    //cout << x << ' ' << p << ' ' << a << ' ' << b << ' ' << c << '\n';
    if(a==0&&b==0&&c==0) {
        ans++;
    }
    if(a<0 || b<0||c<0) return;
    for(int nxt : adj[x]) {
        if(nxt == p) continue;
        if(s[nxt] == '(') {
            dfs(nxt, x, a+1, b, c);
        }
        else if(s[nxt] == ')') {
            dfs(nxt, x, a-1, b, c);
        }
        else if(s[nxt] == '[') {
            dfs(nxt, x, a, b+1, c);
        }
        else if(s[nxt] == ']') {
            dfs(nxt, x, a, b-1, c);
        }
        else if(s[nxt] == '{') {
            dfs(nxt, x, a, b, c+1);
        }
        else {
            dfs(nxt, x, a, b, c-1);
        }
    }
}

int main() {
    cin>>n>>s;
    s = "." + s;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i<= n; i++) {
        if(s[i] == '(') dfs(i, -1, 1, 0, 0);
        if(s[i] == '[') dfs(i, -1, 0, 1, 0);
        if(s[i] == '{') dfs(i, -1, 0, 0, 1);
    }
    cout << ans;
}