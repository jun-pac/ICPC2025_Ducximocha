#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int n, m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
string g[N], s;
vector<int> r;

int dp[51][51][51], ds[50][50];

void relax(int k) {
    priority_queue<array<int,3>> pq;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j< m; j ++) {
            ds[i][j] = dp[k][i][j];
            pq.push({-ds[i][j], i, j});
        }
    }
    while(pq.size()) {
        auto[d,x,y] = pq.top(); pq.pop();
        if((d=-d) != ds[x][y]) continue;
        for(int z = 0; z < 4; z ++) {
            int nx = x + dx[z];
            int ny = y + dy[z];

            if(min(nx,ny) < 0 || min(n-nx, m-ny) < 1) continue;
            if(g[nx][ny] == '#') continue;
            if(ds[nx][ny] > d+1) {
                ds[nx][ny] = d+1;
                pq.push({-d-1,nx,ny});
            }

        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            dp[k][i][j] = ds[i][j];
        }
    }
}

void solve() {
    cin >> n >> m;
    int sx, sy, ex, ey;
    for(int i = 0; i< n; i ++) {
        cin >> g[i];
        for(int j = 0; j< m; j ++) {
            if(g[i][j] == 'S') {
                sx = i; sy = j;
                g[i][j] = '.';
            }
            if(g[i][j] == 'G') {
                ex = i; ey = j;
                g[i][j] = '.';
            }
        }
    }
    cin >> s;
    for(char i: s) {
        if(i == 'R') {
            r.push_back(0);
        } else if(i == 'L') {
            r.push_back(1);
        } else if(i == 'D') {
            r.push_back(2);
        } else {
            r.push_back(3);
        }
    }
    for(auto&i: dp) for(auto&j: i) for(auto&k: j) k = 1e9;

    dp[0][sx][sy] = 0;
    int ans = 1e9;
    for(int k = 0; k < s.size(); k ++) {
        relax(k);
        // for()
        ans = min(ans, dp[k][ex][ey]);
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j++) {
                // cout << dp[k][i][j] << " ";
                int ni = i + dx[r[k]];
                int nj = j + dy[r[k]];

                if(min(ni,nj) < 0 || min(n-ni,m-nj) < 1 || g[ni][nj] == '#') {
                    ni = i;
                    nj = j;
                }

                dp[k+1][ni][nj] = min(dp[k+1][ni][nj], dp[k][i][j]);
                dp[k+1][i][j] = min(dp[k+1][i][j], dp[k][i][j] + 1);
            }
            // cout << "\n";
        }
        // cout << "\n";
    }
    relax(s.size());
    ans = min(ans, dp[s.size()][ex][ey]);
    cout << ans;

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}