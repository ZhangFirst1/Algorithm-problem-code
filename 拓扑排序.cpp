//拓扑排序
//每次删除一个入度为 0 的点，并刷新其他点的入度边个数。
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int N = 100010;

int ne[N],e[N],h[N],idx;
int cnt,d[N],top[N];	//top是拓扑排序,d为入度,cnt记录top中有多少元素
int n,m;

void add(int a,int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort(){
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(d[i] == 0)
			q.push(i); //将所有入度为0的点入队
	
	while(q.size()){
		int t = q.front();
		top[++cnt] = t;
		q.pop();
		
		for(int i=h[t];i != -1;i = ne[i]){
			int j = e[i];
			d[j]--;	//j的入度--
			if(d[j] == 0) q.push(j);
		}
	}
	if(cnt == n) return true;
	return false;
}

int main(){
	cin >> n >> m;
	memset(h,-1,sizeof h);
	
	while(m--){
		int a,b;
		cin >> a >> b;
		add(a,b);
		d[b]++;
	}
	
	if(topsort() == 0) cout << "-1" ;
	else{
		for(int i=1;i<=n;i++)
			cout << top[i] << ' ';
	}	
	
	
	return 0;
}
