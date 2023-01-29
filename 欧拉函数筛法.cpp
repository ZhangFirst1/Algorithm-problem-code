//����ɸ����ŷ������
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
			phi[i] = i-1; //����һ������n����n-1������֮����
		}
		for(int j=1;primes[j] <= n/i;j++){
			st[primes[j]*i] = true;
			if(i % primes[j] == 0){
				phi[i*primes[j]] = phi[i] * primes[j]; //phi[pj*i]���Ѿ�����phi[i]�����������ӣ�ֻ����һ��phi[pj] 
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
