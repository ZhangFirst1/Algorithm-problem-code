//ŷ����������(n):��ʾ1~n����n���ʵ����ĸ���
//N = p1^x1*p2^x2*...*pk^xk
//��(n) = N(1-1/p1)*(1-1/p2)*...*(1-1/pk)
//�ݳ�ԭ��֤��
#include<iostream>
#include<algorithm>
#include<cstring>
 
using namespace std;

int main(){
	int n;
	cin >> n;
	
	while(n--){
		int x;
		cin >> x;
		
		int res = x;
		for(int i=2;i<=x/i;i++){
			if(x % i == 0){
				//res = res * (1 - 1/i);
				res = res / i * (i-1); //��ʽ����
				while(x % i == 0) x /= i;				
			}
		}
		if(x > 1) res = res / x * (x-1);
		
		cout << res << endl;
	}	
	
	return 0;
}
