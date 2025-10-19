// 7z e name.zip [And enter the password]
// 7z -P password name.zip
// ./A < name.txt > output.txt

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define pb push_back
#define all(x) x.bg,x.ed
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 500030
#define MOD 998244353
#define INF 1000000007 

int n, m, ds[10][10][10][10][1<<4];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
string g[N];

bool basicCanMove(int x, int y, int mv) {
    int nx = x+dx[mv], ny = y+dy[mv];

    if(min(nx,ny) < 0 || min(n-nx, m-ny) <= 0) return false;
    if(g[nx][ny] == '*') return false;

    return true;
}

int toggle(int x, int y, int nx, int ny, int sst) {
    int nsst = sst;

    if(x != nx || y != ny) {
        if('1' <= g[nx][ny] && g[nx][ny] <= '4') {
            nsst ^= 1<<(g[nx][ny] - '1');
        }
    }

    return nsst;
}

bool isBlocked(int x, int y, int st) {
    if(g[x][y] == '#') return 1;
    if('a' <= g[x][y] && g[x][y] <= 'd') {
        return (st & (1<<g[x][y] - 'a')) != 0;
    } else if('A' <= g[x][y] && g[x][y] <= 'D') {
        return (st & (1<<g[x][y] - 'a')) == 0;
    }
    return 0;
}

// bool obstacleWorks

void Solve(int tt){
    
    cin >> n >> m;
    vector<array<int,2>> vt;
    for(int i = 0; i < n; i ++) {
        cin >> g[i];
        for(int j = 0; j < m; j ++) {
            if(g[i][j] == 'S') {
                g[i][j] = '.';
                vt.push_back({i,j});
            }
        }
    }

    queue<array<int,5>> que;
    que.push({vt[0][0],vt[0][1],vt[1][0],vt[1][1],0});
    ds[vt[0][0]][vt[0][1]][vt[1][0]][vt[1][1]][0] = 1;

    while(que.size()) {
        auto[x1,y1,x2,y2,sst] = que.front(); que.pop();
        int d = ds[x1][y1][x2][y2][sst];

        if(g[x1][y1] == 'E' && g[x2][y2] == 'E') {
            cout << d-1; return;
        }

        for(int mv = 0; mv < 4; mv ++) {
            if(!basicCanMove(x1,y1,mv) || !basicCanMove(x2,y2,mv)) continue;
            int nx1 = x1+dx[mv], ny1 = y1+dy[mv];
            int nx2 = x2+dx[mv], ny2 = y2+dy[mv];
            
            if(isBlocked(nx1,ny1,sst)) {
                nx1 = x1; ny1 = y1;
            }
            if(isBlocked(nx2,ny2,sst)) {
                nx2 = x2; ny2 = y2;
            }

            if(nx1 == nx2 && ny1 == ny2) continue;

            int nsst = toggle(x2,y2,nx2,ny2,toggle(x1,y1,nx1,ny1,sst));
            
            if(isBlocked(nx1,ny1,nsst) || isBlocked(nx2,ny2,nsst)) {
                continue;
            }

            if(ds[nx1][ny1][nx2][ny2][nsst] == 0) {
                ds[nx1][ny1][nx2][ny2][nsst] = d + 1;
                que.push({nx1,ny1,nx2,ny2,nsst});
            }

        }
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

