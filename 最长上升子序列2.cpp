//给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。
//1 <= N <= 100000
#include<iostream>

using namespace std;
const int N = 100010;

int a[N],f[N]; //f[N]为维护的单调递增的数组
int cnt;

int find(int x){
	int l = 1 , r = cnt;
	while(l < r){
		int mid = (l+r)/2;
		if(f[mid] < x) l = mid + 1;
		else r = mid; 		
	}
	return l;
}

int main(){
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[++cnt] = a[1];
	for(int i=2;i<=n;i++){
		if(a[i] > f[cnt]) f[++cnt] = a[i]; //a[i]大于f[cnt]则将其加入f[]数组
		else{
			int t = find(a[i]); //用a[i]替代f中第一个大于等于a[i]的数
			f[t] = a[i];
		}
	}
	
	cout << cnt;
	return 0;
}
