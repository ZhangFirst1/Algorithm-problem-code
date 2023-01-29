//单调队列
//输出滑动窗口中的最大与最小值
#include<iostream>

using namespace std;
const int N = 100010;

int a[N],q[N],hh,tt = -1;

int main(){
	int n,k;
	cin >> n >> k;
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i - k + 1 > q[hh]) hh++;	//若队首出窗口，hh+1维护滑动窗口大小
		while(hh <= tt && a[i] <= a[q[tt]]) tt--;	//队尾不单调，删去队尾，加上当前元素 
		q[++tt] = i;	//下标加到队尾
		if(i + 1 >= k) printf("%d ",a[q[hh]]); 
	}
	
	cout << endl;
	hh = 0 , tt = -1;
	
	for(int i=0;i<n;i++){
		if(i - k + 1 > q[hh]) hh++;	//若队首出窗口，hh+1维护滑动窗口大小
		while(hh <= tt && a[i] >= a[q[tt]]) tt--;	//队尾不单调，删去队尾，加上当前元素 
		q[++tt] = i;	//下标加到队尾
		if(i + 1 >= k) printf("%d ",a[q[hh]]); 
	}	
	
	return 0;
}
