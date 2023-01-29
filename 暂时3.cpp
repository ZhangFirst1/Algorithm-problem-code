//ͼ��bfs
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int N = 100010;

int ne[N],e[N],h[N],idx;
int dis[N];
int n,m;
bool st[N];

void add(int a,int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
	memset(dis,-1,sizeof dis);
	queue<int> q;
	q.push(1);
	dis[1] = 0; 
	while(!q.empty()){
		int t = q.front();
		q.pop();
		cout << "��ǰ�ڵ�Ϊ" << t << endl;
		for(int i=h[t];i!=-1;i = ne[i]){
			int j = e[i];
			
			if(dis[j] == -1){
				dis[j] = dis[t] + 1;
				q.push(j);
			}	
		}
	}
//	cout << dis[n];
}

void dfs(int u){
	st[u] = true;
	cout << "��ǰ�ڵ�Ϊ" << u << endl;
	for(int i=h[u];i!=-1;i=ne[i]){	
		int j = e[i];
		//cout << "��ǰ�ڵ�Ϊ" << j << endl;
		if(!st[j]){
			dfs(j);
		}
	}
}


int main(){
	cin >> n >> m;
	memset(h,-1,sizeof h);
	for(int i=1;i<=m;i++){
		int a,b;
		cin >> a >> b;
		add(a,b);
	}
	cout << "dfs˳��:" << endl;
	dfs(1);
	cout << "bfs˳��:" << endl;
	bfs();
	
	return 0;
}
