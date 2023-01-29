//�ַ���hash
//�Ƚ�һ���ַ����������ִ��Ƿ���ͬ
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
typedef unsigned long long ULL;	//����ull����Ȼ�������
const int P = 131, N = 100010;

int n, m;
char str[N];
ULL p[N]; 	//Ԥ����p��n�η�
ULL h[N];	//��ϣ

ULL get(int l,int r){
	return h[r] - h[l-1] * p[r-l+1]; //����ϵ��p�Ĵ��ڣ�����ֱ����ǰ׺�ͣ���Ҫ��ȥ�����ʣ�µ������h[l-1]*p[r-l+1];
}
/*����͹�ʽ�����: ABCDE �� ABC ��ǰ�����ַ�ֵ��һ����ֻ����λ��
���� P2P2 �� ABC ��Ϊ ABC00������ ABCDE - ABC00 �õ� DE �Ĺ�ϣֵ��*/

int main(){
	cin >> n >> m;
	cin >> (str+1);
	p[0] = 1;	//131^0 = 1
	for(int i=1;i<=n;i++){
		h[i] = h[i-1] * P + str[i];	//hash[i] = hash[i-1] * Base + str[i]
		p[i] = p[i-1] * P;
	}
	while(m--){
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if(get(l1,r1) == get(l2,r2)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
