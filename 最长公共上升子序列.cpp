//最长公共上升子序列
//https://www.acwing.com/problem/content/274/

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 3010;

int n;
int a[N],b[N];
int f[N][N]; //所有由第一个序列的前i个字母，和第二个序列的前j个字母构成的，且以b[j]结尾的公共上升子序列

int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	
	for(int i=1;i<=n;i++){
		int maxv = 1; //1表示空集情况
		for(int j=1;j<=n;j++){
			f[i][j] = f[i-1][j]; //不包含a[i]的情况
			if(a[i] == b[j]){ //由于状态包含b[j],如需包含a[i]需要a[i]与b[j]相等
				f[i][j] = max(maxv,f[i][j]);	
			}
			if(b[j] < a[i]) maxv = max(maxv,f[i-1][j] + 1); 
		}	
	}
	int res = 0;
	for(int i=1;i<=n;i++) res = max(res,f[n][i]);
	
	cout << res << endl;
	return 0;
}
