//ȫ����
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
		if(!st[i]){		//�������iû���ù�
			a[u] = i;	//�����λ
			st[i] = true;//���ֱ��ã��޸�״̬
			dfs(u+1);	//����һ��λ��
			st[i] = false;	//���ݣ�ȡ��i
		}
	}
	
}

int main(){
	cin >> n;
	dfs(1);
	
	return 0;
}
