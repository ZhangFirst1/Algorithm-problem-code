//�����������
#include<iostream>

using namespace std;
const int N = 1010;

int n;
int f[N],w[N];	//f[i]��ʾ�ӵ�һ�����ֵ�w[i]��β������������еĳ���

int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> w[i];
	
	int maxn = 1; //�ҳ��������f[i]�е����ֵ
	for(int i=1;i<=n;i++){
		f[i] = 1; //�Ҳ���ǰ�߸�С��������Ϊ1
		for(int j=1;j<i;j++){
			if(w[i] > w[j])
				f[i] = max(f[i], f[j]+1); //ȡf[i]��f[j]����w[i](��+1)����
		}
		maxn = max(maxn,f[i]); //���ָ��¿���û��֮ǰ�Ĵ�
	}
	
	cout << maxn;
	return 0;
}
