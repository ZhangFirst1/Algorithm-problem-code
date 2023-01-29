/*迭代加深
	当搜索树分支很多而答案位于某个比较浅的节点时，普通dfs可能在错误分支浪费很多时间
	可以限制搜索深度来提前找到答案
	例：加成序列
	https://www.acwing.com/solution/content/38248/
*/
#include<iostream>
#include<cstring>

using namespace std;
const int N = 110;

int path[N],n;
bool st[N]; //用于排除等效冗余

bool dfs(int u,int k){ //u当前深度，k最大深度
	if(u > k) return false;
	if(path[u-1] == n) return true;
	
	memset(st, 0, sizeof st);
	
	for(int i=u-1;i>=0;i--) //求的是当前的，所以从u-1开始
		for(int j=i;j>=0;j--){
			int s = path[i] + path[j];
			if(s > n || s <= path[u-1] || st[s]) continue; //path单调递增
			st[s] = true;
			path[u] = s;
			if(dfs(u+1,k)) return true;
		}
	return false;
}

int main(){
	
	path[0] = 1;
	
	while(cin >> n , n){
		int k = 1;
		while(!dfs(1,k)){
			k++;
		}
		for(int i=0;i<k;i++) cout << path[i] << ' ';
		cout << endl;
	}
	
	return 0;
}
