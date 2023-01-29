//最长公共子序列
#include<iostream>

using namespace std;
const int N = 1010;

char a[N],b[N];
int f[N][N]; //f[i][j]表示a的前i个字母，和b的前j个字母的最长公共子序列长度

int main(){
	int n,m;
	cin >> n >> m >> (a+1) >> (b+1);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1; //a[i]和b[j]相同长度直接+1
			else f[i][j] = max(f[i-1][j], f[i][j-1]);   //要么a[i]不在公共序列，要么b[j]不在(包括了都不在的情况)
		}
	}
	
	cout << f[n][m];
	return 0;
}
