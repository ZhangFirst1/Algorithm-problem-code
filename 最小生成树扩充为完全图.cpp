//走廊泼水节
//给定一棵N个节点的树，要求增加若干条边，把这棵树扩充为完全图，并满足图的唯一最小生成树仍然是这棵树。
//求增加的边的权值总和最小是多少。
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 13000;

int fa[N],s[N]; //s[i]记录i点所在的连通块有多少个节点
struct Edge{
	int a,b,w;
}edge[N];
int n,t;

bool cmp(Edge x,Edge y){
	return x.w < y.w;
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++) fa[i] = i,s[i] = 1; //初始化并查集
		for(int i=1;i<n;i++) cin >> edge[i].a >> edge[i].b >> edge[i].w; //读入n-1条边
		sort(edge+1,edge+n,cmp);
		long long res = 0;
		for(int i=1;i<n;i++){
			int a = find(edge[i].a), b = find(edge[i].b);
			if(a != b){
				//在不破坏最小生成树的情况下，需要加入两集合点数相乘-1(减去原有边)*(w+1)(为了不破坏需要权重+1)
				res += (long long)(s[a]*s[b] -1) * (edge[i].w+1); 
				fa[a] = b;
				s[b] += s[a];
			}
		}
		cout << res << endl;
	}
	
	return 0;
}
