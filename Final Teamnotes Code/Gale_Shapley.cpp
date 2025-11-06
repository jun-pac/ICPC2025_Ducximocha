#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=a; i<=b; i++)
#define gnr(i,a,b) for(int i=a; i>=b; i--)
#define N 1010

// O(N^3) algorithm
int A_pref[N][N], B_pref[N][N]; // Suppose u\in A and v\in B. A[u][v]: u's preference score for v (the higher the better). B[v][u]: v's preference score for u. 
int A_order[N][N]; // A_order[u][i]: i-th prefered element from B for u. (So prefered element idx first)
bool attempted[N][N]; // attempted[u][v]: Indicates whether the u attempted v previously
int A_match[N], B_match[N]; // current match. Initialize to -1

void Gale_Shapley(int n){
    // return: match idx in A_match and B_match
    fill(A_match,A_match+n,-1);
    fill(B_match,B_match+n,-1);
    rng(i,0,n-1) fill(attempted[i],attempted[i]+n,0);
    queue<int> unmatched_A; 
    
    rng(i,0,n-1) unmatched_A.push(i);
    while(!unmatched_A.empty()){
        int u=unmatched_A.front();
        unmatched_A.pop();
        rng(i,0,n-1){
            int v=A_order[u][i];
            if(attempted[u][v]) continue;
            if(B_match[v]==-1){
                A_match[u]=v;
                B_match[v]=u;
                break;
            }
            else if(B_pref[v][B_match[v]] < B_pref[v][u]){ // u is prefered over previous match
                unmatched_A.push(B_match[v]);
                A_match[u]=v;
                B_match[v]=u;
                break;
            }
        }
    }
}
