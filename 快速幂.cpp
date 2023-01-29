//快速幂 快速求出a^k mod p 
//如：求7^10   10 = (1010)2
//最初ans为1，然后我们一位一位算：
//1010的最后一位是0，所以a^1这一位不要。然后1010变为101，a变为a^2。
//101的最后一位是1，所以a^2这一位是需要的，乘入ans。101变为10，a再自乘。
//10的最后一位是0，跳过，右移，自乘。
//然后1的最后一位是1，ans再乘上a^8。循环结束，返回结果。
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
		//cin >> a >> p;  //求逆元(若a是p的倍数则无解)
		cout << qmi(a,b,p);
		//cout << qmi(a,p-2,p);
	}
	
	return 0;
}
