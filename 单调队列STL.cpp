//滑动窗口 单调队列stl
#include<iostream>
#include<queue>

using namespace std;
const int N = 1000010;

int a[N];

int main(){
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	deque<int> q;
	
	//单调减队列
	for(int i=1;i<=n;i++){
		while(!q.empty() && a[q.back()] >= a[i]) q.pop_back(); //删尾操作
		q.push_back(i);
		if(i >= k){
			while(!q.empty() && q.front() < i-k+1) q.pop_front();
			cout << a[q.front()] << ' ';
		}
	}
	cout << endl;
	//单调增队列
	deque<int> que;
	for(int i=1;i<=n;i++){
		while(!q.empty() && a[q.back()] <= a[i]) q.pop_back(); //删尾操作
		q.push_back(i);
		if(i >= k){
			while(!q.empty() && q.front() <= i-k+1)
			cout << a[q.front()] << ' ';
		}
	}
	
	return 0;
}
