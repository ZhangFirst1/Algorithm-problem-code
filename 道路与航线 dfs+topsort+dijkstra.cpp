//��·�뺽��
//��·���ţ�������������
//1.����������˫���·��dfs��������ͨ�飬����������
//id[]�洢ÿ���������ĸ���ͨ�飬vecrot<int> block[]�洢ÿ����ͨ��������Щ��
//2.�������к��ߣ�ͬʱͳ�Ƴ�ÿ����ͨ������
//3.������������ÿ����ͨ�顣�Ƚ��������Ϊ0����ͨ���������С�
//4.ÿ�δӶ�ͷȡ��һ����ͨ��ı��bid
//5.��block[bid]�����е������У��Զ������е���dijkstra
//6.ÿ��ȡ�����о�����С�ĵ�ver
//7.����ver�������ٵ�j����id[ver] == id[j],��ô���j�ܱ����£���j������У�
//���id[ver] != id[j]��id[j]�����ͨ�����ȼ�1�������Ϊ�㣬���������������Ķ�����
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
typedef pair<int,int> PII;
const int N = 150010,INF = 0x3f3f3f3f;

int n,mr,mp,s;
int head[N],cnt; 
int id[N],dis[N]; //id[]��ʾÿ���������ĸ���ͨ��
vector<int> block[N]; //ÿ����ͨ��������Щ��
int bcnt; //��ͨ��ĸ���
int din[N]; //ÿ����ͨ������
bool st[N];
struct Edge{
	int w,to,next;
}edge[N];
queue<int> q;

void add(int x,int y,int z){
	edge[++cnt].to = y;
	edge[cnt].w = z;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

void dfs(int u,int bid){
	id[u] = bid; //u�����ڱ��Ϊbid����ͨ��
	block[bid].push_back(u); //bid������а���u��
	
	for(int i = head[u]; i ; i = edge[i].next){
		int to = edge[i].to;
		if(!id[to]) dfs(to,bid); //�����ǰ�㻹û���������������dfs
	}
}

void dijkstra(int bid){
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	for(auto ver:block[bid]) heap.push({dis[ver],ver}); //������ͨ���е����е㲢�����
	
	while(!heap.empty()){
		auto t = heap.top();
		heap.pop();
		
		int ver = t.second;
		if(st[ver]) continue;
		st[ver] = true;
		
		for(int i=head[ver];i;i = edge[i].next){
			int to = edge[i].to;
			if(dis[to] > dis[ver] + edge[i].w){
				dis[to] = dis[ver] + edge[i].w;
				if(id[to] == id[ver]) heap.push({dis[to],to}); //����ٵ��뵱ǰ����ͬһ��ͨ�飬����Ѽ���dijkstra
			}
			//�������ͬһ��ͨ�飬˵����·Ϊ���ߣ�������ȣ������Ϊ0���������
			if(id[to] != id[ver] && --din[id[to]] == 0) q.push(id[to]); 	
		}
	}
}

void topsort(){
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	
	for(int i=1;i<=bcnt;i++)
		if(!din[i])
			q.push(i); 
	
	while(!q.empty()){
		int t = q.front();
		q.pop();
		
		dijkstra(t);
	}
}

int main(){
	cin >> n >> mr >> mp >> s;
	while(mr--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c); add(b,a,c);
	}
	//dfs������ͨ��
	for(int i=1;i<=n;i++)
		if(!id[i])
			dfs(i,++bcnt);
	//�������к���
	while(mp--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		din[id[b]]++; //b��������ͨ�����+1
	}
	
	topsort();
	
	for(int i=1;i<=n;i++)
		if(dis[i] > INF / 2) //���ڸ�Ȩ�ߣ���������ܸ�����������Сdis��ֵ
			cout << "NO PATH" << endl;
		else cout << dis[i] << endl;
	return 0;
}
