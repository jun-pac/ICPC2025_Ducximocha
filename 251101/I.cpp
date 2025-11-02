

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

int n, x[N], y[N];

using ld = long double;

struct Poly {
    vector<ld> coef;

    Poly() {
        coef = vector<ld>(1,0);
    }
    Poly(vector<ld> vt) {
        coef = vt;
    }

    Poly operator*(Poly other) {
        vector<ld> a = coef;
        vector<ld> b = other.coef;

        vector<ld> c = vector<ld>(a.size()+b.size()-1, 0);

        for(int i = 0; i < a.size(); i ++) {
            for(int j = 0; j < b.size(); j ++) {
                c[i+j] += a[i] * b[j];
            }
        }

        return Poly(c);
    }

    Poly operator+(Poly other) {
        vector<ld> a = coef;
        vector<ld> b = other.coef;

        if(a.size() < b.size()) swap(a,b);
        while(b.size() < a.size()) b.push_back(0);
        for(int i = 0; i < a.size(); i ++) {
            a[i] += b[i];
        }

        return Poly(a);
    }

    Poly operator-(Poly other) {
        vector<ld> a = coef;
        vector<ld> b = other.coef;

        while(a.size() < b.size()) a.push_back(0);
        while(b.size() < a.size()) b.push_back(0);
        for(int i = 0; i < a.size(); i ++) {
            a[i] -= b[i];
        }

        return Poly(a);
    }

    void integrate() {
        coef.insert(coef.begin(),0);
        for(int i = 1; i< coef.size(); i ++) {
            coef[i] /= i;
        }
    }

    ld get(ld x) {
        ld sum = 0;
        for(int i = 0; i < coef.size(); i ++) {
            sum += powl(x,i) * coef[i];
        }
        return sum;
    }

};

ld getSum() {
    deque<array<int,2>> dq;

    for(int i = 0; i < n; i ++) {
        dq.push_back({x[i], y[i]});
    }

    array<int,2> mn = dq[0], mx = dq[0];
    // int mn = x[0], mx = x[0];
    for(int i = 1; i < n; i ++) {
        mn = min(mn, dq[i]);
        mx = max(mx, dq[i]);
    }

    vector<array<int,2>> up, lw;
    bool c = 0;
    for(int i = 0;; i = (i+1) % n) {
        if(mn == dq[i]) c = 1;
        if(c) {
            up.push_back(dq[i]);
        }
        if(c && mx == dq[i]) break;
    }

    c = 0;
    for(int i = 0;; i = (i+1) % n) {
        if(mx == dq[i]) c = 1;
        if(c) {
            lw.push_back(dq[i]);
        }
        if(c && mn == dq[i]) break;
    }

    reverse(lw.begin(),lw.end());

    vector<array<ld,6>> vt;
    vt.push_back({0,0,0,0,0,0});

    // for(auto[x,y]: lw) {
    //     cout << x << " " << y << "\n";
    // }
    // cout << "\n";


    // for(auto[x,y]: up) {
    //     cout << x << " " << y << "\n";
    // }
    // cout << "\n";
    

    for(int i = 1, j = 1; i < lw.size() && j < up.size(); ) {
        int x1 = max(lw[i-1][0], up[j-1][0]), x2 = min(lw[i][0], up[j][0]);

        
        if(x1 == x2) {
            if(lw[i][0] < up[j][0]) {
                i ++;
            } else if(lw[i][0] > up[j][0]) {
                j ++;
            } else {
                i ++;
                j ++;
            }
            continue;
        }
        // cout << x1 << " " << x2 << "\n";

        ld y1 = lw[i-1][1] + (long double)(x1 - lw[i-1][0]) * (lw[i][1] - lw[i-1][1]) / (lw[i][0] - lw[i-1][0]);
        ld y2 = lw[i-1][1] + (long double)(x2 - lw[i-1][0]) * (lw[i][1] - lw[i-1][1]) / (lw[i][0] - lw[i-1][0]);

        ld yp1 = up[j-1][1] + (long double)(x1 - up[j-1][0]) * (up[j][1] - up[j-1][1]) / (up[j][0] - up[j-1][0]);
        ld yp2 = up[j-1][1] + (long double)(x2 - up[j-1][0]) * (up[j][1] - up[j-1][1]) / (up[j][0] - up[j-1][0]);

        ld h1 = yp1-y1;
        ld h2 = yp2-y2;
        // cout << (long double)(x2 - up[i-1][0])  << " " << (up[i][1] - up[i-1][1]) << " " <<  (up[i][0] - up[i-1][0]) << "\n";

        // cout << y1 << " " << y2 << " " << yp1 << " " << yp2 << "\n";

        
        ld area = (x2 - x1) * (h1 + h2) / 2;
        // cout << h1 << " " << h2 << " " << area << "\n";

        vt.push_back({(ld)x1,(ld)x2,h1,h2,area,area + vt.back()[5]});

        if(lw[i][0] < up[j][0]) {
            i ++;
        } else if(lw[i][0] > up[j][0]) {
            j ++;
        } else {
            i ++;
            j ++;
        }

    }

    int id = 0;

    ld sum = 0;

    for(auto[x1,x2,h1,h2,area,areas]: vt) {
        // cout << area << " ";
        if(id) {
            ld left_area = vt[id-1][5];
            ld right_area = vt.back()[5] - areas;


            Poly hx({h1 - (h2-h1) / (x2-x1) * x1, (h2-h1) / (x2-x1)});
            Poly alx = Poly({left_area}) +  Poly({0.5}) * (Poly({h1}) + hx) * Poly({-x1, 1});
            Poly arx = Poly({right_area}) + Poly({0.5}) * (Poly({h2}) + hx) * Poly({x2, -1});
            
            Poly fin = Poly({0,1}) * (alx - arx) * hx;

            fin.integrate();

            sum += fin.get(x2) - fin.get(x1);
        }

        id ++;
    }

    // cout << vt.back()[5] << "\n";

    sum = sum * 2 / vt.back()[5] / vt.back()[5];

    return sum;
}

void Solve(int tt){
    cin >> n;
    
    for(int i = 0; i < n; i ++) {
        cin >> x[i] >> y[i];
    }
    
    ld ans =  0;
    ans = getSum();

    for(int i = 0; i < n; i ++) {
        y[i] = -y[i];
        swap(x[i], y[i]);
    }

    ans += getSum();

    cout << setprecision(15) << fixed << ans;


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

