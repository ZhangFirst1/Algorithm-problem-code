//���
//����һ������Ϊ n ���������С�
//���������� m ��������ÿ������������������ l,r,c����ʾ�������� [l,r] ֮���ÿ�������� c��
#include<iostream>

using namespace std;
const int N = 1e5+10;

int a[N],b[N];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i] - a[i - 1]; //����������
	}
	
	int l,r,c;
	while(m--){
		cin >> l >> r >> c;
		b[l] += c; 		//������a[l]֮�󶼼���c
		b[r+1] -= c; 	//������a[r+1]֮�󶼼�ȥc
						//����a[l,r]֮��ÿ��������c
	}
	
	for(int i=1;i<=n;i++){
		a[i] = a[i-1] + b[i];	//ǰ׺������
		cout << a[i] << ' ';
	}	
	
	return 0;
}
