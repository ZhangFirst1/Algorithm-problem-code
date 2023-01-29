//双指针 数组元素的目标和
#include<iostream>

using namespace std;
const int N = 100010;

int a[N],b[N];

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=m;i++) cin >> b[i];
	
	for(int i=1,j=m;i<=n;i++){	//数组为升序，j指针不会回退
		while(j >= 1 && a[i] + b[j] > k) j--;
		if(j >= 1 && a[i] + b[j] == k) cout << i-1 << ' ' << j-1; 
	}
	
	return 0;
}
