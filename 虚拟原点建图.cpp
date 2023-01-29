//�����Ƹ��
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 110, INF = 0x3f3f3f3f;
int n,m;
int dis[N]; 
int g[N][N],level[N]; 
bool st[N];

int dijkstra(int down,int up){
	memset(st,0,sizeof st);
	memset(dis,0x3f,sizeof dis);
	
	dis[0] = 0;
	for(int i=0;i<=n;i++){
		int t = -1;
		for(int j=0;j<=n;j++){ //0�ŵ㣨����ԭ�㣩Ҳ��ͼ��
			if(!st[j] && (t == -1 || dis[j] < dis[t])) 
				t = j;	
		}
		st[t] = true;
		for(int j=1;j<=n;j++){ 
			if(level[j] >= down && level[j] <= up){
				if(!st[j] && dis[t] + g[t][j] < dis[j]){
					dis[j] = dis[t] + g[t][j];
				}
			}
		}
		
	}
	return dis[1];
}

int main(){
	cin >> m >> n;
	memset(g,0x3f,sizeof g); //��ʼ��
	for(int i=1;i<=n;i++) g[i][i] = 0;
	
	for(int i=1;i<=n;i++){
		int price,cnt;
		cin >> price >> level[i] >> cnt;
		g[0][i] = min(price,g[0][i]); //����ԭ���뵱ǰ������
		while(cnt--){
			int id,cost;
			cin >> id >> cost;
			g[id][i] = min(g[id][i],cost);
		}
	}
	
	int res = INF;
	for(int i=level[1]-m;i <= level[1];i++) //ö�ٵȼ����䣨Ҫ����1�ĵȼ���
		res = min(res, dijkstra(i, i+m)); //���н��ȡ��Сֵ
	
	return 0;
}
