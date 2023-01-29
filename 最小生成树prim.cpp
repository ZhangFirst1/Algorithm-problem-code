//最小生成树，Prim
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5050;

struct edge{
	int next,to,w;
}edge[500000];
int head[N],cnt,ans,n,m,dis[N],sum_bian,now=1;	//dis[n]表示n点到集合中的距离
bool vis[N];

void add(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int prim(){
	for(int i=1;i<=n;i++) dis[i] = INF;
	dis[now] = 0;
	for(int i=head[1];i;i = edge[i].next)
		dis[edge[i].to] = min(dis[edge[i].to],edge[i].w);//去重复边
	
	while(++sum_bian < n){
		int minn = INF;
		vis[now] = 1;
        //枚举每一个没有使用的点
        //找出最小值作为新边
        //注意这里不是枚举now点的所有连边，而是1~n		
	    for(int i=1;i<=n;i++){
			if(!vis[i] && minn > dis[i]){
				minn = dis[i];
				now = i;
			}
		}
		if(minn == INF) return INF;		//如果没找到最短边则返回，可判断是否可以最小生成树
		ans += minn;
        //利用新加入的节点now对未加入最小生成树的点进行松弛
		for(int i=head[now]; i ;i = edge[i].next){
			int to = edge[i].to;
			if(dis[to] > edge[i].w && !vis[to])
				dis[to] = edge[i].w;
		}
			
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	
	if(prim() == INF)
		cout << "orz";
		else
		cout << ans;
	
	return 0;
}
