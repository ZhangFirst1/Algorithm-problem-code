//SPFA�㷨
//ע�⣺���жϸ�����1��n��������ͼ���Ƿ����
//���ж�ͼ���Ƿ���ڣ������ʱ�����е����
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 100010;

int head[N],cnt;
struct edges{
	int to,next,w;
}edge[N];
int n,m;
int dis[N],outqueue[N]; //outqueue��ʾ���Ӵ������������жϸ���
bool st[N];	//��ʾ��ǰ�Ѿ����������µĵ㣬��dijkstra��ͬ��SPFA��st�����ǿ����

void add(int x,int y,int z){
	edge[++cnt].to = y;
	edge[cnt].w = z;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

int SPFA(){
	queue<int> q;
	memset(dis, 0x3f , sizeof dis);
	dis[1] = 0;
	q.push(0);
	st[1] = true;
	//�ж�ͼ���Ƿ���ڸ���
	/*for(int i=1;i<=n;i++){
		q.push(i);
		st[i] = true;
	}
	*/
	
	while(q.size()){
		int ver = q.front();
		q.pop();
		st[ver] = false; //�Ӷ���ȡ����t�ڵ��ʾΪfalse���˺�����������¿��ٴ����
		outqueue[ver]++;
		if(outqueue[ver] > n) return 0;//���Ӵ�������n����ڸ���
		
		for(int i=head[ver]; i != 0; i = edge[i].next){
			int to = edge[i].to;
			if(dis[to] > dis[ver] + edge[i].w){
				dis[to] = dis[ver] + edge[i].w;
				if(!st[to]){//��ǰ�Ѿ�������еĽ�㣬�����ٴμ�����У����㷢���˸���Ҳֻ�ø�����ֵ���ɣ��ظ���ӽ���Ч��
					st[to] = true;
					q.push(to);
				}
			}
		}
		
	}
	if(dis[n] == 0x3f3f3f3f) cout << "impossible";	//��bellman��ͬ���������ͨ�򲻻���£�����INF
	else cout << dis[n];
	
	return 1;
}

int main(){
	cin >> n >> m;
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
	}
	
	if(SPFA()) cout << "�޸���";
	else cout << "���ڸ���";
	
	return 0;
}

