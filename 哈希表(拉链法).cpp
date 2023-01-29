//ģ��ɢ�б�(������)
#include<iostream>
#include<cstring>

using namespace std;
const int N = 1e5+3;

int n;
int h[N],e[N],ne[N],idx;	//��һ����h[]���ڽӱ�
	
void Insert(int x){
	int k = (x % N + N) % N;	//c++������Ǹ��� ����ȡģҲ�Ǹ��� ���� ��N �� %N ��һ����һ������
	
	e[idx] = x;	//����x
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
