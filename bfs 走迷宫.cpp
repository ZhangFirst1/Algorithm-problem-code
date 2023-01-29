//bfs走迷宫
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 1010;
typedef pair<int,int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n,m;
int g[N][N],d[N][N];	//g存图,d存距离

int bfs(){
	queue<PII> q;
	q.push({0,0});
	
	memset(d,-1,sizeof(d));
	
	d[0][0] = 0;
	
	while(!q.empty()){
		PII t = q.front();
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < n && ny < m && d[nx][ny] == -1 && g[nx][ny] == 0){
				d[nx][ny] = d[t.first][t.second] + 1; //当前点到起点的距离
				q.push({nx,ny});	//新坐标入队
			}
		}
		
	}
	
	return d[n - 1][m - 1];
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> g[i][j];
	
	cout << bfs();
	
	return 0;
}
