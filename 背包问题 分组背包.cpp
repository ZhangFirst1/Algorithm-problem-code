//�������� ���鱳��
#include<iostream>

using namespace std;
const int N = 110;

int v[N][N],w[N][N],s[N];
int dp[N];	//ֻ��ǰi����Ʒ��ѡ����ǰ���С�ڵ���j�����ֵ

int main(){
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){ //����ÿ����Ʒ�ļ�ֵ�����
		cin >> s[i];	   //s[i]��ʾi����Ʒ�ĸ���
		for(int j=0;j<s[i];j++)   //��0��ʼ
			cin >> v[i][j] >> w[i][j];
	}
	
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)	//����֤ÿ��ֻѡһ��
			for(int k=0;k < s[i];k++)
				if(v[i][k] <= j)
					dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);	
			
	cout << dp[m] << endl;
	
	return 0;
}
