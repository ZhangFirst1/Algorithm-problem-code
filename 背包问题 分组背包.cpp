//背包问题 分组背包
#include<iostream>

using namespace std;
const int N = 110;

int v[N][N],w[N][N],s[N];
int dp[N];	//只从前i组物品中选，当前体积小于等于j的最大值

int main(){
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){ //读入每组物品的价值与体积
		cin >> s[i];	   //s[i]表示i组物品的个数
		for(int j=0;j<s[i];j++)   //从0开始
			cin >> v[i][j] >> w[i][j];
	}
	
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)	//逆序保证每组只选一次
			for(int k=0;k < s[i];k++)
				if(v[i][k] <= j)
					dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);	
			
	cout << dp[m] << endl;
	
	return 0;
}
