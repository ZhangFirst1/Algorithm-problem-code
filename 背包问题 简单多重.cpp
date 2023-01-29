//数据量较小的多重背包问题可拆为01背包
#include<iostream>

using namespace std;
const int N = 10010;

int dp[N];
int w[N],v[N],cnt=1;

int main(){
	int n,m,a,b,c;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a >> b >> c;
		for(int j=1;j<=c;j++){
			v[cnt] = a;
			w[cnt++] = b;
		}
	}
	
	for(int i=1;i<=cnt;i++)
		for(int j=m;j>=v[i];j--)
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
	
	cout << dp[m];
	return 0;
}
