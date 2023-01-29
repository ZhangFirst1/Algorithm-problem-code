//��С������ ͨѶ����
//https://www.acwing.com/problem/content/1147/
//�ҵ�һ����С��dֵ,ʹ����ɾȥȨֵ����d�����бߺ�,
//ʣ�µ���ͨ�����������k.
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N = 250000;

int n,m,k;
struct Edge{
	int a,b;
	double w;
	bool operator< (const Edge &t)const{
		return w < t.w;
	}
}edge[N];
PII q[N];
int fa[N];

double get_dis(PII a,PII b){
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

int main(){
	cin >> n >> k;
	for(int i=0;i<n;i++) fa[i] = i;
	for(int i=0;i<n;i++) cin >> q[i].x >> q[i].y;
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++) //����ͼ��ֻ����һ�����
			edge[m++] = {i,j,get_dis(q[i],q[j])};
	
	sort(edge,edge+m);
	int cnt = n; //��ͨ�����
	double res = 0;
	for(int i=0;i<m;i++){
		if(cnt <= k) break; 
		int a = find(edge[i].a), b = find(edge[i].b);
		if(a != b){
			fa[a] = b;
			cnt--; //�ϲ�һ����ͨ�����-1
			res = edge[i].w; //res����Ϊ��ǰ����
		}
	}
	
	printf("%.2lf",res);
	return 0;
}
