//¿¨ÌØÀ¼Êý
//ans = Cn 2n - Cn-1 2n = Cn 2n / n+1;
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 200010, MOD = 1e9 + 7;

int n;
int fact[N], infact[N];

int qmi(int a,int k){
	int res = 1;
	while(k){
		if(k & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		k >>= 1;
	}
	return res;
}

void init(){
	fact[0] = infact[0] = 1;
	for(int i=1;i<N;i++){
		fact[i] = (LL)fact[i-1] * i % MOD;
		infact[i] = (LL)infact[i-1] * qmi(i, MOD-2) % MOD;
	}
}

int main(){
	init();
	cin >> n;
	int res = (LL)fact[2*n] * infact[n] % MOD * infact[n] % MOD * qmi(n+1, MOD -2 ) % MOD;
	cout << res << endl;
	return 0;
}
