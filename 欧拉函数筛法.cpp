//线性筛法求欧拉函数
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long LL;
const int N = 100010;

int primes[N], cnt;
int phi[N];
bool st[N];

LL getPrimes(int n){
	phi[1] = 1;
	for(int i=2;i<=n;i++){
		if(!st[i]){
			primes[++cnt] = i;
			phi[i] = i-1; //对于一个质数n，有n-1个数与之互质
		}
		for(int j=1;primes[j] <= n/i;j++){
			st[primes[j]*i] = true;
			if(i % primes[j] == 0){
				phi[i*primes[j]] = phi[i] * primes[j]; //phi[pj*i]中已经含有phi[i]中所有质因子，只多了一项phi[pj] 
				break;
			}
			//i % pj != 0
			phi[primes[j]*i] = phi[i] * (primes[j] - 1); //phi[pj*i] = phi[i] * pj * (1-1/pj) 
		}
	}
	LL res = 0;
	for(int i=1;i<=n;i++) res += phi[i];
	return res;
}

int main(){
	int n;
	cin >> n;
	
	cout << getPrimes(n) << endl;
	
	return 0;
}
