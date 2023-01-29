//https://www.acwing.com/problem/content/1279/
//线段树的区间加 乘 查询操作
/*
7 43
1 2 3 4 5 6 7
5
1 2 5 5
3 2 4
2 3 7 9
3 1 3
3 4 7
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 200010;
typedef long long LL;
struct Node{
	int l,r;
	int sum,add,mul;
}tr[N*4];
int n,p,m;
int w[N];

void pushup(int u){
	tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void eval(Node &t,int add,int mul){
	t.sum = ((LL)t.sum * mul + (LL)(t.r - t.l + 1) * add) % p; //更改sum值，先乘后加
	t.mul = ((LL)t.mul * mul) % p; //更改乘法的懒标记
	t.add = ((LL)t.add * mul + add) % p; //改变加法的懒标记
	//对于一个数n	
	//若是加上一个数c，n变为n*mul + add + c，add变为add+c，mul不变;
	//若是乘上一个数c，n变为n*mul*c + add * c，add变为add*c，mul变为mul*c;
	//因此mul可写成mul*mul，add写成add*mul + add(+c时乘的mul为1，相当于没乘)
}

void pushdown(int u){
	eval(tr[u << 1],tr[u].add,tr[u].mul);
	eval(tr[u << 1 | 1],tr[u].add,tr[u].mul);
	tr[u].add = 0;
	tr[u].mul = 1; //清空懒标记
}

void build(int u,int l,int r){
	if(l == r) tr[u] = {l,r,w[r],0,1};
	else{
		tr[u] = {l,r,0,0,1};
		int mid = (l + r) >> 1;
		build(u << 1,l,mid);	build(u << 1 | 1,mid+1,r);
		pushup(u);
	}
}

void modify(int u,int l,int r,int add,int mul){
	if(tr[u].l >= l && tr[u].r <= r) eval(tr[u],add,mul);
	else{
		pushdown(u);
		int mid = (tr[u].l + tr[u].r) >> 1;
		if(l <= mid) modify(u << 1,l,r,add,mul);
		if(r > mid) modify(u << 1 | 1,l,r,add,mul);
		pushup(u);
	}
}

int query(int u,int l,int r){
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	
	pushdown(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	int sum = 0;
	if(l <= mid) sum = (sum + query(u << 1,l,r)) % p;
	if(r > mid) sum = (sum + query(u << 1 | 1,l,r)) % p; 
	return sum;
}

int main(){
	cin >> n >> p;
	for(int i=1;i<=n;i++) cin >> w[i];
	build(1,1,n);
	cin >> m;
	
	while(m--){
		int t,l,r,d;
		scanf("%d%d%d",&t,&l,&r);
		if(t == 1){
			cin >> d;
			modify(1,l,r,0,d);
		}else if(t == 2){
			cin >> d;
			modify(1,l,r,d,1);
		}else{
			cout << query(1,l,r) << endl;
		}
	}
	
	return 0;
}
