//素数筛
#include<iostream>

using namespace std;
const int N = 100010;

int prime[N],cnt;
bool st[N];

void get_prime_xian(int n){ //保证每个合数只被一个最小质因子筛掉
	for(int i=2;i<=n;i++){
		if(!st[i]) prime[++cnt] = i;
		
		for(int j=1;prime[j] <= n/i;j++){	//即prime[j]*i <= n,把大于n的合数筛掉没啥意义
			st[prime[j] * i] = true;
			if(i % prime[j] == 0) break;	//prime[j]一定是i的最小质因子
		}	
	}
}

int main(){
	int n;
	cin >> n;
	
	get_prime_xian(n);
	
	for(int i=1;i<=cnt;i++) cout << prime[i] << ' ';
	
	return 0;
}
