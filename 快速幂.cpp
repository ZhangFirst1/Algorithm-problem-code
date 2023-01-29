//������ �������a^k mod p 
//�磺��7^10   10 = (1010)2
//���ansΪ1��Ȼ������һλһλ�㣺
//1010�����һλ��0������a^1��һλ��Ҫ��Ȼ��1010��Ϊ101��a��Ϊa^2��
//101�����һλ��1������a^2��һλ����Ҫ�ģ�����ans��101��Ϊ10��a���Գˡ�
//10�����һλ��0�����������ƣ��Գˡ�
//Ȼ��1�����һλ��1��ans�ٳ���a^8��ѭ�����������ؽ����
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;

LL qmi(int a,int k,int p){
	LL res = 1;
	while(k){
		if(k & 1) res = res * a % p; 
		a = (LL)a * a % p;
		k >>= 1;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	
	while(n--){
		int a,b,p;
		cin >> a >> b >> p;
		//cin >> a >> p;  //����Ԫ(��a��p�ı������޽�)
		cout << qmi(a,b,p);
		//cout << qmi(a,p-2,p);
	}
	
	return 0;
}
