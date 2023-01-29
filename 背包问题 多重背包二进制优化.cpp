//���ر�������Ķ������Ż�
#include<iostream>

using namespace std;
const int N = 20010;

int v[N],w[N];
int dp[N];

int main(){
	int n,m;
	cin >> n >> m;
	int cnt = 0;
	//�������Ż�
	for(int i=1;i<=n;i++){
		int a,b,s;
		cin >> a >> b >> s;
		int k = 1;
		while(k <= s){
			cnt++;
			v[cnt] = a * k; //��������ֵ����
			w[cnt] = b * k;
			s -= k;		//��ǰ��k������
			k *= 2;			
		}
		if(s > 0){
			v[++cnt] = a * s;
			w[cnt] = b * s;
		}
	}
	
	for(int i=1;i<=cnt;i++)
		for(int j=m;j>=v[i];j--)
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
	
	cout << dp[m] << endl;
	return 0;
}
