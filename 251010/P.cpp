#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+5;
string s1, s2;
vector<int> a, c, g, t;

void push(char c1, int x) {
    if(c1 == 'A') {
        a.push_back(x);
        return;
    }
    if(c1 == 'C') {
        c.push_back(x);
        return;
    }
    if(c1 == 'G') {
        g.push_back(x);
        return;
    }
    if(c1 == 'T') {
        t.push_back(x);
        return;
    }
}

void pop(char c1) {
    if(c1 == 'A') {
        a.pop_back();
        return;
    }
    if(c1 == 'C') {
        c.pop_back();
        return;
    }
    if(c1 == 'G') {
        g.pop_back();
        return;
    }
    if(c1 == 'T') {
        t.pop_back();
        return;
    }
}

int main() {
    cin>>s1>>s2;
    int n = s1.size();
    for(int i = n-1; i >=0; i--) {
        push(s1[i], i);
    }
    int ans = 0;
    for(int i= 0; i < n; i++) {
        if(s1[i] == s2[i]) {
            pop(s1[i]);
            continue;
        }
        if(s2[i] == 'A') {
            int idx_to_swap = a.back();
            cout << "swapping " << idx_to_swap << " into " << i << '\n';
            a.pop_back();
            pop(s1[i]);
            push(s1[i], idx_to_swap);
            swap(s1[i], s1[idx_to_swap]);
        }
        else if(s2[i] == 'C') {
            int idx_to_swap = c.back();
            cout << "swapping " << idx_to_swap << " into " << i << '\n';
            c.pop_back();
            pop(s1[i]);
            push(s1[i], idx_to_swap);
            swap(s1[i], s1[idx_to_swap]);
        }
        else if(s2[i] == 'G') {
            int idx_to_swap = g.back();
            cout << "swapping " << idx_to_swap << " into " << i << '\n';
            g.pop_back();
            pop(s1[i]);
            push(s1[i], idx_to_swap);
            swap(s1[i], s1[idx_to_swap]);
        }
        else if(s2[i] == 'T') {
            int idx_to_swap = t.back();
            cout << "swapping " << idx_to_swap << " into " << i << '\n';
            t.pop_back();
            pop(s1[i]);
            push(s1[i], idx_to_swap);
            swap(s1[i], s1[idx_to_swap]);
        }
        ans++;
    }
    cout << ans;
}