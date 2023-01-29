//https://www.acwing.com/problem/content/342/
//二分 + 最短路(双端队列广搜)
//从1到N经过的长度大于等于x的边个数是否小于等于k
//将边权分类，大于等于x边权看成1，否则看出0
//双端队列bfs

#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
const int N = 20010;
int head[N],cnt;
int n,m,k;
int dis[N];
bool st[N];
deque<int> q;
struct Edge{
	int w,to,next;
}edge[N];

void add(int x,int y,int z){
	edge[++cnt].to = y;
	edge[cnt].w = z;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

bool check(int bound){
	memset(st,0,sizeof st);
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	
	q.push_back(1);
	while(!q.empty()){
		int t = q.front();
		q.pop_front();
		
		if(st[t]) continue;
		st[t] = true;
		for(int i = head[t];i;i = edge[i].next){
			int to = edge[i].to, v = edge[i].w > bound; //大于则取1，否则取0
			if(dis[to] > dis[t] + v){ //若可以更新
				dis[to] = dis[t] + v;
				if(!v) q.push_front(to);
				else q.push_back(to);
			}
		}
	}
	return dis[n] <= k;
}

int main(){
	cin >> n >> m >> k;
	
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c); add(b,a,c);
	}
	
	int l = 0, r = 1e6+1; //取1e6+1可区分无解的情况
	while(l < r){
		int mid = (l+r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(r == 1e6+1) r = -1;
	cout << r;
	
	return 0;
}
