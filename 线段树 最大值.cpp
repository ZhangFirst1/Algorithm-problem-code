//线段树
//https://www.acwing.com/problem/content/description/1277/
/*给定长度为 N 的数列 A，以及 M 条指令，每条指令可能是以下两种之一：
1.添加操作：向序列后添加一个数，序列长度变成 n+1；
2.询问操作：询问这个序列中最后 L 个数中最大的数是多少。
*/

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
const int N = 2e5+10;
typedef long long LL;
int m,p;
//线段树的节点，最大空间开4倍
struct Node{
	int l,r;
	int v; //区间[l,r]中最大值
}tr[4*N];

void pushup(int u){
	tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

//u表示当前线段树的节点编号
void build(int u,int l,int r){
	tr[u] = {l,r};
	if(l == r) return;
	int mid = l + r >> 1;
	build(u << 1,l,mid); //建立左子树
	build(u << 1 | 1,mid + 1 ,r); //建立右子树
}
//查询以u为根节点，区间[l,r]中的最大值
int query(int u,int l,int r){
	//  Tl --- Tr
	// L -------- R
	// 1.不必分治，直接返回 
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].v;
	
	int mid = tr[u].l + tr[u].r >> 1;
	int v = 0; //最大值
	//  Tl---m---Tr
	//     L ------ R
	// 2.需要在tr的左区间[Tl,m]继续分治
	if(l <= mid) v = max(v,query(u << 1,l,r));
	
	//  Tl---m---Tr
	// L ------ R
	// 3.需要在tr的右区间[m+1,Tr]继续分治
	if(r > mid) v = max(v, query(u << 1 | 1 ,l, r));

	return v;
}

//u为节点编号，更新该节点的区间最大值	
void modify(int u,int x,int v){
	if(tr[u].l == tr[u].r) tr[u].v = v; //叶节点，递归出口
	else{
		int mid = tr[u].l + tr[u].r >> 1;
		//分治寻找x所在的子树
		if(x <= mid) modify(u<<1, x, v);
		else modify(u << 1 | 1, x, v);
		//回溯，拿子节点的信息更新父节点，即pushup操作
		pushup(u);
	}
	
}


int main(){
	//n表示树中节点个数，last保存上一次查询结果
	int n = 0,last = 0;
	cin >> m >> p;
	//初始化线段树，节点的区间最多为[1,m]
	build(1,1,m);
	
	while(m--){
		char op;
		cin >> op;
		if(op == 'A'){
			int t;
			cin >> t;
			//在n+1处插入
			modify(1, n+1, ((LL)t + last) % p); //题目要求
			//节点个数+1
			n++;
		}else{
			int l;
			cin >> l;
			//查询[n - l + 1, n]内的最大值,u=1,即从根节点开始查询
			last = query(1, n-l+1, n);
			cout << last << endl;
		}
	}
	
	return 0;
}
