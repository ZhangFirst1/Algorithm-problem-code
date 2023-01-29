//拦截导弹
//https://www.acwing.com/problem/content/1012/
//dp+贪心 用最少的下降子序列覆盖原数组
//第二问，对于第i号导弹，要么选择末尾导弹高度最小的拦截系统，要么创建一个新的，
//用一个数字即每套拦截系统此时所拦截的最后一个导弹高度，来表示该系统。
//这样就得到了一个数组，数组最终长度就是所需最少拦截系统数目。
#include<iostream>
#include<cstring>

using namespace std;
const int N = 1010;
int a[N],f[N],g[N];
int n;

int main(){
	while(cin >> a[n]) n++;
	
	int ans = 0;
	for(int i=0;i<n;i++){
		f[i] = 1;
		for(int j=0;j<i;j++){
			if(a[j] >= a[i]) f[i] = max(f[i], f[j]+1);
		}
		ans = max(ans,f[i]);
	}	
	cout << ans << endl;
	
	int cnt = 0; //cnt表示数组长度，即当前子序列个数
	for(int i=0;i<n;i++){
		int k = 0;
		while(k < cnt && g[k] < a[i]) k++; //当前序列结尾小于当前数，遍历掉拦截不了当前导弹的系统
		g[k] = a[i]; //替换成更小的数,即用下一套拦截系统拦截导弹
		if(k >= cnt) cnt++;  //没有任何一个序列大于等于当前数，开一个新的序列	
	}
	
	cout << cnt << endl;
	return 0;
}
