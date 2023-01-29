//���������������
//https://www.acwing.com/problem/content/274/

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 3010;

int n;
int a[N],b[N];
int f[N][N]; //�����ɵ�һ�����е�ǰi����ĸ���͵ڶ������е�ǰj����ĸ���ɵģ�����b[j]��β�Ĺ�������������

int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	
	for(int i=1;i<=n;i++){
		int maxv = 1; //1��ʾ�ռ����
		for(int j=1;j<=n;j++){
			f[i][j] = f[i-1][j]; //������a[i]�����
			if(a[i] == b[j]){ //����״̬����b[j],�������a[i]��Ҫa[i]��b[j]���
				f[i][j] = max(maxv,f[i][j]);	
			}
			if(b[j] < a[i]) maxv = max(maxv,f[i-1][j] + 1); 
		}	
	}
	int res = 0;
	for(int i=1;i<=n;i++) res = max(res,f[n][i]);
	
	cout << res << endl;
	return 0;
}
