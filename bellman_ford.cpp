//bellman_ford �б������Ƶ����·	
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int N = 100010;

struct edges{
	int a,b,w;
}edge[N];
int dis[N];
int back[N];	//���������ֹ����
int n,m,k;	//k��ʾ���·����������������

void bellman_ford(){
	memset(dis,0x3f, sizeof dis);
	dis[1] = 0;
	for(int i=1;i<=k;i++){	//k��ѭ��
		memcpy(back,dis,sizeof dis);
		for(int j=1;j<=m;j++){ //�������б�
			int a = edge[j].a, b = edge[j].b, w = edge[j].w;
			dis[b] = min(dis[b],back[a] + w);	//�����ֽڵ���µľ��������´��ֽڵ㣬�ɱ��⴮��
		}	
	}
	if(dis[n] > 0x3f3f3f3f / 2) cout << "impossible"; //���߸��º������С
	else cout << dis[n];
	
}

int main(){
	cin >> n >> m >> k;
	
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		edge[i] = {a,b,c};
	}
	
	bellman_ford();

	
	return 0;
}
