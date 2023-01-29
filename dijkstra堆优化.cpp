//dijkstra∂—”≈ªØ
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
typedef pair<int,int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1000010;

int head[N],cnt;
struct edges{
	int to,next,w;
}edge[N];

int dis[N],n,m;
bool vis[N];

void add(int x,int y,int z){
	edge[++cnt].to = y;
	edge[cnt].w = z;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

priority_queue<PII ,vector<PII>, greater<PII> > q;

void dijkstra(int s){
	memset(dis, 0x3f, sizeof dis);
	
	dis[s] = 0;
	q.push(make_pair(0,s));
	
	while(!q.empty()){
		int ver = q.top().second;
		q.pop();
		
		if(vis[ver]) continue;
		vis[ver] = 1;
		
		for(int i=head[ver];i != 0;i = edge[i].next){
			int to = edge[i].to;
			if(dis[to] > dis[ver] + edge[i].w){
				dis[to] = dis[ver] + edge[i].w;
				q.push(make_pair(dis[to],to));
			}
		}
		
	}
	if(dis[n] != INF) cout << dis[n];
	else cout << "-1";	
}

int main(){
	cin >> n >> m;
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
	}
	
	dijkstra(1);
	
	return 0;
}
