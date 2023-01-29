#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int,int> PII;
const int N = 1010;

int g[N][N],n;
bool vis[N][N];

int dy[] = {1,1,1,0,0,-1,-1,-1};
int dx[] = {-1,0,1,-1,1,0,-1,1};

void bfs(int x,int y,bool& hasPeak,bool& hasValley){
	queue<PII> q;
	q.push({x,y});
	vis[x][y] = true;
	
	while(!q.empty()){
		PII t = q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			
			if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if(g[nx][ny] == g[x][y] && !vis[nx][ny]){
				q.push({nx,ny});
				vis[nx][ny] = true;
			}else if(g[nx][ny] > g[x][y]){
				hasPeak = 0;
			}else if(g[nx][ny] < g[x][y]){
				hasValley = 0;
			}
		}
	}
}

int main(){
	cin >> n;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> g[i][j];
			
	int peak = 0, valley = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[i][j]){
				bool hasPeak=1,hasValley=1;
				bfs(i,j,hasPeak,hasValley);
				if(hasPeak) peak++;
				if(hasValley) valley++;
			}
		}
	}

	cout << peak << ' ' << valley;
	return 0;
}
