#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 55;
int a[N];
int up[N],down[N];
int ans,n;

void dfs(int u,int su,int sd){
	if(su + sd >= ans) return; //��֦��˵�����ܼ������´𰸣�ֱ�ӷ���
	if(u == n){ //�ҵ�һ�ַ���������ans
		ans = su + sd;
		return;
	}
	//���1. ����ǰ����������������
	int k = 0;
	while(k < su && up[k] >= a[u]) k++;
	int t = up[k]; //���ݣ������Ժ�ָ��ֳ�
	up[k] = a[u];
	if(k < su) dfs(u+1,su,sd); // û�п����µ�����������
	else dfs(u+1,su+1,sd); //����һ���µ�����������
	up[k] = t; //�ָ��ֳ�
	//���2. ����ǰ�������½�������
	k = 0;
	while(k < sd && down[k] <= a[u]) k++;
	t = down[k];
	down[k] = a[u];
	if(k < sd) dfs(u+1,su,sd);
	else dfs(u+1,su,sd+1);
	down[k] = t;
	
}

int main(){
	
	while(cin >> n,n){
		for(int i=0;i<n;i++) cin >> a[i];
		
		ans = n; //ans��Ϊ��󣬼�ÿ������һ��ϵͳ��ans=n
		dfs(0,0,0); //��ǰö�ٵ��ĸ�������ǰ���������и�������ǰ�½������и���
		
		cout << ans << endl;
	}
	
	return 0;
}
