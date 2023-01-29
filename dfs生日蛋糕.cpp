#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N = 25, INF = 0x3f3f3f3f;

int n,m;
int minv[N],mins[N];
int R[N],H[N];
int ans = INF;

void dfs(int u,int v,int s){
	if(v + minv[u] > n) return; //��ǰ�����������ȡ��С����Ѿ�����n����֦
	if(s + mins[u] >= ans) return; //��ǰ�����������ȡ��С������ڵ���ans��˵�������޷��ı���Сֵ����֦
	if(s + 2 * (n-v) / R[u+1] >= ans) return; //�ƹ�ʽ��֦�Ż�
		
	if(!u){ //�������в�
		if(v == n) ans = s;
		return;
	}
	
	//��С���ܵ���u(�±߻���u-1��)������ܳ��������ǲ�뾶-1 �� sqrt(����� - �������)
	for(int r = min(R[u+1] - 1, (int)sqrt(n - v)); r >= u; r--) //�Ӵ�Сö��
		for(int h = min(H[u+1] - 1, (n-v)/r/r); h >= u;h--){
			int t = 0;
			if(u == m) t = r*r; //�����ײ㣬����������
			R[u] = r, H[u] = h;
			dfs(u-1,v + r*r*h, s + 2*r*h + t);
		}	
	
	
	
}

int main(){
	cin>> n >> m;
	
	for(int i=1;i<=m;i++){
		minv[i] = minv[i-1] + i*i*i;
		mins[i] = mins[i-1] + 2*i*i;
	}
	
	R[m+1] = H[m+1] = INF;
	
	dfs(m,0,0);
	
	if(ans == INF) cout << '0'; //ansδ������˵���޽�
	else cout << ans;
	
	return 0;
}
