#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 2000010;
typedef long long LL;

int n;
int a[N],t[N];
int Lower[N],Greater[N];

int lowbit(int x){
	return x & -x;
}
//序列中第x个数加上k
void add(int x,int k){
	for(int i=x; i<=n ;i += lowbit(i)) t[i] += k;
}
//查询序列前x个数的和
int ask(int x){
	int sum = 0;
	for(int i=x;i;i -= lowbit(x)) sum += t[i];
	return sum;
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	//从左向右，依次统计每个位置左边比第i个数y小的数的个数、以及大的数的个数
	for(int i=1;i<=n;i++){
		int y = a[i];
		//在前边已加入树状数组的所有数中统计区间[1,y-1]的数字出现的次数
		Lower[i] = ask(y-1);
		//统计区间[y+1,n]
		Greater[i] = ask(n) - ask(y);
		//把y加入树状数组，即y出现1次
		add(y,1);
	}	
	memset(t,0,sizeof t);
	int resA = 0,resV = 0;
	//从右向左统计
	for(int i=n;i>=1;i--){
		int y = a[i];
		resA += (LL)Lower[i] * ask(y-1);
		resV += (LL)Greater[i] * (ask(n) - ask(y-1));
		add(y,1);
	}
	cout << resA << ' ' << resV;
	return 0;
}
