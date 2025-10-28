

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

int n, a, b, p[N], len, ds[N];


struct Tree {
    array<int,2> tree[1<<20];
    
    void update(int a, int v) {
        tree[a+len] = {v, a};
        for(a = (a+len)>>1; a >= 1; a >>= 1) {
            tree[a] = min(tree[a*2], tree[a*2+1]);
        }
    }
    
    array<int,2> query(int a, int b) {
        array<int,2> res = {(int)1e9,-1};
        for(a += len, b += len; a <= b; a >>= 1, b >>= 1){ 
            if(a&1) res = min(res, tree[a++]);
            if(~b&1) res = min(res, tree[b--]);
        }
        return res;
    }
    
    void erase(int a) {
        update(a, 1e9);
    }

    void init() {
        for(int i = 0; i <= len*2; i ++) {
            tree[i] = {(int)1e9,0};
        }
    }
} tree1, tree2;

void Solve(int tt){
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i];
        ds[i] = -1;
    }
    len = 1;
    while(len <= n+5) {
        len <<= 1;
    }
    tree1.init(); tree2.init();
    for(int i = 1; i <= n; i ++) {
        tree2.update(i, i-p[i]);
        tree1.update(i, -(i+p[i]));
    }
    queue<int> que;
    que.push(a); tree1.erase(a); tree2.erase(a);
    ds[a] = 0;
    // cout << tree2.query(2,3)[0] << "\n";

    while(que.size()) {
        int c = que.front(); que.pop();
        // cout << c << " visited!\n";
        if(c == b) {
            cout << ds[c] << "\n"; return;
        }
        // cout << tree2.query(c,min(n,c+p[c]))[1] << "\n";
        while(-tree1.query(max(0,c-p[c]),c)[0] >= c) {
            int i = tree1.query(max(0,c-p[c]),c)[1];
            tree2.erase(i); tree1.erase(i);
            if(ds[i] == -1) {
                ds[i] = ds[c]+1;
                que.push(i);
            }
        }
        // cout << c << " " << c+p[c] << "\n";
        // cout << tree2.query(c,min(n,c+p[c]))[1] << "\n";
        while(tree2.query(c,min(n,c+p[c]))[0] <= c) {
            int i = tree2.query(c,min(n,c+p[c]))[1];
            tree2.erase(i); tree1.erase(i);
            if(ds[i] == -1) {
                ds[i] = ds[c]+1;
                que.push(i);
            }
        }
    }
    // cout << "???\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

