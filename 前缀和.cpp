//前缀和
#include<iostream>

using namespace std;
const int N = 100010;

int a[N],s[N];

int main(){
	int n,q;
	cin >> n >> q;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
	
	while(q--){	//q组询问
		int l,r;
		cin >> l >> r;
		cout << s[r] - s[l-1] << endl;
	}
	
	return 0;
}
