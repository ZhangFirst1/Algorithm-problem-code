//SPFA算法
//注意：此判断负环是1到n，而不是图中是否存在
//若判断图中是否存在，则入队时将所有点入队
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 100010;

int head[N],cnt;
struct edges{
	int to,next,w;
}edge[N];
int n,m;
int dis[N],outqueue[N]; //outqueue表示出队次数，可用于判断负环
bool st[N];	//表示当前已经发生过更新的点，与dijkstra不同，SPFA的st数组是可逆的

void add(int x,int y,int z){
	edge[++cnt].to = y;
	edge[cnt].w = z;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

int SPFA(){
	queue<int> q;
	memset(dis, 0x3f , sizeof dis);
	dis[1] = 0;
	q.push(0);
	st[1] = true;
	//判断图中是否存在负环
	/*for(int i=1;i<=n;i++){
		q.push(i);
		st[i] = true;
	}
	*/
	
	while(q.size()){
		int ver = q.front();
		q.pop();
		st[ver] = false; //从队列取出后t节点表示为false，此后如果发生更新可再次入队
		outqueue[ver]++;
		if(outqueue[ver] > n) return 0;//出队次数大于n则存在负环
		
		for(int i=head[ver]; i != 0; i = edge[i].next){
			int to = edge[i].to;
			if(dis[to] > dis[ver] + edge[i].w){
				dis[to] = dis[ver] + edge[i].w;
				if(!st[to]){//当前已经加入队列的结点，无需再次加入队列，即便发生了更新也只用更新数值即可，重复添加降低效率
					st[to] = true;
					q.push(to);
				}
			}
		}
		
	}
	if(dis[n] == 0x3f3f3f3f) cout << "impossible";	//与bellman不同，如果不连通则不会更新，保持INF
	else cout << dis[n];
	
	return 1;
}

int main(){
	cin >> n >> m;
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
	}
	
	if(SPFA()) cout << "无负环";
	else cout << "存在负环";
	
	return 0;
}

