//最长上升子序列
#include<iostream>

using namespace std;
const int N = 1010;

int n;
int f[N],w[N];	//f[i]表示从第一个数字到w[i]结尾的最大上升序列的长度

int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> w[i];
	
	int maxn = 1; //找出所计算的f[i]中的最大值
	for(int i=1;i<=n;i++){
		f[i] = 1; //找不到前边更小的数字则为1
		for(int j=1;j<i;j++){
			if(w[i] > w[j])
				f[i] = max(f[i], f[j]+1); //取f[i]和f[j]加上w[i](即+1)大者
		}
		maxn = max(maxn,f[i]); //此轮更新可能没有之前的大
	}
	
	cout << maxn;
	return 0;
}
