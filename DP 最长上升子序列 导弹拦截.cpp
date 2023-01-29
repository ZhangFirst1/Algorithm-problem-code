//���ص���
//https://www.acwing.com/problem/content/1012/
//dp+̰�� �����ٵ��½������и���ԭ����
//�ڶ��ʣ����ڵ�i�ŵ�����Ҫôѡ��ĩβ�����߶���С������ϵͳ��Ҫô����һ���µģ�
//��һ�����ּ�ÿ������ϵͳ��ʱ�����ص����һ�������߶ȣ�����ʾ��ϵͳ��
//�����͵õ���һ�����飬�������ճ��Ⱦ���������������ϵͳ��Ŀ��
#include<iostream>
#include<cstring>

using namespace std;
const int N = 1010;
int a[N],f[N],g[N];
int n;

int main(){
	while(cin >> a[n]) n++;
	
	int ans = 0;
	for(int i=0;i<n;i++){
		f[i] = 1;
		for(int j=0;j<i;j++){
			if(a[j] >= a[i]) f[i] = max(f[i], f[j]+1);
		}
		ans = max(ans,f[i]);
	}	
	cout << ans << endl;
	
	int cnt = 0; //cnt��ʾ���鳤�ȣ�����ǰ�����и���
	for(int i=0;i<n;i++){
		int k = 0;
		while(k < cnt && g[k] < a[i]) k++; //��ǰ���н�βС�ڵ�ǰ�������������ز��˵�ǰ������ϵͳ
		g[k] = a[i]; //�滻�ɸ�С����,������һ������ϵͳ���ص���
		if(k >= cnt) cnt++;  //û���κ�һ�����д��ڵ��ڵ�ǰ������һ���µ�����	
	}
	
	cout << cnt << endl;
	return 0;
}
