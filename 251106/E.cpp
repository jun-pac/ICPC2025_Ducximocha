#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

typedef long double ld;

const ld PI = acosl(0)*2;
const ld ep = 1e-10;

array<array<ld,2>,4> getTheta(ld x1, ld y1, ld x2, ld y2, ld l1, ld l2) {

    bool sw = 0;

    if(x1 > x2) {
        swap(x1,x2);
        swap(y1,y2);
        sw = 1;
    } else if(abs(x1-x2) < ep && y1 > y2) {
        swap(x1,x2);
        swap(y1,y2);
        sw =1;
    }

    ld l0 = sqrtl(powl(x1-x2,2)+powl(y1-y2,2));
    ld theta1 = acosl((l0 * l0 + l1 * l1 - l2*l2)/(2 * l0 * l1));
    ld theta2 = acosl((l0 * l0 + l2 * l2 - l1 *l1)/(2 * l0 * l2));

    ld theta;

    if(abs(x1-x2) < ep) {
        theta = PI/2;
    }  else {
        theta = atanl((y1-y2) / (x1-x2));
    }

    array<ld,2> a, b, c, d;

    a = {cosl(theta + theta1), sinl(theta + theta1)};
    b = {-cosl(theta + theta1), -sinl(theta + theta1)};
    
    c = {cosl(theta - theta1), sinl(theta - theta1)};
    d = {-cosl(theta - theta1), -sinl(theta - theta1)};
    
    a[0] *= l1;
    a[1] *= l1;

    b[0] *= l1;
    b[1] *= l1;

    c[0] *= l1;
    c[1] *= l1;

    d[0] *= l1;
    d[1] *= l1;

    a[0] += x1;
    a[1] += y1;

    b[0] += x2;
    b[1] += y2;

    c[0] += x1;
    c[1] += y1;

    d[0] += x2;
    d[1] += y2;

    if(sw) {
        swap(a,b);
        swap(c,d);
    }

    return {a, b, c, d};
}

int n, l[N];

ld ans;

void recurse(vector<bool>&usd, ld x1, ld y1, ld x2, ld y2) {
    if(min(x1,x2) < 0) return;
    for(int i = 0; i < n; i ++) {
        if(usd[i]) continue;
        for(int j = i+1; j < n; j ++) {
            if(usd[j]) continue;
                if(max({(ld)l[i],(ld)l[j],sqrtl(powl(x1-x2,2) +powl(y1-y2,2))})*2 >= (ld)l[i]+(ld)l[j]+sqrtl(powl(x1-x2,2) +powl(y1-y2,2))) {
                    continue;
                }
                auto[a,b,c,d] = getTheta(x1,y1,x2,y2,l[i],l[j]);
                
                // vector<array<ld,2>> vt = {A,b,c,d};
                ans = max({ans, a[0], b[0], c[0], d[0]});
                
                usd[i] = 1; usd[j] = 1;
                if(max(a[0],x1) > max(b[0],x2)) {
                    recurse(usd, x1,y1,a[0],a[1]);
                } else {
                    recurse(usd,x2,y2,b[0],b[1]);
                }
                if(max(a[0],x2) > max(b[0],x1)) {
                    recurse(usd, x2,y2, a[0], a[1]);
                } else {
                    recurse(usd, x1,y1, b[0], b[1]);
                }

                if(max(c[0],x1) > max(d[0],x2)) {
                    recurse(usd, x1,y1,c[0],c[1]);
                } else {
                    recurse(usd,x2,y2,d[0],d[1]);
                }
                if(max(c[0],x2) > max(d[0],x1)) {
                    recurse(usd, x2,y2, c[0], c[1]);
                } else {
                    recurse(usd, x1,y1, d[0], d[1]);
                }
                
                usd[i] = 0; usd[j] = 0;
        }
    }
}

void solve() {

    // auto[a,b,c,d] = getTheta(0, 0, -4, 3, 3, 4);

    // cout << "(" << a[0] << ", " << a[1] << ")\n";
    // cout << "(" << b[0] << ", " << b[1] << ")\n";
    // cout << "(" << c[0] << ", " << c[1] << ")\n";
    // cout << "(" << d[0] << ", " << d[1] << ")\n";

    cin >> n;
    for(int i = 0; i< n; i++) {
        cin >> l[i];
    }
    ans = 0;
    for(int i = 0; i < n; i ++) {
        vector<bool> usd(n,0);
        vector<array<ld,4>> seg = {{0,0,0,l[i]}};
        usd[i] = 1;
        recurse(usd,0,0,0,l[i]);
    }
    cout << setprecision(15) << fixed << ans;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}