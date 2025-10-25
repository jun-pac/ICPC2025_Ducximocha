

#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)

int datas[26];
bool DP[1<<25]; // 1 if a^b==c exists
int num_one[26];
int num_tar[26];

void Solve(int tt){
    int n;
    cin>>n;
    fill(DP,DP+(1<<n),0);
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1){
        int a=(1<<i);
        rng(j,i+1,n-1){
            int b=(1<<j);
            rng(k,j+1,n-1){
                int c=(1<<k);
                if((datas[i]^datas[j])==datas[k]){
                    DP[a+b+c]=1;
                }
            }
        }
    }
    rng(idx,0,(1<<n)-1){
        int val=0;
        int cnt=0;
        rng(k,0,n-1) if(idx&(1<<k)) cnt++;
        if(cnt<=3) continue;

        rng(k,0,n-1){
            if((idx&(1<<k)) && DP[idx-(1<<k)]) val=1;
        }
        DP[idx]=val;
        num_one[cnt]+=val;
        num_tar[cnt]+=1;
    }
    gnr(i,n-1,3){
        if(num_tar[i]!=num_one[i]){
            cout<<n-i<<'\n';
            return;
        }
    }
    cout<<n-2<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

