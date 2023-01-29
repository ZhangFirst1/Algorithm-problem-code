//背包 数字组合
//https://www.acwing.com/problem/content/280/
//把每个数看作一个物品，Ai看作体积
//目标：求出总体积恰好为M的方案数

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 10010;
int f[N];
int n,m;

int main(){
	cin >> n >> m;
	f[0] = 1;
	
	for(int i=1;i<=n;i++){
		int v;
		cin >> v;
		for(int j=m;j>=v;j--)
			f[j] += f[j - v];
	}
	
	cout << f[m] << endl;
	return 0;
}
