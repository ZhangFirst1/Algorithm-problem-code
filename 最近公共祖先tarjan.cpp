//��ûд�� д�����ɾ������
//�����������
//��������rarjan  O(n+m)
//��dfs�н����е��Ϊ������
//1.�Ѿ��������һ��ݹ�
//2.���������ķ�֧
//3.��δ�������ĵ�
//��������
//1.��ѡһ����Ϊ���ڵ㣬�Ӹ��ڵ㿪ʼ��
//2.�����õ�u�����ӽڵ�v���������Щ�ӽڵ�v�ѱ����ʹ���
//3.����v�����ӽڵ㣬����2��������һ����
//4.�ϲ�v��u�ϡ�
//5.Ѱ���뵱ǰ��u��ѯ�ʹ�ϵ�ĵ�v��
//6.����v�Ѿ������ʹ��ˣ������ȷ��u��v�������������Ϊv���ϲ����ĸ��׽ڵ�a
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
typedef pair<int,int> PII;
const int N = 20010, M = 2*N;

int n, m;
int h[N], ne[M], e[M], idx, w[M];
vector<PII> query[N]; //first�洢��ѯ�ĵ㣬 second�洢��ѯ���
int res[N], dis[N];
int fa[N];	//���鼯
int st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void dfs(int u,int p){
	for(int i=h[u];i != -1;i = ne[i]){
		int j = e[i];
		if(j == p) continue;
		dis[j] = dis[u] + w[i]; //����
		dfs(j,u);
	}
}

void tarjan(int u){
	st[u] = 1;
	for(int i=h[u];i != -1;i = ne[i]){
		int j = e[i];
		if(!st[j]){
			tarjan(j);
			fa[j] = u;	//�ϲ������ڵ�
		}
	}
	//û���ӽڵ��˲�ѯ�͵�ǰ����ѯ�ʹ�ϵ�ĵ�
	for(auto item:query[u]){
		int y = item.first;
		int id = item.second;
		if(st[y] == 1){
			int anc = find(y);	//ancΪ����lca
			res[id] = dis[u] + dis[y] - 2*dis[anc];
		}
	}
	
	//st[u] = 2;
}

int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i=1;i<n;i++){
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c); add(b,a,c);
	}
	//a��b�ľ��� = dis[a] + dis[b] - 2dis[lca(a,b)]
	for(int i=1;i<=m;i++){
		int a, b;
		scanf("%d%d",&a,&b);
		if(a != b){		//a��b���resΪ0
			query[a].push_back({b,i});
			query[b].push_back({a,i});
		} 
	}
	
	for(int i=1;i<=n;i++) fa[i] = i; //���鼯��ʼ��
	
	dfs(1, -1); //��ÿ����͵�һ����ľ���
	tarjan(1);	//�����һ���㵱���ڵ�
	
	for(int i=1;i<=m;i++) cout << res[i] << endl;
	
	return 0;
}
