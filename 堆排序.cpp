//������
#include<iostream>

using namespace std;
const int N = 100010;

int n,m;
int size,h[N];

void down(int u){
	int t = u;	//t��ʾ���ڵ����ӽڵ����Сֵ���±�
	
	if(u*2 <= size && h[u*2] <= h[t]) t = u*2;
	if(u*2+1 <= size && h[u*2+1] <= h[t]) t = u*2+1;
	
	if(u != t){	//��Сֵ��u���ӽڵ�
		swap(h[t],h[u]);	
		down(t);	//����down�ӽڵ� 
	}
}

void up(int u){	
	if(u/2 > 0 && h[u/2] > h[u]){	//������ڵ�����Ҹ��ڵ�����ӽڵ�
		swap(h[u/2],h[u]);
		u /= 2;
	}
}

int main(){			
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> h[i];
	size = n;
	
	for(int i=n/2;i>0;i--) down(i);	//������(��n/2��ʼdown,��ΪҶ�ӽڵ�һ������ѵ�����)
	//for(int i=1;i<=n/2;i++) down(i); �����ԴӸ��ڵ㿪ʼdown����Ϊdown�����������㣺���Ҷ�������ѵ�����
	
	for(int i=1;i<=m;i++){
		cout << h[1] << ' ';
		
		h[1] = h[size--];	//�����ɾ���Ѷ�
		down(1);
	}
	
	
	return 0;
}
