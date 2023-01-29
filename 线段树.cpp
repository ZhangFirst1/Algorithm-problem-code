//https://www.acwing.com/problem/content/244/
//线段树区间修改操作
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long LL;
const int N = 100010;
int n,m;
int w[N];
struct Tree{
	int l,r;
	LL sum,add;
}tr[N];

void pushup(int u){
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
	auto &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
	if(root.add){ //如果存在懒标记
		l.add += root.add, l.sum += (LL)(l.r - l.l + 1) * root.add;//左右节点的懒标记加上父节点的懒标记(将懒标记向下传)
		r.add += root.add, r.sum += (LL)(r.r - r.l + 1) * root.add;
		root.add = 0; //去除父节点的懒标记
	}
}

void build(int u,int l,int r){
	if(l == r) tr[u] = {l,r,w[r],0};
	else{
		tr[u] = {l,r};
		int mid = (l+r) >> 1;
		build(u << 1,l,mid);	build(u << 1 | 1,mid+1,r);
		pushup(u);   //改变子树后由子树更新父节点
	}
}

void modify(int u,int l,int r,int d){
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d; //如果当前区间完全在待修改区间内，直接修改区间总和
		tr[u].add += d;	//懒标记
	}else{ //分裂区间
		pushdown(u); //整个区间的标记不一样，需要先将当前的标记朝下传
		int mid = (tr[u].l + tr[u].r) >> 1;
		if(l <= mid) modify(u << 1,l,r,d); //包含左区间
		if(r > mid) modify(u << 1 | 1,l,r,d);//包含右区间
		pushup(u); //子区间修改完更新父区间
	}
}

LL query(int u,int l,int r){
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	
	pushdown(u); //查询时先pushdown掉当前标记
	int mid = (tr[u].l + tr[u].r) >> 1;
	LL sum = 0;
	if(l <= mid) sum += query(u << 1,l,r);
	if(r > mid) sum += query(u << 1 | 1,l,r);
	return sum;
}


int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> w[i];
	
	build(1,1,n);
	//C l r d，表示把 A[l],A[l+1],…,A[r] 都加上 d。
	//Q l r，表示询问数列中第 l～r 个数的和。
	char op[2];
	int l,r,d;
	while(m--){
		scanf("%s%d%d",op,&l,&r);
		if(op[0] == 'C'){
			cin >> d;
			modify(1,l,r,d);
		}else{
			cout << query(1,l,r) << endl; 
		}
	}
	
	return 0;
}
