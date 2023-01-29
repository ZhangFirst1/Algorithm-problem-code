//拜访亲戚
//单源最短路 + dfs + 打表
//https://www.acwing.com/problem/content/1137/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
typedef pair<int,int> PII;
const int N = 200010,INF = 0x3f3f3f3f;

int n,m;
int source[6]; //存不同起点
int head[N],cnt;
int dis[6][N];
bool st[N];

struct Edge{
	int w,to,next;
}edge[N];

void add(int x,int y,int z){
	edge[++cnt].w = z;
	edge[cnt].to = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

void dijkstra(int start,int dis[]){
	memset(st,0,sizeof st);
	memset(dis,0x3f, N * 4);
	dis[start] = 0;
	priority_queue<PII,vector<PII>, greater<PII> >q;
	q.push({0,start});
	
	while(!q.empty()){
		auto t = q.top();
		q.pop();
		int ver = t.second;
		if(st[ver]) continue;
		st[ver] = true;
		
		for(int i=head[ver];i;i=edge[i].next){
			int to = edge[i].to;
			if(dis[to] > dis[ver] + edge[i].w){
				dis[to] = dis[ver] + edge[i].w;
				q.push({dis[to],to});
			}
		}
	}
	
}

int dfs(int u,int start,int dist){
	if(u == 6) return dist;
	
	int res = INF;
	for(int i=1;i<=5;i++){
		if(!st[i]){ //当前亲戚还没去过
			int ne = source[i];
			st[i] = true;
			res = min(res,dfs(u+1 ,i ,dist + dis[start][ne]));
			st[i] = false;
		}
	}
	
	return res;
}

int main(){
	cin >> n >> m;
	source[0] = 1; //0的位置即佳佳的位置
	for(int i=1;i<=5;i++) cin >> source[i];
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c); add(b,a,c);
	}
	
	for(int i=0;i <= 5;i++) dijkstra(source[i],dis[i]);
	memset(st,0,sizeof st);
	printf("%d\n",dfs(1,0,0)); //第一个亲戚，当前起点，总距离
	
	return 0;
}
