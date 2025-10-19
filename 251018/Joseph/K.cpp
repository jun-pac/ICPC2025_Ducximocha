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


class node{
public:
    // Do something!
    node(){}
    //node(int val){this->val=val;}
    node operator+(node b){
        node result;
        result.val=max(val,b.val); // Modify
        return result;
    }
    int val=0, lazy_val=0;
};

class lazy_seg{
public:
    vector<node> seg;
	
	lazy_seg(){}
	//lazy_seg(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
            if(seg.size() < idx) {
                while(seg.size() < idx) seg.push_back(node());
            }
			seg[idx].val=0; // seg[idx].val=datas[l];
			seg[idx].lazy_val=0;
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=(seg[2*idx]+seg[2*idx+1]);
		}
	}
	
	void update_down(int idx, int l, int r){
		if(l==r) return;
		int mid=(l+r)>>1;

		// // seg[2*idx], seg[2*idx+1]
		seg[2*idx].val+=seg[idx].lazy_val;
		seg[2*idx].lazy_val+=seg[idx].lazy_val;
		seg[2*idx+1].val+=seg[idx].lazy_val;
		seg[2*idx+1].lazy_val+=seg[idx].lazy_val;
		// seg[idx]�� lazy_val�ʱ�ȭ
		seg[idx].lazy_val=0;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			// // seg[idx].val�� seg[idx].lazy_val������Ʈ
			seg[idx].val+=val;
			seg[idx].lazy_val+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]);
	}
	
	node find_seg(int idx, int l, int r, int t_l, int t_r){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
		node result;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=(result+find_seg(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) result=(result+find_seg(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}
} tree;


int r, c, d, n;

void Solve(int tt){
    cin >> r >> c >> d >> n;
    vector<array<int,3>> vt;
    int cur = 0;
    priority_queue<int> pq2, pq3;
    for(int z=0; z<n; z ++) {
        int i, j; cin >> i >> j;
        if(i-1) vt.push_back({i-1,0,-1});
        if(i+1<=r) vt.push_back({i+1,0,-1});
        vt.push_back({i,-j,j});
        if(i-d-1 >= 1) {
            cur ++;
            pq2.push(d-i);
        }
        if(i+d+1 <= r) {
            pq3.push(-(i+d+1));
        }
        for(int ni = max(1,i-d); ni <= min(r,i+d); ni ++) {
            int l = sqrtl(d*d-(i-ni)*(i-ni));
            int L = max(1,j-l), R = min(c,j+l);
            if(L != 1) vt.push_back({ni,1,L-1});
            if(R != c) vt.push_back({ni,R+1,c});
        }
    }

    priority_queue<array<int,3>> pq;

    sort(vt.begin(),vt.end());
    int ans = n;
    for(int i = 0; i < vt.size();) {
        int j = i;
        vector<int> cc;
        vector<array<int,3>> rg;
        while(pq2.size() && -pq2.top() <= vt[i][0]) {
            cur --;
            pq2.pop();
        }
        while(pq3.size() && -pq3.top() <= vt[i][0]) {
            cur ++;
            pq3.pop();
        }
        while(j < vt.size() && vt[j][0] == vt[i][0]) {
            auto[_,l,r] = vt[j];
            if(l < 0) {
                rg.push_back({-l,r,-10000});
            } else if(r < 0) {
            } else {
                rg.push_back({l,r,1});
            }
            j ++;
        }
        // cout << cur << " ";
        for(auto[l,r,v]: rg) {
            // cout << "(" << l << ", " << r << ", " << v << ") ";
            cc.push_back(l);
            cc.push_back(r);
        }
        // cout << "\n";
        sort(cc.begin(),cc.end());
        cc.erase(unique(cc.begin(),cc.end()),cc.end());
        tree.build_seg(1,0,cc.size());
        for(auto[l,r,v]: rg) {
            l = lower_bound(cc.begin(),cc.end(),l)-cc.begin();
            r = lower_bound(cc.begin(),cc.end(),r)-cc.begin();
            tree.update_seg(1,0,cc.size(),l,r,v);
        }
        // cout <<  n-tree.find_seg(1,0,cc.size(),0,cc.size()).val-cur << "\n";
        ans = min(ans, n-tree.find_seg(1,0,cc.size(),0,cc.size()).val-cur);
        i = j;
    }
    cout << ans;

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

