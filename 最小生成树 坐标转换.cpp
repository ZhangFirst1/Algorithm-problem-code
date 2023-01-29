#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1010, M =2 * N * N + 10;
int n,m,k,sum;
struct Edge{
	int a,b,w;
}edge[M];
int fa[M];

int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

inline int merge(int x,int y){
	int headx = find(x), heady = find(y);
	if(headx != heady){
		fa[headx] = heady;
		return 1; //已经连了一条边
	}
	return 0;
}

int main(){
	cin >> n >> m;

	for(int i=1;i<=n*m;i++) fa[i] = i;
	/*如n = 3，m = 5
	1  2  3  4  5
	6  7  8  9  10
	11 12 13 14 15
	(x,y)的坐标为 (x-1)*m + y
	*/
	int x1,y1,x2,y2;
	while(cin >> x1 >> y1 >> x2 >> y2){
		int u = (x1 - 1) * m + y1; //坐标转换
		int v = (x2 - 1) * m + y2; 
		merge(u,v);
	}
	
	//竖向合并一遍
	for(int i=1;i<=m;i++)
		for(int j=1;j<n;j++){
			int u = (j-1)*m + i, v = j*m + i; //坐标转换
			if(merge(u,v)) sum++; //当前两点间有一条边，竖向答案+1
		}
	//横向合并一遍
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++){
			int u=(i-1)*m+j, v=(i-1)*m+j+1;
			if(merge(u,v)) sum += 2;
		}
	
	cout << sum << endl;
	
	return 0;
}
