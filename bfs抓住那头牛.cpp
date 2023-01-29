//bfsץס��ͷţ
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
const int N = 2e5 + 10;

int n,k;
int dis[N]; 

int bfs(){
	memset(dis, -1 ,sizeof dis);
	queue<int> q;
	dis[n] = 0;
	q.push(n);
	
	while(!q.empty()){
		int t = q.front();
		q.pop();
		
		if(t == k) return dis[k];
		
		if(t + 1 < N && dis[t+1] == -1){ //t+1û��Խ����t+1û�߹�
			dis[t+1] = dis[t] + 1;
			q.push(t+1);
		}
		
		if(t - 1 >= 0 && dis[t-1] == -1){	//�����ƶ���������û������
			dis[t-1] = dis[t] + 1;
			q.push(t-1);
		}
		if(t * 2 < N && dis[t*2] == -1){
			dis[t*2] = dis[t] + 1;
			q.push(t*2);
		}
	}
	
	return -1;
}

int main(){
	cin >> n >> k;
	
	cout << bfs();
	
	return 0;
}
