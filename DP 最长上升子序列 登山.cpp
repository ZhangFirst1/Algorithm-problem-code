//�����������ģ�� ��ɽ
//https://www.acwing.com/problem/content/1016/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1010;

int n;
int a[N];
int f[N],g[N]; //��kΪ�м�� �������ߵ������������ģ��

int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){ //��������Ԥ����f[i]
		f[i] = 1;
		for(int j=1;j<i;j++)
			if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
	}
	for(int i=n;i>=1;i--){ //��������Ԥ����g[i]
		g[i] = 1;
		for(int j=n;j>i;j--)
			if(a[i] > a[j]) g[i] = max(g[i], g[j] + 1);
	}
	
	int res = 0;
	for(int i=1;i<=n;i++) res = max(res, f[i] + g[i] - 1); //i����������� ����Ҫ��һ
	cout << res;
	return 0;
}
