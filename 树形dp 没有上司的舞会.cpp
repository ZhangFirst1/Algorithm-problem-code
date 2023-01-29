//树形dp 没有上司的舞会
#include<iostream>
#include<cstring>

using namespace std;
const int N = 10010;

int e[N],ne[N],idx,h[N];
int dp[N][2],happy[N];
bool st[N];

void add(int x,int y){
	e[idx] = y, ne[idx] = h[x], h[x] = idx++; 
}

void dfs(int x){
	dp[x][1] += happy[x];	//表示老大要来，加上他的快乐值
	
	for(int i = h[x]; i != -1; i = ne[i]){
		int j = e[i];
		dfs(j);
		
		dp[x][0] += max(dp[j][0], dp[j][1]); //上司不来，最大为下属来或不来的快乐总值
		dp[x][1] += dp[j][0];  //上司来，下属只好不来
	}
}

int main(){
	memset(h,-1,sizeof h);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> happy[i];
	
	for(int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		add(b,a);
		st[a] = true;
	}
	
	int root = 1;
	while(st[root]) root++;	//找出根节点（老大）
	
	dfs(root);
	
	cout << max(dp[root][0], dp[root][1]);
	
	return 0;
}
