//模拟散列表(拉链法)
#include<iostream>
#include<cstring>

using namespace std;
const int N = 1e5+3;

int n;
int h[N],e[N],ne[N],idx;	//开一个槽h[]和邻接表
	
void Insert(int x){
	int k = (x % N + N) % N;	//c++中如果是负数 那他取模也是负的 所以 加N 再 %N 就一定是一个正数
	
	e[idx] = x;	//插入x
	ne[idx] = h[k];
	h[k] = idx++;
}

bool find(int x){
	int k = (x % N + N) % N;
	for(int i = h[k]; i != -1; i = ne[i]){
		if(e[i] == x) return true;
	}
	return false;
}

int main(){
	cin >> n;
	
	memset(h, -1 ,sizeof h);
	
	while(n--){
		string op;
		int x;
		cin >> op >> x;
		if(op == "I") Insert(x);
		else{
			if(find(x)) cout << "Yes" << endl;
			else cout << "No" <<endl;
		}
	}
	
	return 0;
}
