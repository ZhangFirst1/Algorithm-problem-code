//Trie�� �������
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 100010,M = 31*N; 

int n;
int a[N];
int son[M][2],idx;
//M��ʾһ�������ƴ��ж೤

void Insert(int x){
	int p = 0;
	for(int i=30;i>=0;i--){
		int u = x >> i & 1;	//��ʾȡx�ĵ�iλ����������ʲô
		if(!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
}

int Search(int x){
	int p = 0, res = 0;
	for(int i=30;i>=0;i--){
		int u = x >> i & 1;
		if(son[p][!u]){	//�����ǰ���ж�Ӧ�Ĳ���ͬ����
			p = son[p][!u]; //pָ���ҵ���ͬ���ĵ�ַ
			res = res * 2 + 1;	//*2�൱������һλ Ȼ���жϵ�ǰλ��ͬ������ ͬ+0 ��+1
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
