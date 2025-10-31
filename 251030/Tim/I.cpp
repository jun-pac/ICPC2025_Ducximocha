#include <bits/stdc++.h>

using namespace std;

string s, p;

int main() {
    cin>>s>>p;
    if(s==p) {
        cout << "Yes";
        return 0;
    }
    swap(s,p);
    for(char a = '0'; a <= '9'; a ++) {

        // cout << a + s << "\n";
        if(a + s == p) {
            cout << "Yes"; return 0;
        }
        if(s + a == p) {
            cout << "Yes"; return 0;
        }
    }

    for(char&i: s) {
        if('a' <= i && i <= 'z') {
            i = i-'a'+'A';
        } else if('A' <= i && i <= 'Z') {
            i = i-'A'+'a';
        }
    }

    if(s == p) {
        cout << "Yes"; return 0;
    }

    cout << "No"; return 0;


}