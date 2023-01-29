//双指针 判断子序列
#include<iostream>

using namespace std;
const int N = 100010;
//判断a是否为b的子序列
int a[N],b[N];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int j=0;j<m;j++) cin >> b[j];
	//i扫描a数组，匹配成功后才向右移动
	//j扫描b数组，不断向右移动
	int i = 0;
	for(int j=0;j<m;j++){
		if(i < n && a[i] == b[j]) i++;
	}
	if(i == n) cout << "Yes";
	else cout << "No";
	
	return 0;
}
