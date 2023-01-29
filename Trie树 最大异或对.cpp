//Trie树 最大异或对
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 100010,M = 31*N; 

int n;
int a[N];
int son[M][2],idx;
//M表示一个二进制串有多长

void Insert(int x){
	int p = 0;
	for(int i=30;i>=0;i--){
		int u = x >> i & 1;	//表示取x的第i位二进制数是什么
		if(!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
}

int Search(int x){
	int p = 0, res = 0;
	for(int i=30;i>=0;i--){
		int u = x >> i & 1;
		if(son[p][!u]){	//如果当前层有对应的不相同的数
			p = son[p][!u]; //p指针找到不同数的地址
			res = res * 2 + 1;	//*2相当于左移一位 然后判断当前位是同还是异 同+0 异+1
		}else{
			p = son[p][u];
			res = res * 2 + 0;
		}
		
	}
	return res;
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		Insert(a[i]);
	}
	
	int res = 0;
	for(int i=0;i<n;i++)
		res = max(res,Search(a[i]));
		
	cout << res;
	
	
	return 0;
}
