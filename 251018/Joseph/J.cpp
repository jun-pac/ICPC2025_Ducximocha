

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

int n, ans = 0;
string s;
vector<int> adj[N];

stack<char> st;

void DFS(int c, int p) {
    if(s[c] == ')') {
        if(st.top() == '(') st.pop();
        else return;
    } else if(s[c] == ']') {
        if(st.top() == '[') st.pop();
        else return;
    } else if(s[c] == '}') {
        if(st.top() == '{') st.pop();
        else return;
    } else {
        st.push(s[c]);
    }
    if(st.size() == 1) ans ++;

    for(int i: adj[c]) {
        if(i == p) continue;
        DFS(i,c);
    }


    if(s[c] == ')') {
        st.push('(');
    } else if(s[c] == ']') {
        st.push('[');
    } else if(s[c] == '}') {
        st.push('{');
    } else {
        st.pop();
    }
}

void Solve(int tt){
    cin >> n >> s;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  
    s.insert(s.begin(), ' ');
    st.push(' ');
    for(int i = 1; i <= n; i ++) {  
        DFS(i,-1);
    }
    cout << ans;
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

