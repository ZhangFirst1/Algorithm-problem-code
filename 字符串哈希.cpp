//字符串hash
//比较一个字符串的两个字串是否相同
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
typedef unsigned long long ULL;	//采用ull的自然溢出方法
const int P = 131, N = 100010;

int n, m;
char str[N];
ULL p[N]; 	//预处理p的n次方
ULL h[N];	//哈希

ULL get(int l,int r){
	return h[r] - h[l-1] * p[r-l+1]; //由于系数p的存在，不能直接用前缀和，需要消去做差后剩下的项，即用h[l-1]*p[r-l+1];
}
/*区间和公式的理解: ABCDE 与 ABC 的前三个字符值是一样，只差两位，
乘上 P2P2 把 ABC 变为 ABC00，再用 ABCDE - ABC00 得到 DE 的哈希值。*/

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
