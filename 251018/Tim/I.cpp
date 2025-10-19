#include <bits/stdc++.h>

using namespace std;

int n, s;

int main() {
   cin>>n>>s;
   for(int i= 0; i <n; i++) {
    int l, r;
    cin>>l>>r;
    if(s>=l && s<=r)s++;
   }  
   cout << s;
}