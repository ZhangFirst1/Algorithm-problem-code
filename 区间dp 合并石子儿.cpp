//ʯ�Ӷ��ϲ�
//����dp����һάö�����䳤�ȣ�һ��len=1��ʼ����ö�ٴ�len=2��ʼ���ڶ�άö�����i���Ҷ˵�j = i + len -1�� 
#include<iostream>

using namespace std;
const int N = 400;

int a[N],s[N]; //��ǰ׺������ϲ��Ĵ���
int dp[N][N]; //dp[i][j]��ʾ��i��j�ϲ���һ�ѵķ����ļ���

int main(){
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	
	//����dpö�٣����ȼ���˵�
	for(int len = 1;len < n;len++){	//len��ʾi��j���±�Ĳ�ֵ
		for(int i = 1;i+len <= n;i++){ //ö����˵�
			int j = i + len;//�Ҷ˵�
			dp[i][j] = 0x3f3f3f3f;
			for(int k = i;k <= j-1;k++){ //ö�ٷָ�㣬������k+1 <= j
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + s[j] - s[i-1]);
			}
		}
	}
	
	cout << dp[1][n];
	return 0;
}
