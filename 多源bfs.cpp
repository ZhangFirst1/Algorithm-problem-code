//��Դbfs
//���ͼ��ÿ��0�������1�ľ��룬�����һ�Ÿ��º�ĵ�ͼ
//������1���³�0�����������Ϊ0���������У����Դ�Ϊ������bfs����������ͼ

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int,int> PII;
const int N = 1010;

int n,m;
char g[N][N];
int dis[N][N];

void bfs(){
	memset(dis, -1 , sizeof dis);
	
	queue<PII> q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(g[i][j] == '1'){
				dis[i][j] = 0; //����1�ľ���Ϊ0
				q.push({i,j});
			}
	
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	
	while(!q.empty()){
		PII t = q.front();
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(dis[nx][ny] != -1) continue;
			
			dis[nx][ny] = dis[t.first][t.second] +1;
			q.push({nx,ny});
			
		}
		
	}
	
	
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++) scanf("%s",g[i]);
	
	bfs();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout << dis[i][j] << ' ';
		cout << endl;
	}
	
	return 0;
}
