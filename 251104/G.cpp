#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int MOD = 998244353;
const int INF = 1000000000;

typedef long long ll;

int n, m;

array<ll,2> xy[N];

inline long long dist(const array<ll,2>& a, const array<ll,2>& b = {0,0}) {
    return (b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]);
}

bool comp(int i, int j) {
    auto[x1,y1] = xy[i];
    auto[x2,y2] = xy[j];
    if(1LL*y1*x2 == 1LL*y2*x1) return dist(xy[i]) > dist(xy[j]);
    return 1LL*y1*x2 < 1LL*y2*x1;
}

inline bool CCW(const array<ll,2>& a, const array<ll,2>& b, const array<ll,2>& c) {
    auto[x1,y1] = a;
    auto[x2,y2] = b;
    auto[x3,y3] = c;

    return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]) > 0;
}

inline bool lin(const array<ll,2>& a, const array<ll,2>& b, const array<ll,2>& c) {
    auto[x1,y1] = a;
    auto[x2,y2] = b;
    auto[x3,y3] = c;

    return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]) == 0;
}

// inline long long

vector<int> hull;

void construct_convex_hull() {

    vector<int> vt;
    for(int i = 0; i < n; i ++) {
        vt.push_back(i);
    }
    sort(vt.begin(),vt.end(),comp);

    // for(int i: vt) {
    //     cout << i << ": (" << xy[i][0] << ", " << xy[i][1] << ")\n";
    // }

    vector<int> st;

    for(int i: vt) {
        if(st.size() <= 1) st.push_back(i);
        else {
            int v = 1e9;
            while(st.size() > 1) {
                int j = st.back();
                int k = st[st.size()-2];
                if(CCW(xy[k], xy[j], xy[i])) {
                    break;
                } else if(lin(xy[k], xy[j], xy[i])) {
                    v = min(v, j);
                    // lns.push_back(j);
                }
                st.pop_back();
            }
            if(v <= n) {
                st.push_back(v);
            }
            st.push_back(i);
        }
    }

    hull = st;

}

long long cost(int qx, int qy, int i) {
    return 1LL*xy[hull[i]][0] * qx + 1LL*xy[hull[i]][1] * qy;
}

void solve() {
    cin >> n >> m;

    for(int i = 0; i < n; i ++) {
        auto&[x,y] = xy[i];
        cin >> x >> y;
    }

    construct_convex_hull();

    // for(int i: hull) {
    //     cout << i << ": (" << xy[i][0] << ", " << xy[i][1] << ")\n";
    // }

    while(m--) {
        int qx, qy; cin >> qx >> qy;

        int l = 0, h = hull.size()-1;

        while(h - l >= 10) {
            int m1 = l + (h-l)/3;
            int m2 = l + (h-l)*2/3;

            if(cost(qx,qy,m1) > cost(qx,qy,m2)) {
                h = m2;
            } else {
                l = m1;
            }

        }

        long long ans = 0;
        int id;

        for(int i = max(0,l-10); i <= min((int)hull.size()-1,h+10); i ++) {
            if(ans < cost(qx,qy,i)) {
                ans = cost(qx,qy,i);
                id = hull[i];
            } else if(ans == cost(qx,qy,i)) {
                id = min(id, hull[i]);
            }
        }

        cout << id+1 << "\n";

    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}