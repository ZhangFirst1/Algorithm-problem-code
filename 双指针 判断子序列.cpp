//˫ָ�� �ж�������
#include<iostream>

using namespace std;
const int N = 100010;
//�ж�a�Ƿ�Ϊb��������
int a[N],b[N];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int j=0;j<m;j++) cin >> b[j];
	//iɨ��a���飬ƥ��ɹ���������ƶ�
	//jɨ��b���飬���������ƶ�
	int i = 0;
	for(int j=0;j<m;j++){
		if(i < n && a[i] == b[j]) i++;
	}
	if(i == n) cout << "Yes";
	else cout << "No";
	
	return 0;
}
