//01�������� ��ȫ��������
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 10010;

int v[N],w[N];
int dp[N]; //dp[i][j]��ʾ��ǰi����Ʒ����������j�µ����Ž�

//1.��ǰ������������(j < v[i])��û��ѡ��������Ž�Ϊǰi-1����Ʒ���Ž�
//dp[i][j] = dp[i-1][j];
//2.�������������Ƿ�ѡ���i����Ʒ
//ѡ��dp[i][j] = dp[i-1][j - v[i]] + w[i];
//��ѡ��dp[i][j] = dp[i-1][j];

void bag01(int n,int m){
	//״̬ת�Ʒ���dp[i][j] = max(dp[i-1][j], dp[i-1][j - v[i]] + w[i])
	for(int i=1;i<=n;i++)
		for(int j=m;j>=v[i];j--) //����ö�٣���Ϊj > j - v[i],��������ö��dp[j-v[i]]��i����ٴα�����
			dp[j] = max(dp[j] , dp[j - v[i]] + w[i]);	
			
	cout << dp[m] << endl;
}

void bagwanquan(int n,int m){
	//״̬ת�Ʒ���dp[i][j] = max(dp[i-1][j], dp[i][j - v[i]] + w[i])
	for(int i=1;i<=n;i++)
		for(int j=v[i];j<=m;j++) //����ö�ٿɴﵽdp[i][j - v[i]]��Ч��
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
			
	cout << dp[m] << endl;
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
	
	bag01(n,m);
	
	//bagwanquan(n,m);
	
	return 0;
}
