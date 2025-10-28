#include <bits/stdc++.h>

using namespace std;

int t, w, l;

signed main() {
    cin>>t;
    while(t--) {
        cin>>w>>l;
        set<int> ans;
        if((w+l)%2 == 1) {
            ans.insert(2);
        }
        //case top is full mutliple
        int bound = sqrt(l);
        int cw = w-2, cl = l;
        for(int i=  1; i <= bound; i++) {
            if(cl % i ==0) {
                if(cw % i == 0) {
                    ans.insert(i);
                }
                if(cw%(cl/i) == 0) {
                    ans.insert(cl/i);
                }
            }
        }
        //case top is mod 1
        bound = sqrt(l-1);
        cw = w -1, cl = l-1;
        for(int i=  1; i <= bound; i++) {
            if(cl % i ==0) {
                if(cw % i == 0) {
                    ans.insert(i);
                }
                if(cw%(cl/i) == 0) {
                    ans.insert(cl/i);
                }
            }
        }
        bound = sqrt(l-2);
        cw = w, cl = l-2;
        for(int i=  1; i <= bound; i++) {
            if(cl % i ==0) {
                if(cw % i == 0) {
                    ans.insert(i);
                }
                if(cw%(cl/i) == 0) {
                    ans.insert(cl/i);
                }
            }
        }
        cout << ans.size() << ' ';
        for(int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}