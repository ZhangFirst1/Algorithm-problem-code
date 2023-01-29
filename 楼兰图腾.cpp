#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 2000010;
typedef long long LL;

int n;
int a[N],t[N];
int Lower[N],Greater[N];

int lowbit(int x){
	return x & -x;
}
//�����е�x��������k
void add(int x,int k){
	for(int i=x; i<=n ;i += lowbit(i)) t[i] += k;
}
//��ѯ����ǰx�����ĺ�
int ask(int x){
	int sum = 0;
	for(int i=x;i;i -= lowbit(x)) sum += t[i];
	return sum;
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	//�������ң�����ͳ��ÿ��λ����߱ȵ�i����yС�����ĸ������Լ�������ĸ���
	for(int i=1;i<=n;i++){
		int y = a[i];
		//��ǰ���Ѽ�����״�������������ͳ������[1,y-1]�����ֳ��ֵĴ���
		Lower[i] = ask(y-1);
		//ͳ������[y+1,n]
		Greater[i] = ask(n) - ask(y);
		//��y������״���飬��y����1��
		add(y,1);
	}	
	memset(t,0,sizeof t);
	int resA = 0,resV = 0;
	//��������ͳ��
	for(int i=n;i>=1;i--){
		int y = a[i];
		resA += (LL)Lower[i] * ask(y-1);
		resV += (LL)Greater[i] * (ask(n) - ask(y-1));
		add(y,1);
	}
	cout << resA << ' ' << resV;
	return 0;
}
