#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int len = 1<<19;

// assuming decreasing M / Increasing X

struct CHT {
    struct Line {
        ll m, c;
        ll eval(ll x) { return m * x + c; }
    };

    vector<Line> hull;
    int ptr = 0;

    bool bad(Line l1, Line l2, Line l3) {
        return (__int128)(l2.c - l1.c) * (l3.m - l2.m) <= (__int128)(l3.c - l2.c) * (l2.m - l1.m);
    }

    void addLine(ll m, ll c) {
        Line L = {m, c};
        if (!hull.empty() && hull.back().m == L.m) {
            if (hull.back().c >= L.c) return;
            hull.pop_back();
        }
        while (hull.size() >= 2 && bad(hull[hull.size()-2], hull.back(), L)) {
            hull.pop_back();
        }
        hull.pb(L);
    }

    ll query(ll x) {

        // can change to binary search here to avoid condition of increasing X.

        while (ptr + 1 < (int)hull.size() && hull[ptr + 1].eval(x) >= hull[ptr].eval(x)) {
            ptr++;
        }
        return hull[ptr].eval(x);
    }
};