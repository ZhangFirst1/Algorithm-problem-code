#include<iostream>

using namespace std;

void divide(int n){
	for(int i=2;i<=n/i;i++){
		if(n % i == 0){
			int s = 0;
			while(n % i == 0){
				n /= i;
				s++;
			}
			cout << i << ' ' << s << endl;
		}
	}
	if(n > 1) cout << n << " 1" << endl;	//n中最多包含一个大于sqrt(n)的质因子，最后处理一下下 
}

int main(){
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		if(x == 1) cout << "1 1" << endl;
		else divide(x);
	}
	return 0;
}
