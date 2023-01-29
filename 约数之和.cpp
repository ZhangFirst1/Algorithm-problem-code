//如果 N=p1^c1*p2^c2*…pk^ck
//约数个数：(c1+1)*(c2+1)*…*(ck+1)
//证明：N的任何一个约数都可以表示为b=p1^x1*p2^x2*...*pk^xk 0<xi<=ci
//对于每个xi的不同取值，都对应着不同的约数
//所以N的约数个数为上式

//约数之和： (p1^0+p1^1+…+p1^c1)*…*(pk^0+pk^1+…+pk^ck)
//证明：上式展开后即为(p1^x0*..*pk^x0)+(p2^x1*...*pk^x1)+...() xi取遍ci 

#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
typedef long long LL;
const int N = 110, MOD = 1e9+7;

int main(){
	int n;
	cin >> n;
	
	map<int,int> primes;
	
	while(n--){
		int x;
		cin >> x;
		for(int i=2;i<=x/i;i++){
			while(x % i == 0){
				primes[i]++;
				x /= i;
			}
		}
		if(x > 1) primes[x]++;
	}
	LL cnt = 1;
	LL res = 1;
	for(auto p : primes) cnt = cnt * (p.second + 1) % MOD; //求约数个数
	cout << cnt << endl;

	for(auto p:primes){
		LL a = p.first;
		LL b = p.second;
		LL t = 1;

		while(b--) t = (t * a + 1) % MOD; //别忘了p^0
		
		res = (res * t) % MOD;
	}
	
	
	cout << res;
	return 0;
}
