//ţ������
//https://www.luogu.com.cn/problem/P1522
//1.��floyd������������ľ���
//2.��maxd[i],��ʾ��i��ͨ�Ҿ���i��Զ�ĵ�ľ���
//3.���1������maxd[i]�����ֵ
//	���2��ö������������֮�����ߡ�i��j��Ҫ����d[i,j] = INF�� maxd[i] + dist[i,j] + maxd[j]
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N = 160;
const double INF = 1e20;

int n;
char g[N][N];
PII q[N];
double dis[N][N],maxd[N];

double get_dis(PII a,PII b){
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> q[i].x >> q[i].y;
	for(int i=0;i<n;i++) cin >> g[i];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i != j){
				if(g[i][j] == '1') dis[i][j] = get_dis(q[i],q[j]); //���֮���бߣ�dis��������ֱ�߾���
				else dis[i][j] = INF;
			}
	
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	
	//��ʾ��i��ͨ����i��Զ�ĵ�ľ���
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(dis[i][j] < INF)
				maxd[i] = max(maxd[i],dis[i][j]);
		}	
	
	double res1 = 0;
	for(int i=0;i<n;i++) res1 = max(res1, maxd[i]); //���1
	double res2 = INF;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(dis[i][j] >= INF) //����ͨ
				res2 = min(res2, get_dis(q[i],q[j]) + maxd[i] + maxd[j]);
	
	printf("%lf\n",max(res1,res2));
	
	return 0;
}
