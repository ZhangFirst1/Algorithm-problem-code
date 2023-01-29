#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;
typedef pair<int,int> PII;
const int N = 1010;

int n;
int g[N][N];
PII pre[N][N];

void bfs(int x,int y){
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	memset(pre,-1,sizeof pre);
	
	queue<PII> q;
	q.push(make_pair(x,y));
	pre[x][y] = {0,0};
	
	while(!q.empty()){
		PII t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			if(nx < 0 || nx >=n || ny < 0 || ny >= n) continue;
			if(g[nx][ny]) continue;
			if(pre[nx][ny].first != -1) continue;
		
			q.push({nx,ny});	
			pre[nx][ny] = t;
		}
	}
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&g[i][j]);
			
	bfs(n-1,n-1);
	
	PII ans = {0,0};
	
	while(1){
		printf("%d %d\n",ans.first,ans.second);
		if(ans.first == n-1 && ans.second == n-1) break;
		ans = pre[ans.first][ans.second];
	}
	
	
	return 0;
}
