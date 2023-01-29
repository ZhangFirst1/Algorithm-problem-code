//双端队列广搜（只包含0和1的最短路）
//取出队头 如果扩展的边的权重是0则插到队头，否则插到队尾
//电路维修https://www.acwing.com/problem/content/177/

#include<iostream>
#include<algorithm>
#include<deque>
#include<cstring>

using namespace std;
typedef pair<int,int> PII;
const int N = 510;

char g[N][N];
int dis[N][N];
int n,m;
bool st[N][N];

int bfs(){
	deque<PII> q;
	memset(st,0,sizeof st);
	memset(dis,0x3f,sizeof dis);
	
	char cs[10] = "\\/\\/";  //图与点坐标的对应关系可推出相应图形
	int dx[4] = {-1,-1,1,1}; //每个点可走的四个方向
	int dy[4] = {-1,1,1,-1};
	int ix[4] = {-1,-1,0,0}; //点和图位置关系
	int iy[4] = {-1,0,0,-1};
	
	dis[0][0] = 0;
	q.push_back({0,0});
	
	while(!q.empty()){
		PII t = q.front();
		q.pop_front();
		
		int x = t.first; int y = t.second;
		
		if(x == n && y == m) return dis[x][y];
		
		if(st[x][y]) continue;
		st[x][y] = true;
		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
			int gx = x + ix[i];
			int gy = y + iy[i];
			int w = (g[gx][gy] != cs[i]);
			int d = w + dis[x][y];
			if(d <= dis[nx][ny]){
				dis[nx][ny] = d;
				if(!w) q.push_front({nx,ny});
				else q.push_back({nx,ny});
			}
			
		}
	}
	
	return -1;
}

int main(){
	int t;
	cin >> t;
	
	while(t--){
		scanf("%d%d",&n,&m);
		
		for(int i=0;i<n;i++) scanf("%s",g[i]);
		printf("%d\n",bfs());
		
		if((n+m) % 2 != 0) puts("NO SOLUTION");
		else printf("%d\n",bfs());
		
	}
		
	return 0;
}
