//最长上升子序列模型 登山
//https://www.acwing.com/problem/content/1016/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1010;

int n;
int a[N];
int f[N],g[N]; //以k为中间点 左右两边的最长上升子序列模型

int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){ //从左向右预处理f[i]
		f[i] = 1;
		for(int j=1;j<i;j++)
			if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
	}
	for(int i=n;i>=1;i--){ //从右向左预处理g[i]
		g[i] = 1;
		for(int j=n;j>i;j--)
			if(a[i] > a[j]) g[i] = max(g[i], g[j] + 1);
	}
	
	int res = 0;
	for(int i=1;i<=n;i++) res = max(res, f[i] + g[i] - 1); //i点计算了两次 所以要减一
	cout << res;
	return 0;
}
