//��������1�ĸ���
#include<iostream>

using namespace std;
//lowbit������ȡһ���������һ��1���������λ
int lowbit(int x){
	return x&(-x);	//ԭ���벹��(����+1)��λ��õ�1��������λ
}

int main(){
	int n;
	cin >> n;
	
	while(n--){
		int x;
		cin >> x;
		
		int res = 0;
		while(x){
			x -= lowbit(x);
			res++;
		}
		cout << res << endl;
	}
		
	return 0;
}
