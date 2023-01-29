//最长上升子序列模型 怪盗基德的滑翔翼
//https://www.acwing.com/problem/content/1019/
//选定方向后求从最左（右）到当前位置的最长上升子序列
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 110;

int n;
int a[N],f[N];

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		//正向求解LIS问题
		int res = 0;
		for(int i=1;i<=n;i++){
			f[i] = 1;
			for(int j=1;j<i;j++)
				if(a[i] > a[j]) f[i] = max(f[i], f[j]+1);
			res = max(res,f[i]);	
		} 
		//反向求解LIS问题
		for(int i=n;i>=1;i--){
			f[i] = 1;
			for(int j=n;j>i;j--)
				if(a[i] > a[j]) f[i] = max(f[i], f[j]+1);
			res = max(res,f[i]); 
		}
		cout << res << endl;
	}
	return 0;
}
