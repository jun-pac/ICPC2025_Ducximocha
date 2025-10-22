
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

int n, v[N][3];

int bk = -1;
vector<array<int,2>> ans;

struct Cont {
    vector<int> vt;
    int ln, idx;
    bool operator<(Cont& b) {
        return this->ln < b.ln;
    }
    int size() {
        return ln;
    }
    void push_back(int v) {
        if(idx != -1) {
            ans.push_back({bk, idx});
            bk = -1;
        }
        vt.push_back(v);
        ln ++;
    }
    int pop() {
        assert(vt.size());
        int v = vt.back();
        vt.pop_back();
        bk = idx;
        ln --;
        return v;
    }
    int top() {
        return vt.back();
    }
    Cont(vector<int> vt, int ln, int idx) {
        this->vt = vt;
        this->ln = ln;
        this->idx = idx;
    }
};



void Solve(int tt){
    cin >> n;
    vector<Cont> vt;
    for(int i = 1; i <= n+1; i ++) {
        vector<int> cur;
        for(int j = 0; j < 3; j ++) {
            cin >> v[i][j];
            if(v[i][j]) cur.push_back(v[i][j]);
        }
        vt.push_back(Cont(cur, cur.size(), i));
    }
    while(vt.size() > 1) {
        sort(vt.begin(),vt.end());
        if(vt[0].size() == 2) {
            vt[2].push_back(vt[0].pop());
        } else if(vt[0].size() == 0) {
            vt[0].push_back(vt[1].pop());
        }
        int a = vt[0].top();
        if(vt[1].top() == a) {
            vt[0].push_back(vt[1].pop());
        } else if(vt[1].vt[0] == a) {
            vt[0].push_back(vt[1].pop());
            vt[0].push_back(vt[2].pop());


            vt[2].push_back(vt[1].pop());


            vt[1].push_back(vt[0].pop());
            vt[1].push_back(vt[0].pop());


            vt[0].push_back(vt[2].pop());
            vt[2].push_back(vt[1].pop());
        } else {
            for(int i = 2; i < vt.size(); i ++) {
                assert(vt[i].size() == 3);
                if(vt[i].vt[0] == a) {
                    // bottom
                    vt[0].push_back(vt[i].pop());
                    vt[0].push_back(vt[i].pop());

                    vt[1].push_back(vt[i].pop());

                    vt[i].push_back(vt[0].pop());
                    vt[i].push_back(vt[0].pop());

                    vt[0].push_back(vt[1].pop());
                    vt[i].push_back(vt[1].pop());
                } else if(vt[i].vt[1] == a) {
                    // mid
                    vt[1].push_back(vt[i].pop());
                    vt[0].push_back(vt[i].pop());
                    vt[i].push_back(vt[1].pop());
                    vt[i].push_back(vt[1].pop());
                } else if(vt[i].vt[2] == a) {
                    // top
                    vt[0].push_back(vt[i].pop());
                    vt[i].push_back(vt[1].pop());
                } else {
                    continue;
                }
                break;
            }
        }
        if(vt[1].top() == a) {
            vt[0].push_back(vt[1].pop());
        } else {
            for(int i = 2; i < vt.size(); i ++) {
                if(vt[i].vt[0] == a) {
                    // bottom
                    vt[1].push_back(vt[i].pop());
                    vt[1].push_back(vt[i].pop());
                    vt[0].push_back(vt[i].pop());
                } else if(vt[i].vt[1] == a) {
                    // middle
                    vt[1].push_back(vt[i].pop());
                    vt[0].push_back(vt[i].pop());
                } else if(vt[i].vt[2] == a) {
                    // top
                    vt[0].push_back(vt[i].pop());
                } else {
                    continue;
                }
                break;
            }
        }
        reverse(vt.begin(),vt.end());
        vt.pop_back();
    }
    cout << ans.size() << "\n";
    for(auto[a,b]: ans) {
        cout << a << " " << b << "\n";
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

