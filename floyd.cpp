//floyd多源最短路问题
#include<iostream>

using namespace std;
const int N = 210, INF = 1e9;

int d[N][N];

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	//邻接表初始化
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i == j) d[i][j] = 0;
			else d[i][j] = INF;
	//读入邻接表
	while(m--){
		int x,y,z;
		cin >> x >> y >> z;
		d[x][y] = min(d[x][y], z); //保存最小的边
	}
	//floyd 以当前点为中转点，刷新入度和出度
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	//k次询问
	while(k--){
		int a,b;
		cin >> a >> b;
		if(d[a][b] > INF / 2) cout << "impossible" << endl;
		else cout << d[a][b] << endl;
	}
	
	return 0;
}
