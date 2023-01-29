#include<iostream>
#include<cstring>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 510;

int map_dis[N][N],map_time[N][N];
int n,m,start,ed;
int disl[N],dist[N];
int sumNode[N],sumNodeTime[N],preNodeDis[N],preNodeTime[N];
bool vis[N];

void dijkstraL(){
	memset(vis,0,sizeof vis);
	for(int i=0;i<n;i++){
		preNodeDis[i] = i;
		disl[i] = INF;
		sumNode[i] = 0;
	}
	disl[start] = 0;
	for(int i=0;i<n;i++){
		int now = start, minn = INF;
		for(int j=0;j<n;j++){
			if(disl[j] < minn && !vis[j]){
				now = j;
				minn = disl[j];
			}
		}
		vis[now] = 1;
		
		for(int j=0;j<n;j++){
			if(!vis[j] && disl[now] + map_dis[now][j] < disl[j]){
				disl[j] = disl[now] + map_dis[now][j];
				sumNode[j] = sumNode[now] + 1;
				preNodeDis[j] = now;
			}else if(!vis[j] && disl[now] + map_dis[now][j] == disl[j]){
				if(sumNode[j] > sumNode[now] + 1){
					sumNode[j] = sumNode[now] + 1;
					preNodeDis[j] = now;
				}
			}	
		}	
	}  	
}

void dijkstraT(){
	memset(vis,0,sizeof vis);
	for(int i=0;i<n;i++){
		preNodeTime[i] = i;
		dist[i] = INF;
		sumNodeTime[i] = 0;
	}
	dist[start] = 0;
	for(int i=0;i<n;i++){
		int now = start, minn = INF;
		for(int j=0;j<n;j++){
			if(dist[j] < minn && !vis[j]){
				now = j;
				minn = dist[j];
			}
		}
		vis[now] = 1;
		
		for(int j=0;j<n;j++){
			if(!vis[j] && dist[now] + map_time[now][j] < dist[j]){
				dist[j] = dist[now] + map_time[now][j];
				sumNodeTime[j] = sumNodeTime[now] + map_dis[now][j];
				preNodeTime[j] = now;
			}else if(!vis[j] && dist[now] + map_dis[now][j] == dist[j]){
				if(sumNodeTime[j] > sumNodeTime[now] + map_dis[now][j]){
					sumNodeTime[j] = sumNodeTime[now] + map_dis[now][j];
					preNodeTime[j] = now;
				}
			}	
		}	
	}  	
}

void printPath(int pre[],int u){
	if(u == start) return;
	else printPath(pre,pre[u]);
	printf(" %d =>",pre[u]);
}

bool cmp(int predis,int pretime){
	if(predis != pretime) return false;
	else if(predis == pretime && pretime == start) return true;
	return cmp(preNodeDis[predis],preNodeTime[pretime]);
}

int main(){
	memset(map_dis, INF ,sizeof map_dis);
	memset(map_time, INF, sizeof map_time);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v,flag,l,t;
		cin >> u >> v >> flag >> l >> t;
		map_dis[u][v] = l;
		map_time[u][v] = t;
		if(flag == 0){
			map_dis[v][u] = l;
			map_time[v][u] = t;
		}
	}
	cin >> start >> ed;
	dijkstraL();
	dijkstraT();
	
	if(cmp(ed,ed)){
		printf("Time = %d; Distance = %d:",dist[ed],disl[ed]);
		printPath(preNodeDis,ed);
		cout << ' ' << ed << endl;
	}else{
		printf("Time = %d:",dist[ed]);
		printPath(preNodeTime,ed);
		cout << ' ' << ed <<endl;
		printf("Distance = %d:",disl[ed]);
		printPath(preNodeDis,ed);
		cout << ' ' << ed << endl;
	}

	return 0;
}
