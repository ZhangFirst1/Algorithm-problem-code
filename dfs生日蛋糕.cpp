#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N = 25, INF = 0x3f3f3f3f;

int n,m;
int minv[N],mins[N];
int R[N],H[N];
int ans = INF;

void dfs(int u,int v,int s){
	if(v + minv[u] > n) return; //当前体积加上这层可取最小体积已经大于n，剪枝
	if(s + mins[u] >= ans) return; //当前面积加上这层可取最小面积大于等于ans，说明更新无法改变最小值，剪枝
	if(s + 2 * (n-v) / R[u+1] >= ans) return; //推公式剪枝优化
		
	if(!u){ //搜完所有层
		if(v == n) ans = s;
		return;
	}
	
	//最小不能低于u(下边还有u-1层)，最大不能超过底下那层半径-1 或 sqrt(总体积 - 已用体积)
	for(int r = min(R[u+1] - 1, (int)sqrt(n - v)); r >= u; r--) //从大到小枚举
		for(int h = min(H[u+1] - 1, (n-v)/r/r); h >= u;h--){
			int t = 0;
			if(u == m) t = r*r; //如果最底层，加上鸟瞰表面积
			R[u] = r, H[u] = h;
			dfs(u-1,v + r*r*h, s + 2*r*h + t);
		}	
	
	
	
}

int main(){
	cin>> n >> m;
	
	for(int i=1;i<=m;i++){
		minv[i] = minv[i-1] + i*i*i;
		mins[i] = mins[i-1] + 2*i*i;
	}
	
	R[m+1] = H[m+1] = INF;
	
	dfs(m,0,0);
	
	if(ans == INF) cout << '0'; //ans未被更新说明无解
	else cout << ans;
	
	return 0;
}
