#include <bits/stdc++.h>
using namespace std;
int n, x[200005], sg[200005], mxv[200005], mnv[200005];
set<int> st;
multiset<int> st2;
bool exists(int l, int r) {
    auto it = st2.lower_bound(l);
    return it != st2.end() && (*it) <= r;
}
int len = 1<<18;
int tree[1<<19], tree2[1<<19];
void update(int a, int v) {
    tree[a+len] = v;
    tree2[a+len] = v;
    for(a = (a+len)>>1; a >= 1; a >>= 1) {
        tree[a] = max(tree[a*2], tree[a*2+1]);
        tree2[a] = min(tree2[a*2], tree2[a*2+1]);
    }
}
array<int,2> query(int l, int r) {
    int v1 = 0, v2 = 1e9;
    for(l += len, r += len; l <= r; l >>= 1, r >>= 1) {
        if(l&1) {
            v1 = max(v1, tree[l]);
            v2 = min(v2, tree2[l++]);
        }
        if(~r&1) {
            v1 = max(v1, tree[r]);
            v2 = min(v2, tree[r--]);
        }
    }
    return {v1,v2};
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> x[i];
        st2.insert(x[i]);
    }
    mxv[n] = mnv[n] = x[n];
    for(int i = n-1; i >= 1; i --) {
        mxv[i] = max(mxv[i+1], x[i]);
        mnv[i] = min(mnv[i+1], x[i]);
    }
    
    vector<string> ans;
    for(int i = 1; i < n; i ++) {
        st2.erase(st2.lower_bound(x[i]));
        if(st.empty()) {
            st.insert(x[i]);
            continue;
        }
        if(st.count(x[i])) {
            if(mxv[i+1] > x[i]) {
                ans.push_back("112");
            }
            if(mnv[i+1] < x[i]) {
                ans.push_back("221");
            }
            if(st2.count(x[i])) {
                ans.push_back("111");
            }
        }
        if((*st.begin()) < x[i]) {
            int v = *(prev(st.lower_bound(x[i])));
            if(exists(0,v-1)) {
                ans.push_back("231");
            }
            v = *st.begin();
            if(exists(v+1,x[i]-1)) {
                ans.push_back("132");
            }
            if(exists(x[i],x[i])) {
                ans.push_back("122");
            }
            if(exists(x[i]+1,1e9)) {
                ans.push_back("123");
            }
        }

        if((*st.rbegin()) > x[i]) {
            int v = *st.upper_bound(x[i]);
            if(exists(v+1,1e9)) {
                ans.push_back("213");
            }
            v = *st.rbegin();
            if(exists(x[i]+1,v-1)) {
                ans.push_back("312");
            }
            if(exists(x[i],x[i])) {
                ans.push_back("211");
            }
            if(exists(0,x[i]-1)) {
                ans.push_back("321");
            }
        }
        st.insert(x[i]);
    }
    map<int,int> mp;
    map<int,int> cnt;
    st2.clear();
    for(int i = 1; i <= n; i ++) {
        mp[x[i]] = (i);
        cnt[x[i]] ++;
        update(i, x[i]);
    }
    for(auto[a,b]: cnt) {
        if(b >= 3) ans.push_back("111");
    }
    set<array<int,2>> st3;
    int r = 1;
    for(int i = 1; i <= n; i ++) {
        if(mp[x[i]] == i) continue;
        int l = i+1, r = mp[x[i]] -1;
        if(l <= r) {
            if(query(l,r)[0] > x[i]) {
                ans.push_back("121");
            }
            if(query(l,r)[1] < x[i]) {
                ans.push_back("212");
            }
        }


    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(auto i: ans) {
        cout << i << "\n";
    }
}