

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

#define N 1000030
#define MOD 998244353
#define INF 1000000007 

typedef complex<double> cpx;
const int SZ = 1048576;


void FFT(cpx g[], bool inv = false){
    int n = SZ;
    for(int i = 1, j = 0; i < n; ++i){
        // j : bitwise reverse of i (10110 -> 01101)
        int b = n/2;
        while(!((j ^= b) & b)) b /= 2; // find left-most 1 bit of j, then reverse all the visited bit.
        // 1110xx -> 0001xx
        if(i < j) swap(g[i], g[j]);
    }
    for(int k = 1; k < n; k *= 2){
        double a = (inv ? M_PI/k : -M_PI/k);
        cpx w(cos(a), sin(a));
        for(int i = 0; i < n; i += k*2){
            cpx wp(1, 0);
            for(int j = 0; j < k; ++j){
                cpx x = g[i+j], y = g[i+j+k] * wp;
                g[i+j] = x + y;
                g[i+j+k] = x - y;
                wp *= w;
            }
        }
    }
    if(inv){
        for(int i = 0; i < n; ++i)
            g[i] /= n;
    }
}

int n, p[N], sz[N];

vector<int> adj[N];
void DFS(int c) {
    sz[c] = 1;
    for(int i: adj[c]) {
        DFS(i);
        sz[c] += sz[i];
    }
}

long long DFS2(int c, int dpt) {
    long long sum = dpt;
    for(int i: adj[c]) {
        sum += DFS2(i, dpt+1);
    }
    return sum;
}

void Solve(int tt){

    cin >> n;
    for(int i = 2, p; i <= n; i ++) {
        cin >> p;
        adj[p].push_back(i);
    }
    DFS(1);
    for(int i = 1; i <= n; i ++) {
        if(sz[i]*2 == n) {
            cout << n + 1LL*n*n/4;
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

