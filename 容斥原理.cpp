//给定一个整数 n 和 m 个不同的质数 p1,p2,…,pm。
//请你求出 1～n 中能被 p1,p2,…,pm 中的至少一个数整除的整数有多少个。

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long LL;
const int N = 21;
int p[N], n, m;

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++) cin >> p[i];
	
	int res = 0;
	//枚举从1到111..(m个1)的每一个状态(至少选中一个集合)
	for(int i=1;i< 1<<m;i++){
		int t = 1; //选中集合对应质数的乘积
		int s = 0; //选中集合的数量
		
		//枚举当前状态的每一位
		for(int j=0;j<m;j++){
			//选中一个集合
			if(i >> j & 1){
				s++;
				//乘积大于n，则n/t = 0,跳出循环
				if((LL)t * p[j] > n){
					t = -1;
					break;
				}
				t *= p[j];
			}
		}
		if(t == -1) continue;
		
		if(s & 1) res += n/t; //选中奇数个集合, 加上 n/t为当前这种状态的集合数量
		else res -= n/t;    //反之则减去
		
	}
	cout << res << endl;
	return 0;
}
