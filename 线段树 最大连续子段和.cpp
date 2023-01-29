//https://www.acwing.com/problem/content/description/246/

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 500010;

int n,m;
int w[N];
struct Node{
	int l,r;
	//总和 最大前缀 最大后缀 最大子段和
	int sum,lmax,rmax,tmax;
}tr[N*4];

void pushup(Node &u,Node &l,Node &r){
	u.sum = l.sum + r.sum; //总和等于两子节点之和
	u.lmax = max(l.lmax, l.sum + r.lmax); //左儿子和加右儿子最大前缀和
	u.rmax = max(r.rmax, r.sum + l.rmax);
	u.tmax = max(max(l.tmax,r.tmax), l.rmax + r.lmax); //左边 右边 跨区间
}

void pushup(int u){
	pushup(tr[u],tr[u << 1],tr[u << 1 | 1]);
}

void build(int u,int l,int r){
	if(l == r) tr[u] = {l,r,w[r],w[r],w[r],w[r]};
	else{
		tr[u] = {l,r};
		int mid = l + r >> 1;
		build(u << 1,l,mid);	
		build(u << 1 | 1,mid+1,r); 
		pushup(u);
	}
}

void modify(int u,int x,int v){
	if(tr[u].l == x && tr[u].r == x) tr[u] = {x,x,v,v,v,v};
	else{
		int mid = tr[u].l + tr[u].r >> 1;
		if(x <= mid) modify(u << 1,x,v);
		else modify(u << 1 | 1,x,v);
		pushup(u);
	}
}

Node query(int u,int l,int r){
	//当前区间被查询区间完全包含，返回当前区间
	if(tr[u].l >= l && tr[u].r <= r) return tr[u]; 
	else{
		int mid = tr[u].l + tr[u].r >> 1;
		if(r <= mid) return query(u << 1,l,r); //查询区间只在当前区间的左区间
		else if(l > mid) return query(u << 1 | 1,l,r);//只在右区间
		else{ //其他情况，合并左右区间的查询结果
			auto left = query(u << 1,l,r);
			auto right = query(u << 1 | 1,l,r);
			Node res;
			pushup(res,left,right);
			return res;
		}
	}
}


int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> w[i];
	build(1,1,n);
	
	int k,x,y;
	while(m--){
		cin >> k >> x >> y;
		if(k == 1){
			if(x > y) swap(x,y);
			auto q = query(1,x,y).tmax;
			cout << q << endl;
		}else{
			modify(1,x,y);
		}
	}
	
	return 0;
}
