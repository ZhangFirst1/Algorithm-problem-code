//双指针 最长连续不重复子序列
#include<iostream>

using namespace std;
const int N = 100010;

int a[N],s[N];

int main(){
	int n,res=0;
	cin >> n;
	//双指针[j, i]维护的是以a[i]结尾的最长连续不重复子序列，
	for(int i=0,j=0;i<n;i++){
		cin >> a[i];
		s[a[i]]++;
		while(s[a[i]] > 1) --s[a[j++]]; //先减后右移
		res = max(res ,i - j + 1);	
	}
	
	cout << res;
	
	return 0;
}
