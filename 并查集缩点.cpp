//并查集缩点
//https://www.acwing.com/problem/content/1144/
//1.将所有必选边加入并查集中
//2.将所有非必选边从小到大排序
//3.从小到大枚举非必选边，a，b，w
//	如果a和b已经联通 直接pass
//	若不连通，将当前边选上
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 10010;
int fa[N];
struct Edge{
	int a,b,w;
	bool operator< (const Edge &t) const{
		return w < t.w;
	}
}edge[N];
int n,m;

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) fa[i] = i;
	
	int res = 0, cnt = 0;
	for(int i=1;i<=m;i++){
		int t,a,b,w;
		cin >> t >> a >> b >> w;
		if(t == 1){
			res += w;
			fa[find(a)] = find(b);
		}else{
			edge[++cnt] = {a,b,w};
		}	
	}
		
	sort(edge+1,edge+1+cnt);
	
	for(int i=1;i<=cnt;i++){
		int a = find(edge[i].a), b = find(edge[i].b);
		if(a != b){
			res += edge[i].w;
			fa[a] = b;
		}
	}
	
	cout << res;
	return 0;
}
