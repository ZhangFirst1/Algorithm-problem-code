#include<iostream>

using namespace std;
const int N = 100;
typedef long long LL;
LL jc[N] = {0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};

int solve(int k){
	int t = k;
	if(k >= 13) t = 12;
	for(int i=t-1;i>=1;i--){
		if((jc[i] + jc[i-1]) % k == 0){
			return i;
		}
	}
	return -1;
}

int main(){

	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		cout << solve(k) << endl;
	}
	
	return 0;
}
