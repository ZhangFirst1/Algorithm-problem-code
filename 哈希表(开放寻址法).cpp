//哈希表(开放寻址法)
#include<iostream>
#include<cstring>

using namespace std;
const int N = 2e5+3; //开放寻址法一般开 数据范围的 2~3倍, 这样大概率就没有冲突了
const int null = 0x3f3f3f3f;

int h[N];

int find(int x){
	int k = (x % N + N) % N;
	while(h[k] != null && h[k] != x){	//如果这个位置不为空且不为x
		k++;
		if(k == N) k = 0;	//看完了最后一个位置，循环第一个
	}
	return k; //如果x在哈希表中，k就是x的下标；如果不在，k就是x应该存储的位置
}

int main(){
	int n;
	cin >> n;
	
	memset(h, 0x3f ,sizeof h);	//规定空指针为0x3f3f3f3f
	
	while(n--){
		string op;
		int x;
		cin >> op >> x;
		if(op == "I") h[find(x)] = x;
		else{
			if(h[find(x)] == null) cout << "No" <<endl;
			else cout << "Yes" << endl;
		}
		
	}
		
	return 0;
}
