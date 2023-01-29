//最近公共祖先
//1.向上标记法O(n)
//2.倍增法：预处理每个点向上走2^k步的父亲是谁
//预处理O(nlogn) 查询O(logn)
//fa[i][j]表示从i开始向上走2^j步所能走到的节点
//	j = 0, fa[i][j]为i的父节点
//	j > 0, fa[i][j] = fa[fa[i][j-1]] [j-1](跳两次2^(j-1))
//depth[i]表示深度
//哨兵：如果从i开始跳2^j步会跳出根节点，那么fa[i, j] = 0, depth[0] = 0
//(1)先将两个点跳到同一层：二进制拼凑，从高位到地位
//(2)让两个点同时往上跳，一直跳到他们最近公共祖先的下一层(如果用同一层判断可能跳到的点不是最近公共祖先)

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 40010, M = N*2;

int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][16]; //最长40000个点，2^16 > 40000

void add(int a,int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
//宽搜初始化depth与fa
void bfs(int root){
	memset(depth, 0x3f, sizeof depth);
	depth[0] = 0, depth[root] = 1;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		
		for(int i=h[t]; i != -1;i = ne[i]){
			int j = e[i];
			if(depth[j] > depth[t] + 1){
				depth[j] = depth[t] + 1;
				q.push(j);
				
				fa[j][0] = t; //向上跳1步
				for(int k=1;k<=15;k++){
					fa[j][k] = fa[fa[j][k-1]][k-1]; //分两步跳
				}
				
			}
		}	
	}
}

int lca(int a,int b){
	if(depth[a] < depth[b]) swap(a, b); //a在b的上边 交换一下，即从下边的点开始搜
	
	for(int k=15;k>=0;k--)				//跳到同一层
		if(depth[fa[a][k]] >= depth[b]) //从a开始跳2^k后仍在b下边
			a = fa[a][k];
	
	if(a == b) return a; //相等已经找到最近公共祖先
	
	for(int k=15;k>=0;k--)
		if(fa[a][k] != fa[b][k]) 	//没有跳到公共祖先的下一层
		{
			a = fa[a][k];
			b = fa[b][k];
		}
	return fa[a][0];			
}

int main(){
	cin >> n;
	int root = 0;
	memset(h, -1, sizeof h);
	for(int i=1;i<=n;i++){
		int a, b;
		scanf("%d%d",&a,&b);
		if(b == -1)  root = a;
		else add(a,b), add(b,a);
	}
	
	bfs(root);
	
	cin >> m;
	while(m--){
		int a, b;
		scanf("%d%d",&a,&b);
		int p = lca(a, b);
		if(p == a) cout << 1 << endl;
		else if(p == b) cout << 2 << endl;
		else cout << 0 << endl;
	}
	
	return 0;
}
