#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 55;
int a[N];
int up[N],down[N];
int ans,n;

void dfs(int u,int su,int sd){
	if(su + sd >= ans) return; //剪枝，说明不能继续更新答案，直接返回
	if(u == n){ //找到一种方案，更新ans
		ans = su + sd;
		return;
	}
	//情况1. 将当前数放在上升子序列
	int k = 0;
	while(k < su && up[k] >= a[u]) k++;
	int t = up[k]; //备份，用于稍后恢复现场
	up[k] = a[u];
	if(k < su) dfs(u+1,su,sd); // 没有开辟新的上升子序列
	else dfs(u+1,su+1,sd); //开辟一个新的上升子序列
	up[k] = t; //恢复现场
	//情况2. 将当前数放在下降子序列
	k = 0;
	while(k < sd && down[k] <= a[u]) k++;
	t = down[k];
	down[k] = a[u];
	if(k < sd) dfs(u+1,su,sd);
	else dfs(u+1,su,sd+1);
	down[k] = t;
	
}

int main(){
	
	while(cin >> n,n){
		for(int i=0;i<n;i++) cin >> a[i];
		
		ans = n; //ans设为最大，即每个导弹一个系统，ans=n
		dfs(0,0,0); //当前枚举到哪个数，当前上升子序列个数，当前下降子序列个数
		
		cout << ans << endl;
	}
	
	return 0;
}
