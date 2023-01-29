//昂贵的聘礼
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 110, INF = 0x3f3f3f3f;
int n,m;
int dis[N]; 
int g[N][N],level[N]; 
bool st[N];

int dijkstra(int down,int up){
	memset(st,0,sizeof st);
	memset(dis,0x3f,sizeof dis);
	
	dis[0] = 0;
	for(int i=0;i<=n;i++){
		int t = -1;
		for(int j=0;j<=n;j++){ //0号点（虚拟原点）也在图中
			if(!st[j] && (t == -1 || dis[j] < dis[t])) 
				t = j;	
		}
		st[t] = true;
		for(int j=1;j<=n;j++){ 
			if(level[j] >= down && level[j] <= up){
				if(!st[j] && dis[t] + g[t][j] < dis[j]){
					dis[j] = dis[t] + g[t][j];
				}
			}
		}
		
	}
	return dis[1];
}

int main(){
	cin >> m >> n;
	memset(g,0x3f,sizeof g); //初始化
	for(int i=1;i<=n;i++) g[i][i] = 0;
	
	for(int i=1;i<=n;i++){
		int price,cnt;
		cin >> price >> level[i] >> cnt;
		g[0][i] = min(price,g[0][i]); //虚拟原点与当前点连边
		while(cnt--){
			int id,cost;
			cin >> id >> cost;
			g[id][i] = min(g[id][i],cost);
		}
	}
	
	int res = INF;
	for(int i=level[1]-m;i <= level[1];i++) //枚举等级区间（要包含1的等级）
		res = min(res, dijkstra(i, i+m)); //所有结果取最小值
	
	return 0;
}
