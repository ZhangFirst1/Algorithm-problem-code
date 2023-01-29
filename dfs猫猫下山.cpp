/*dfs剪枝
1.优化搜索顺序
	优先搜索分支数量较小的节点
2.排除等效冗余
	不考虑顺序的情况下用组合搜索
3.可行性剪枝
	搜到不合法直接返回
4.最优性剪枝
	当前方案不可能是最优解直接退出
5.记忆化搜索(DP)
*/
	
//猫猫下山
//索道上的缆车最大承重量为 W，而 N 只小猫的重量分别是 C1、C2……CN

#include<iostream>
#include<algorithm>

using namespace std;
const int N = 20;

int a[N],sum[N];
int n,m;
int ans = N;
//第u只猫猫，第k辆车
void dfs(int u,int k){
	if(k >= ans) return; //最优性剪枝
	if(u == n){
		ans = k;
		return;
	}
	
	for(int i=0;i<k;i++){
		if(sum[i] + a[u] <= m){ //可行性剪枝
			sum[i] += a[u];
			dfs(u+1,k);
			sum[i] -= a[u]; //恢复现场
		}
	}
	
	sum[k] = a[u]; //新开一辆车
	dfs(u+1,k+1);
	sum[k] = 0; //恢复现场
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	
	//优化搜索顺序
	//从大到小开始找猫猫
	sort(a,a+n);
	reverse(a,a+n);
	
	dfs(0,0);
	
	cout << ans;
	
	return 0;
}
