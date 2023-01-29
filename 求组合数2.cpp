//组合数2
//1≤n≤10000
//1≤b≤a≤10^5
//利用预处理加组合数公式
//a! / (a-b)!*b!
//其中除法用逆元表示

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long LL;
const int MOD = 1e9+7,N = 100010;
int fact[N], infact[N];

int qmi(int a,int k,int p){
	int res = 1;
	while(k){
		if(k & 1) res = (LL)res * a % p;
		a = (LL)a * a % p;
		k >>= 1;
	}
	return res;
}

int main(){
	fact[0] = infact[0] = 1;
	for(int i=1;i<N;i++){
		fact[i] = (LL)fact[i-1] * i % MOD;
		infact[i] = (LL)infact[i-1] * qmi(i, MOD-2, MOD) % MOD;
	}
	
	int n;
	cin >> n;
	while(n--){
		int a, b;
		scanf("%d%d",&a,&b);
		printf("%lld\n",(LL)fact[a] * infact[b] % MOD * infact[a-b] % MOD); //即使取模	
	}
	
	return 0;
}
