//˫ָ�� ����Ԫ�ص�Ŀ���
#include<iostream>

using namespace std;
const int N = 100010;

int a[N],b[N];

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=m;i++) cin >> b[i];
	
	for(int i=1,j=m;i<=n;i++){	//����Ϊ����jָ�벻�����
		while(j >= 1 && a[i] + b[j] > k) j--;
		if(j >= 1 && a[i] + b[j] == k) cout << i-1 << ' ' << j-1; 
	}
	
	return 0;
}
