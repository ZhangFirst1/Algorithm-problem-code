//多重背包问题的二进制优化
#include<iostream>

using namespace std;
const int N = 20010;

int v[N],w[N];
int dp[N];

int main(){
	int n,m;
	cin >> n >> m;
	int cnt = 0;
	//二进制优化
	for(int i=1;i<=n;i++){
		int a,b,s;
		cin >> a >> b >> s;
		int k = 1;
		while(k <= s){
			cnt++;
			v[cnt] = a * k; //将体积与价值分组
			w[cnt] = b * k;
			s -= k;		//当前的k被凑完
			k *= 2;			
		}
		if(s > 0){
			v[++cnt] = a * s;
			w[cnt] = b * s;
		}
	}
	
	for(int i=1;i<=cnt;i++)
		for(int j=m;j>=v[i];j--)
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
	
	cout << dp[m] << endl;
	return 0;
}
