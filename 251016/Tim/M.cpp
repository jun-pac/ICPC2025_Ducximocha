#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+5;
int n, h;

struct request {
    int u, v;
};
vector<request> prele, preri, le, ri;

bool cmpl(request a, request b) {return a.u < b.u;}
bool cmpr(request a, request b) {return a.u>b.u;}

int main() {
    cin>>n>>h;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin>>x>>y;
        if(x<y) preri.push_back({x, y});
        else prele.push_back({y, x});
    }
    sort(preri.begin(), preri.end(), cmpl);
    sort(prele.begin(), prele.end(), cmpr);
    int maxr = 0;
    for(int i = 0; i < n; i++) {
        if(preri[i].v > maxr) {
            ri.push_back(preri[i]);
            maxr = preri[i].v;
        }
    }
    for(int i = 0; i < n; i++) 
}