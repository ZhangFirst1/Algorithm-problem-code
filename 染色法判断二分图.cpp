//染色法判断二分图 dfs
//将所有点分成两个集合，使得所有边只出现在集合之间，就是二分图
//二分图：一定不含有奇数环，可能包含长度为偶数的环， 不一定是连通图
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 2e5+10;
int e[N],ne[N],idx,h[N];
int n,m;
int st[N];

void add(int a,int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u,int color){
	st[u] = color;	//当前点的颜色为color
	
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(!st[j]){	//j点未染色
			if(!dfs(j, 3 - color)) return false;	
		}else if(st[j] == color) return false;	//如果一条边的两个点颜色相同则错误，返回false
	}
	return true;
}

int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m--){
		int a,b;
		cin >> a >> b;
		add(a,b); add(b,a); //无向图
	}
	
	bool flag = true;
	for(int i=1;i<=n;i++){	//遍历所有点
		if(!st[i]){			//每次将未染色的点dfs
			if(!dfs(i,1)){	//默认染成1或2,dfs过程矛盾则不为二分图
				flag = false;
				break;
			}
		}
	}
	
	if(flag) cout << "Yes";
	else cout << "No";
	
	return 0;
}
