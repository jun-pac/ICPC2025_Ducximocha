#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int ccw(pll A, pll B, pll C){
    return (C.second-A.second)*(B.first-A.first) > (B.second-A.second)*(C.first-A.first);
}

// Line AB and CD
// ONLY USE WHEN ABCD are guaranteed not ro be collinear
bool intersect(pll A, pll B, pll C, pll D){
    return (ccw(A,C,D) != ccw(B,C,D)) && (ccw(A,B,C) != ccw(A,B,D));
}

// Example
#define fi first
#define se second
int main(){
    pll a,b,c,d;
    cin>>a.fi>>a.se;
    cin>>b.fi>>b.se;
    cin>>c.fi>>c.se;
    cin>>d.fi>>d.se;
    cout<<intersect(a,b,c,d)<<'\n';
}