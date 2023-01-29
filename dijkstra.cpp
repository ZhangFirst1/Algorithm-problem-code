#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N = 100020;
const int INF = 0x3f3f3f3f;

int head[N],cnt,s,n,m,dis[N];
bool vis[N];
struct Node{
	int next,w,to;
}edge[N];

void add(int a,int b,int c){
	edge[++cnt].to = b;
	edge[cnt].w = c;
	edge[cnt].next = head[a];
	head[a] = cnt;
}

void dijkstra(){
	for(int i=1;i<=m;i++) dis[i] = INF;
	vis[s] = 1;
	dis[s] = 0;
	
	for(int i=1;i<=n;i++){
		int now = s, minn = INF;
		for(int j=1;j<=n;j++){
			if(!vis[j] && dis[j] < minn){
				now = j;
				minn = dis[j];
			}
		}
		vis[now] = 1;
		
		for(int i=head[now]; i ; i = edge[i].next){
			int to = edge[i].to;
			if(!vis[to] && dis[now] + edge[i].w < dis[to]){
				dis[to] = dis[now] + edge[i].w;
			}	
		}	
	}	
	
}

int main(){
	cin >> n >> m >> s;
	
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
	}
	
	dijkstra();
	
	for(int i=1;i<=n;i++){
		if(dis[i] == INF) cout << "2147483647 ";
		else cout << dis[i] << ' ';
	}
	
	return 0;
}
