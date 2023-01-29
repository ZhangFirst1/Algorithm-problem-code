//滑雪 记忆化搜索
#include<iostream>
#include<cstring>

using namespace std;
const int N = 310;

int n,m;
int a[N][N];  //记录每个点滑动的最大长度
int dp[N][N]; //dp[i][j] = max(dp[i][j-1], dp[i][j+1],dp[i-1][j],dp[i+1][j])

int nx[] = {1,0,-1,0};
int ny[] = {0,1,0,-1};

int dfs(int x,int y){
	if(dp[x][y] != 0) return dp[x][y]; // 如果该点的dp[][] 不为初始化值 那么就说明计算过 不必再次计算。
	
	for(int i=0;i<4;i++){
		int nxx = x + nx[i];
		int nyy = y + ny[i];
		
		if(nxx >= 1 && nxx <= n && nyy >=1 && nyy <= m && a[nxx][nyy] < a[x][y]){
			dp[x][y] = max(dp[x][y], dfs(nxx,nyy) + 1);
		}
		
	}
	return dp[x][y];
}

int main(){
	cin >> n >> m;
	int maxn = -1;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
			
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int len = dfs(i,j);
			maxn = max(maxn, len);
		}
	}
	
	cout << maxn + 1;
	
	return 0;
}
