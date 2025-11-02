

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

string a, b;
bool vs[1679616];

string toString(int n) {
    string r = "";
    for(int z = 0; z < 8; z ++) {
        r += (char)(n%6+'A');
        n /= 6;
    }
    reverse(r.begin(),r.end());
    return r;
}

int toInt(string s) {
    int r = 0;
    for(char i: s) {
        r = r*6+i-'A';
    }
    return r;
}

char rotate(char v) {
    return (v-'A'+1)%6+'A';
}

void Solve(int tt){
    cin >> a >> b;
    vs[toInt(a)] = 1;
    queue<pair<int, int>> que;
    que.push({toInt(a),0});
    vs[toInt(a)] = 1;
    while(que.size()) {
        auto[cc,d] = que.front(); que.pop();
        // cout << c << " " << d << "\n";
        string c = toString(cc);
        // cout << c << "\n";
        // return ;
        if(c == b) {
            cout << d; return;
        }
        for(int i = 0; i < 8; i ++) {
            string nc = c;
            if(c[i] == 'A') {
                if(i) nc[i-1] = rotate(nc[i-1]);
                if(i + 1 < 8) {
                    nc[i+1] = (nc[i+1] + 1 - 'A') % 6 + 'A';
                }
            } else if(c[i] == 'B') {
                if(i && i+1 < 8) {
                    nc[i+1] = nc[i-1];
                }
            } else if(c[i] == 'C') {
                nc[7-i] = rotate(nc[7-i]);
            } else if(c[i] == 'D') {
                if(i <= 3) {
                    for(int j = 0; j < i; j ++) {
                        nc[j] = rotate(nc[j]);
                    }
                } else {
                    for(int j = i+1; j < 8; j ++) {
                        nc[j] = rotate(nc[j]);
                    }
                }
            } else if(c[i] == 'E') {
                if(i && i+1 < 8) {
                    int y = min(i, 7-i);
                    nc[i-y] = rotate(nc[i-y]);
                    nc[i+y] = rotate(nc[i+y]);
                }
            } else {
                if((i+1)%2) {
                    nc[(i+10)/2-1] = rotate(nc[(i+10)/2-1]);
                } else {
                    nc[(i+1)/2-1] = rotate(nc[(i+1)/2-1]);
                }
            }
            int ncc = toInt(nc);
            if(vs[ncc]) {
                continue;
            }
            vs[ncc] = 1;
            que.push({ncc,d+1});
        }
    }
    cout << "-1";
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

