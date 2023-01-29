//牛的旅行
//https://www.luogu.com.cn/problem/P1522
//1.用floyd求出任意两点间的距离
//2.求maxd[i],表示和i联通且距离i最远的点的距离
//3.情况1：所有maxd[i]的最大值
//	情况2：枚举在哪两个点之间连边。i，j需要满足d[i,j] = INF。 maxd[i] + dist[i,j] + maxd[j]
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
				if(g[i][j] == '1') dis[i][j] = get_dis(q[i],q[j]); //如果之间有边，dis等于两点直线距离
				else dis[i][j] = INF;
			}
	
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	
	//表示和i联通且离i最远的点的距离
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(dis[i][j] < INF)
				maxd[i] = max(maxd[i],dis[i][j]);
		}	
	
	double res1 = 0;
	for(int i=0;i<n;i++) res1 = max(res1, maxd[i]); //情况1
	double res2 = INF;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(dis[i][j] >= INF) //不连通
				res2 = min(res2, get_dis(q[i],q[j]) + maxd[i] + maxd[j]);
	
	printf("%lf\n",max(res1,res2));
	
	return 0;
}
