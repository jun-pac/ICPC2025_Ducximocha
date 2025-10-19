#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    cin.tie(NULL)->sync_with_stdio(0);
    cin>>t;
    while(t--) {
        int n;cin>>n;
        bool is_odd = n%2;
        bool is_square = (int) sqrt(n) * (int) sqrt(n) == n;
        if(!is_odd && !is_square) {
            cout << "EMPTY\n";
            continue;
        }
        if(is_odd) {
            cout << "O";
        }
        if(is_square) {
            cout << "S";
        }
        cout << '\n';
    }
}