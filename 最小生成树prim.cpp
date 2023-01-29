//��С��������Prim
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5050;

struct edge{
	int next,to,w;
}edge[500000];
int head[N],cnt,ans,n,m,dis[N],sum_bian,now=1;	//dis[n]��ʾn�㵽�����еľ���
bool vis[N];

void add(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int prim(){
	for(int i=1;i<=n;i++) dis[i] = INF;
	dis[now] = 0;
	for(int i=head[1];i;i = edge[i].next)
		dis[edge[i].to] = min(dis[edge[i].to],edge[i].w);//ȥ�ظ���
	
	while(++sum_bian < n){
		int minn = INF;
		vis[now] = 1;
        //ö��ÿһ��û��ʹ�õĵ�
        //�ҳ���Сֵ��Ϊ�±�
        //ע�����ﲻ��ö��now����������ߣ�����1~n		
	    for(int i=1;i<=n;i++){
			if(!vis[i] && minn > dis[i]){
				minn = dis[i];
				now = i;
			}
		}
		if(minn == INF) return INF;		//���û�ҵ���̱��򷵻أ����ж��Ƿ������С������
		ans += minn;
        //�����¼���Ľڵ�now��δ������С�������ĵ�����ɳ�
		for(int i=head[now]; i ;i = edge[i].next){
			int to = edge[i].to;
			if(dis[to] > edge[i].w && !vis[to])
				dis[to] = edge[i].w;
		}
			
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	
	if(prim() == INF)
		cout << "orz";
		else
		cout << ans;
	
	return 0;
}
