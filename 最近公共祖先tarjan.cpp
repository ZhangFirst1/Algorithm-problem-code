//还没写完 写完后请删除此行
//最近公共祖先
//离线做法rarjan  O(n+m)
//在dfs中将所有点分为三大类
//1.已经遍历过且回溯过
//2.正在搜索的分支
//3.还未搜索到的点
//基本流程
//1.任选一个点为根节点，从根节点开始。
//2.遍历该点u所有子节点v，并标记这些子节点v已被访问过。
//3.若是v还有子节点，返回2，否则下一步。
//4.合并v到u上。
//5.寻找与当前点u有询问关系的点v。
//6.若是v已经被访问过了，则可以确认u和v的最近公共祖先为v被合并到的父亲节点a
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
typedef pair<int,int> PII;
const int N = 20010, M = 2*N;

int n, m;
int h[N], ne[M], e[M], idx, w[M];
vector<PII> query[N]; //first存储查询的点， second存储查询编号
int res[N], dis[N];
int fa[N];	//并查集
int st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void dfs(int u,int p){
	for(int i=h[u];i != -1;i = ne[i]){
		int j = e[i];
		if(j == p) continue;
		dis[j] = dis[u] + w[i]; //距离
		dfs(j,u);
	}
}

void tarjan(int u){
	st[u] = 1;
	for(int i=h[u];i != -1;i = ne[i]){
		int j = e[i];
		if(!st[j]){
			tarjan(j);
			fa[j] = u;	//合并到父节点
		}
	}
	//没有子节点了查询和当前点有询问关系的点
	for(auto item:query[u]){
		int y = item.first;
		int id = item.second;
		if(st[y] == 1){
			int anc = find(y);	//anc为两点lca
			res[id] = dis[u] + dis[y] - 2*dis[anc];
		}
	}
	
	//st[u] = 2;
}

int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i=1;i<n;i++){
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c); add(b,a,c);
	}
	//a到b的距离 = dis[a] + dis[b] - 2dis[lca(a,b)]
	for(int i=1;i<=m;i++){
		int a, b;
		scanf("%d%d",&a,&b);
		if(a != b){		//a和b相等res为0
			query[a].push_back({b,i});
			query[b].push_back({a,i});
		} 
	}
	
	for(int i=1;i<=n;i++) fa[i] = i; //并查集初始化
	
	dfs(1, -1); //求每个点和第一个点的距离
	tarjan(1);	//随便拿一个点当根节点
	
	for(int i=1;i<=m;i++) cout << res[i] << endl;
	
	return 0;
}
