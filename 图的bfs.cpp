//Í¼µÄbfs
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int N = 100010;

int ne[N],e[N],h[N],idx;
int dis[N];
int n,m;

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
		
		for(int i=h[t];i!=-1;i = ne[i]){
			int j = e[i];
			if(dis[j] == -1){
				dis[j] = dis[t] + 1;
				q.push(j);
			}	
		}
	}
	cout << dis[n];
}

int main(){
	cin >> n >> m;
	memset(h,-1,sizeof h);
	for(int i=1;i<=m;i++){
		int a,b;
		cin >> a >> b;
		add(a,b);
	}
	
	bfs();
	
	return 0;
}
