//bellman_ford 有边数限制的最短路	
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int N = 100010;

struct edges{
	int a,b,w;
}edge[N];
int dis[N];
int back[N];	//备份数组防止串联
int n,m,k;	//k表示最短路径最多包含多少条边

void bellman_ford(){
	memset(dis,0x3f, sizeof dis);
	dis[1] = 0;
	for(int i=1;i<=k;i++){	//k次循环
		memcpy(back,dis,sizeof dis);
		for(int j=1;j<=m;j++){ //遍历所有边
			int a = edge[j].a, b = edge[j].b, w = edge[j].w;
			dis[b] = min(dis[b],back[a] + w);	//用上轮节点更新的距离来更新此轮节点，可避免串联
		}	
	}
	if(dis[n] > 0x3f3f3f3f / 2) cout << "impossible"; //负边更新后距离会变小
	else cout << dis[n];
	
}

int main(){
	cin >> n >> m >> k;
	
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		edge[i] = {a,b,c};
	}
	
	bellman_ford();

	
	return 0;
}
