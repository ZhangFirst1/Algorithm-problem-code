//����ɸ
#include<iostream>

using namespace std;
const int N = 100010;

int prime[N],cnt;
bool st[N];

void get_prime_xian(int n){ //��֤ÿ������ֻ��һ����С������ɸ��
	for(int i=2;i<=n;i++){
		if(!st[i]) prime[++cnt] = i;
		
		for(int j=1;prime[j] <= n/i;j++){	//��prime[j]*i <= n,�Ѵ���n�ĺ���ɸ��ûɶ����
			st[prime[j] * i] = true;
			if(i % prime[j] == 0) break;	//prime[j]һ����i����С������
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
