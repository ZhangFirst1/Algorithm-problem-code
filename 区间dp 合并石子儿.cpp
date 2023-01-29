//石子儿合并
//区间dp，第一维枚举区间长度，一般len=1初始化，枚举从len=2开始，第二维枚举起点i（右端点j = i + len -1） 
#include<iostream>

using namespace std;
const int N = 400;

int a[N],s[N]; //用前缀和求出合并的代价
int dp[N][N]; //dp[i][j]表示将i到j合并成一堆的方案的集合

int main(){
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	
	//区间dp枚举，长度加左端点
	for(int len = 1;len < n;len++){	//len表示i和j堆下标的差值
		for(int i = 1;i+len <= n;i++){ //枚举左端点
			int j = i + len;//右端点
			dp[i][j] = 0x3f3f3f3f;
			for(int k = i;k <= j-1;k++){ //枚举分割点，需满足k+1 <= j
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + s[j] - s[i-1]);
			}
		}
	}
	
	cout << dp[1][n];
	return 0;
}
