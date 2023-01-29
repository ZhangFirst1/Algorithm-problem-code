//����һ������Ϊ N �����У�����ֵ�ϸ񵥵������������еĳ�����Ƕ��١�
//1 <= N <= 100000
#include<iostream>

using namespace std;
const int N = 100010;

int a[N],f[N]; //f[N]Ϊά���ĵ�������������
int cnt;

int find(int x){
	int l = 1 , r = cnt;
	while(l < r){
		int mid = (l+r)/2;
		if(f[mid] < x) l = mid + 1;
		else r = mid; 		
	}
	return l;
}

int main(){
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[++cnt] = a[1];
	for(int i=2;i<=n;i++){
		if(a[i] > f[cnt]) f[++cnt] = a[i]; //a[i]����f[cnt]�������f[]����
		else{
			int t = find(a[i]); //��a[i]���f�е�һ�����ڵ���a[i]����
			f[t] = a[i];
		}
	}
	
	cout << cnt;
	return 0;
}
