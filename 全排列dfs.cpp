//全排列
#include<iostream>

using namespace std;
const int N = 10;

int a[N],n;
bool st[N];

void dfs(int u){
	if(u > n){
		for(int i=1;i<=n;i++)
			cout << a[i] << ' ';
		cout << endl;
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(!st[i]){		//如果数字i没被用过
			a[u] = i;	//放入空位
			st[i] = true;//数字被用，修改状态
			dfs(u+1);	//填下一个位置
			st[i] = false;	//回溯，取出i
		}
	}
	
}

int main(){
	cin >> n;
	dfs(1);
	
	return 0;
}
