//01背包问题 完全背包问题
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 10010;

int v[N],w[N];
int dp[N]; //dp[i][j]表示：前i个物品，背包容量j下的最优解

//1.当前背包容量不够(j < v[i])，没得选，因此最优解为前i-1个物品最优解
//dp[i][j] = dp[i-1][j];
//2.容量够，决策是否选择第i个物品
//选：dp[i][j] = dp[i-1][j - v[i]] + w[i];
//不选：dp[i][j] = dp[i-1][j];

void bag01(int n,int m){
	//状态转移方程dp[i][j] = max(dp[i-1][j], dp[i-1][j - v[i]] + w[i])
	for(int i=1;i<=n;i++)
		for(int j=m;j>=v[i];j--) //反向枚举，因为j > j - v[i],所以正向枚举dp[j-v[i]]在i层会再次被更新
			dp[j] = max(dp[j] , dp[j - v[i]] + w[i]);	
			
	cout << dp[m] << endl;
}

void bagwanquan(int n,int m){
	//状态转移方程dp[i][j] = max(dp[i-1][j], dp[i][j - v[i]] + w[i])
	for(int i=1;i<=n;i++)
		for(int j=v[i];j<=m;j++) //正向枚举可达到dp[i][j - v[i]]的效果
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
			
	cout << dp[m] << endl;
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
	
	bag01(n,m);
	
	//bagwanquan(n,m);
	
	return 0;
}
