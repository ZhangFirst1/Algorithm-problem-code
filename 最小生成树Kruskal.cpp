//最小生成树 Kruskal
/*先把边按照权值进行排序，用贪心的思想优先选取权值较小的边，并依次连接，
若出现环则跳过此边（用并查集来判断是否存在环）继续搜，
直到已经使用的边的数量比总点数少一即可。*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 200050;

struct edges{
	int u,v,w;
}edge[N];
int ans,cnt,n,m,fa[N];

bool cmp(edges a,edges b){
	return a.w < b.w;
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);	//路径压缩
}

void Kruskal(){
	sort(edge+1,edge+1+m,cmp); //将边按权值排序
	
	for(int i=1;i<=m;i++){
		int headu = find(edge[i].u);
		int headv = find(edge[i].v);
		if(headu == headv) continue; //如果两个点已经联通，这条边不再需要
		ans += edge[i].w;
		fa[headu] = headv; 	//将headu与headv合并
		
		if(++cnt == n-1) break;
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=m;i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;
	
	Kruskal();
	
	if(cnt == n - 1) cout << ans;
	else cout << "impossible";
	
	return 0;
}
