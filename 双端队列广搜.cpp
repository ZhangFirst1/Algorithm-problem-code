//˫�˶��й��ѣ�ֻ����0��1�����·��
//ȡ����ͷ �����չ�ıߵ�Ȩ����0��嵽��ͷ������嵽��β
//��·ά��https://www.acwing.com/problem/content/177/

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
	
	char cs[10] = "\\/\\/";  //ͼ�������Ķ�Ӧ��ϵ���Ƴ���Ӧͼ��
	int dx[4] = {-1,-1,1,1}; //ÿ������ߵ��ĸ�����
	int dy[4] = {-1,1,1,-1};
	int ix[4] = {-1,-1,0,0}; //���ͼλ�ù�ϵ
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
