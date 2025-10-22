

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

array<ll,3> datas[N]; // x,y,idx
ll value[N];

int left_idx[N], right_idx[N];
ll x;
bool compare_left(array<ll,3> a, array<ll,3> b){
    return b[0]*a[1]-b[1]*a[0]>0;
}

bool compare_right(array<ll,3> a, array<ll,3> b){
    return (b[0]-x)*a[1]-b[1]*(a[0]-x)<0;
}


class segtree{
public:	
	ll seg[1<<19];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=0;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]=val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	long long find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		long long mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

void Solve(int tt){
    ll n;
    cin>>n>>x;
    rng(i,0,n-1){
        cin>>datas[i][0]>>datas[i][1];
        datas[i][2]=i;
        cin>>value[i];
    }
    sort(datas,datas+n,compare_left);
    rng(i,0,n-1) left_idx[i]=datas[i][2];
    sort(datas,datas+n,compare_right);
    rng(i,0,n-1) right_idx[i]=datas[i][2];

    vector<int> ls(n), rs(n);

    for(int i = 0; i < n; i ++) {
        ls[left_idx[i]] = i;
        // cout << left_idx[i] <<  " ";
    }
    // cout << "\n";
    
    for(int i = 0; i < n; i ++) {
        rs[right_idx[i]] = i;
        // cout << right_idx[i] <<  " ";
    }
    // cout << "\n";
    
    vector<array<int,3>> vt;

    for(int i = 0; i < n; i ++) {
        vt.push_back({-ls[i], rs[i], i});
    }

    sort(vt.begin(),vt.end());
    seg.build_seg(1, 0, n+1);
    vector<long long> ans(n);
    for(auto[a,b,i]: vt) {
        ans[i] = seg.find_seg(1, 0, n+1, b, n);
        seg.update_seg(1, 0, n+1, b, value[i]);
    }

    for(auto i: ans) {
        cout << i << "\n";
    }

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

