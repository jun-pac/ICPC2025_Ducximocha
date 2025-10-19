#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin>>n;
    int l = 0, r = 5e5;
    for(int  i =0; i < n; i++) {
        int x, y;
        cin>>x>>y;
        l = max(l, x);
        r = min(r, y);
    }
    if(l > r) {
        cout << "bad news";
        return 0;
    }
    cout << r - l + 1 << ' ';
    cout << l << '\n';
}