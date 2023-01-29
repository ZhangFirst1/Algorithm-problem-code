//差分
//输入一个长度为 n 的整数序列。
//接下来输入 m 个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c。
#include<iostream>

using namespace std;
const int N = 1e5+10;

int a[N],b[N];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i] - a[i - 1]; //构造差分数组
	}
	
	int l,r,c;
	while(m--){
		cin >> l >> r >> c;
		b[l] += c; 		//将序列a[l]之后都加上c
		b[r+1] -= c; 	//将序列a[r+1]之后都减去c
						//即将a[l,r]之间每个数加上c
	}
	
	for(int i=1;i<=n;i++){
		a[i] = a[i-1] + b[i];	//前缀和运算
		cout << a[i] << ' ';
	}	
	
	return 0;
}
