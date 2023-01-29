/*dfs��֦
1.�Ż�����˳��
	����������֧������С�Ľڵ�
2.�ų���Ч����
	������˳�����������������
3.�����Լ�֦
	�ѵ����Ϸ�ֱ�ӷ���
4.�����Լ�֦
	��ǰ���������������Ž�ֱ���˳�
5.���仯����(DP)
*/
	
//èè��ɽ
//�����ϵ��³���������Ϊ W���� N ֻСè�������ֱ��� C1��C2����CN

#include<iostream>
#include<algorithm>

using namespace std;
const int N = 20;

int a[N],sum[N];
int n,m;
int ans = N;
//��uֻèè����k����
void dfs(int u,int k){
	if(k >= ans) return; //�����Լ�֦
	if(u == n){
		ans = k;
		return;
	}
	
	for(int i=0;i<k;i++){
		if(sum[i] + a[u] <= m){ //�����Լ�֦
			sum[i] += a[u];
			dfs(u+1,k);
			sum[i] -= a[u]; //�ָ��ֳ�
		}
	}
	
	sum[k] = a[u]; //�¿�һ����
	dfs(u+1,k+1);
	sum[k] = 0; //�ָ��ֳ�
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	
	//�Ż�����˳��
	//�Ӵ�С��ʼ��èè
	sort(a,a+n);
	reverse(a,a+n);
	
	dfs(0,0);
	
	cout << ans;
	
	return 0;
}
