#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e4+5;
int l, h, n, a[MAXN], dp_max[MAXN], dp_min[MAXN], psum[MAXN];

int range(int l, int r) {
    if(l > r) return 0;
    return psum[r] - psum[l-1];
}

int main () {
    cin>>n>>l>>h;
    for(int i = 1; i <=n; i++) {
        cin>>a[i];
        psum[i] = psum[i-1] + a[i];
        dp_min[i] = 1e9;
        dp_max[i] = -1e9;
    }
    for(int i = 1; i < l; i++) {
        int cur_sum = range(1, i);
        if(cur_sum > 0) {
            dp_max[i] = dp_min[i] = 1;
        }
        else {
            dp_max[i] = dp_min[i] = 0;
        }
    }
    for(int i = l; i <= n; i++) {
        for(int j = i - h; j <= i - l; j++) {
            int cur_sum = range(j+1, i);
            if(cur_sum > 0) {
                dp_max[i] = max(dp_max[i], dp_max[j] + 1);
                dp_min[i] = min(dp_min[i], dp_min[j] + 1);
            }
            else {
                dp_max[i] = max(dp_max[i], dp_max[j]);
                dp_min[i] = min(dp_min[i], dp_min[j]);
            }
        }
    }
    int ans_max=  0, ans_min = 1e9;
    for(int i = n - l + 1; i <= n; i++) {
        int cur_sum = range(i+1, n);
        if(cur_sum > 0) {
            ans_max = max(ans_max, dp_max[i] + 1);
            ans_min = min(ans_min, dp_min[i] + 1);
        }
        else {
            ans_max = max(ans_max, dp_max[i]);
            ans_min = min(ans_min, dp_min[i]);
        }
    }
    cout << ans_min << ' ' << ans_max;
    // for(int i= 1; i <= n; i++) {
    //     cout << dp_max[i] << ' ';
    // }
    // cout << '\n';
    //     for(int i= 1; i <= n; i++) {
    //     cout << dp_min[i] << ' ';
    // }
    // cout << '\n';
}