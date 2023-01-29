//道路与航线
//道路成团，航线拓扑排序
//1.先输入所有双向道路，dfs出所有连通块，计算俩数组
//id[]存储每个点属于哪个连通块，vecrot<int> block[]存储每个连通块中有哪些点
//2.输入所有航线，同时统计出每个连通块的入度
//3.按照拓扑序处理每个连通块。先将所有入度为0的连通块加入队列中。
//4.每次从队头取出一个连通块的编号bid
//5.将block[bid]中所有点加入堆中，对堆中所有点做dijkstra
//6.每次取出堆中距离最小的点ver
//7.遍历ver的所有临点j，若id[ver] == id[j],那么如果j能被更新，则将j插入堆中；
//如果id[ver] != id[j]则将id[j]这个连通块的入度减1，如果减为零，则将其插入拓扑排序的队列中
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
typedef pair<int,int> PII;
const int N = 150010,INF = 0x3f3f3f3f;

int n,mr,mp,s;
int head[N],cnt; 
int id[N],dis[N]; //id[]表示每个点属于哪个连通块
vector<int> block[N]; //每个连通块中有哪些点
int bcnt; //连通块的个数
int din[N]; //每个连通块的入度
bool st[N];
struct Edge{
	int w,to,next;
}edge[N];
queue<int> q;

void add(int x,int y,int z){
	edge[++cnt].to = y;
	edge[cnt].w = z;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

void dfs(int u,int bid){
	id[u] = bid; //u点属于编号为bid的连通块
	block[bid].push_back(u); //bid这个块中包含u点
	
	for(int i = head[u]; i ; i = edge[i].next){
		int to = edge[i].to;
		if(!id[to]) dfs(to,bid); //如果当前点还没遍历过，将其继续dfs
	}
}

void dijkstra(int bid){
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	for(auto ver:block[bid]) heap.push({dis[ver],ver}); //遍历连通块中的所有点并加入堆
	
	while(!heap.empty()){
		auto t = heap.top();
		heap.pop();
		
		int ver = t.second;
		if(st[ver]) continue;
		st[ver] = true;
		
		for(int i=head[ver];i;i = edge[i].next){
			int to = edge[i].to;
			if(dis[to] > dis[ver] + edge[i].w){
				dis[to] = dis[ver] + edge[i].w;
				if(id[to] == id[ver]) heap.push({dis[to],to}); //如果临点与当前点在同一连通块，加入堆继续dijkstra
			}
			//如果不在同一连通块，说明此路为航线，更新入度，若入度为0，加入队列
			if(id[to] != id[ver] && --din[id[to]] == 0) q.push(id[to]); 	
		}
	}
}

void topsort(){
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	
	for(int i=1;i<=bcnt;i++)
		if(!din[i])
			q.push(i); 
	
	while(!q.empty()){
		int t = q.front();
		q.pop();
		
		dijkstra(t);
	}
}

int main(){
	cin >> n >> mr >> mp >> s;
	while(mr--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c); add(b,a,c);
	}
	//dfs所有连通块
	for(int i=1;i<=n;i++)
		if(!id[i])
			dfs(i,++bcnt);
	//读入所有航线
	while(mp--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		din[id[b]]++; //b所属的连通块入度+1
	}
	
	topsort();
	
	for(int i=1;i<=n;i++)
		if(dis[i] > INF / 2) //存在负权边，正无穷可能更新正无穷，会减小dis的值
			cout << "NO PATH" << endl;
		else cout << dis[i] << endl;
	return 0;
}
