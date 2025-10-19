// 7z e name.zip [And enter the password]
// 7z -P password name.zip
// ./A < name.txt > output.txt

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

long long w, h, a[N];
int n;

vector<long long> comb(vector<long long> a, vector<long long> b) {
    vector<long long> ans(n,0);
    for(int i = 0; i < n; i ++) {
        ans[i] = a[i];
        if(i) ans[i] += b[i-1];
    }
    return ans;
}

vector<long long> counts(long long w, long long h) {
    vector<long long> ans(n,0);
    if(w == 0 || h == 0) return ans;
    if(w&1) {
        ans[0] += h;
    }
    if(h&1) {
        ans[0] += w;
    }
    if((w&1) && (h&1)) {
        ans[0] --;
    }
    return comb(ans, counts(w/2, h/2));
}

vector<array<long long,2>> vt[N];

void Solve(int tt){
    cin >> w >> h >> n;

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        vt[i].push_back({1,a[i]});
    }

    while(n < 51) {
        n ++;
    }

    vector<long long> ans = counts(w,h);
    long long sum = 0;
    for(int i = 0; i < n; i ++) {
        long long nd = ans[i];
        // cout << nd << " ";
        vector<array<long long,2>> lft;
        sort(vt[i].begin(),vt[i].end());
        for(auto[v,a]: vt[i]) {
            if(a >= nd) {
                sum += nd * v;
                if((a-nd) != 0) {
                    lft.push_back({v,(a-nd)});
                }
                nd = 0;
            } else if(a < nd) {
                sum += a * v;
                nd -= a;
            }
        }
        for(int z = 0; z < lft.size();) {
            if(lft[z][1] >= 4) {
                vt[i+1].push_back({lft[z][0]*4, lft[z][1]/4});
            }
            lft[z][1] %= 4;
            int j = z;
            long long sum = 0, cst = 0;
            while(j < lft.size() && sum < 4) {
                sum += lft[j][1];
                cst += lft[j][1] * lft[j][0];
                j ++;
            }
            if(sum < 4) break;
            j --;
            sum -= lft[j][1]; cst -= lft[j][1] * lft[j][0];
            int lv = (4-sum);
            vt[i+1].push_back({cst + lv * lft[j][0], 1});
            lft[j][1] -= lv;
            z = j;
        }
        if(nd) {
            cout << "-1"; return;
        }
    }
    cout << sum;

    
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

