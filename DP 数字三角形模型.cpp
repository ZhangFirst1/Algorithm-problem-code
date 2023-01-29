//����������ģ��
//https://www.acwing.com/problem/content/1029/
//����·��ͬʱ����
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 15;
				  //��һά��ʾ��ǰ��������֮�ͣ�ֻ��i1+j1 == i2+j2ʱ����·���ſ������ Ҳ�������Ϊ�ܲ���
int f[N*2][N][N]; //f[k][i1][i2]��ʾ����(1,1) (1,1)��(i,k-i) (i2,k-i2)·�������ֵ
int w[N][N],n;

int main(){
	cin >> n;
	int a,b,c;
	while(cin >> a >> b >> c,a||b||c) w[a][b] = c;
	
	for(int k=2;k<=n+n;k++)
		for(int i1=1;i1<=n;i1++)
			for(int i2=1;i2<=n;i2++){
				int j1 = k - i1, j2 = k - i2;
				if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n){ //�ж��Ƿ�Խ��
					int t = w[i1][j1]; //ͬһ���һ��
					if(i1 != i2) t += w[i2][j2]; //�ܲ�����ͬ��i1��i2��ͬ��˵����ͬһ�� ֻ��һ�Σ������ټ�һ��
					f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2-1] + t); //����
					f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2] + t); //����
					f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2-1] + t); //����
					f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2] + t); //����
				}
			}
	
	cout << f[n+n][n][n] << endl;
	return 0;
}
