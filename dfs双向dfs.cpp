/*双向dfs
	避免在深层子树浪费时间，从初态和终态各搜一半，最终交会
	
	送礼物
	https://www.acwing.com/solution/content/38250/
*/
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 46;
int n,m,k,ans;
int w[N];
int weight[1 << 25],cnt = 1;

void dfs1(int u,int s){
	if(u == k){
		weight[cnt++] = s; //weigh[0]是0，可以凑出重量0
		return;
	}
	//枚举当前不选这个物品
	dfs1(u+1,s);
	//选这个物品
	if((LL)s + w[u] <= m) dfs1(u+1,s+w[u]); //可行性剪枝
}

void dfs2(int u,int s){
	if(u >= n){ //找完了n个节点，二分一下
		int l = 0,r = cnt - 1;
		while(l < r){
			int mid = (l+r+1) / 2;
			if(weight[mid] > m - s) r = mid - 1;
			else l = mid;
			
		}
		ans = max(ans,weight[l] + s);
		return;
	}
	dfs2(u+1,s);
	
	if((LL)s + w[u] <= m) dfs2(u+1,s+w[u]);
}

int main(){
	cin >> m >> n;
	for(int i=0;i<n;i++) cin >> w[i];
	
	sort(w,w+n);
	reverse(w,w+n);
	
	k = n/2+2; //把前k个物品可以组成的重量打表
	dfs1(0,0);
	
	sort(weight,weight + cnt);
	cnt = unique(weight,weight + cnt) - weight;
	//从k开始 当前和是0
	dfs2(k,0);
	
	cout << ans << endl;
	return 0;
}
