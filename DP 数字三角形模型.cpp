//数字三角形模型
//https://www.acwing.com/problem/content/1029/
//两条路径同时进行
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 15;
				  //第一维表示当前横纵坐标之和，只有i1+j1 == i2+j2时两条路径才可能相等 也可以理解为总步数
int f[N*2][N][N]; //f[k][i1][i2]表示所有(1,1) (1,1)到(i,k-i) (i2,k-i2)路径的最大值
int w[N][N],n;

int main(){
	cin >> n;
	int a,b,c;
	while(cin >> a >> b >> c,a||b||c) w[a][b] = c;
	
	for(int k=2;k<=n+n;k++)
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				int j1 = k - i1, j2 = k - i2;
				if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n){ //判断是否越界
					int t = w[i1][j1]; //同一格加一次
					if(i1 != i2) t += w[i2][j2]; //总步数相同，i1和i2相同就说明是同一格 只加一次，否则再加一次
					f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2-1] + t); //下下
					f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2] + t); //下右
					f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2-1] + t); //右下
					f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2] + t); //右右
				}
			}
	
	cout << f[n+n][n][n] << endl;
	return 0;
}
