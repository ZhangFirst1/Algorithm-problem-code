//匈牙利算法 二分图的最大匹配
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 510,M = 100010;

int n1,n2,m,cnt,head[M];
struct edges{
	int to,next,w;
}edge[M];
int match[N]; //表示匹配关系
bool st[N];

void add(int x,int y){
	edge[++cnt].to = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

bool find(int x){
	for(int i=head[x]; i ;i = edge[i].next){
		int to = edge[i].to;
		if(!st[to]){	//该右侧元素未被访问过
			st[to] = true;
			if(match[to] == 0 || find(match[to])){	//如果暂无匹配，或者原来匹配的左侧元素可以找到新的匹配
				match[to] = x; //建立匹配关系
				return true;
			}
			
		}
	}
	return false;
}

int main(){
	cin >> n1 >> n2 >> m;
	while(m--){
		int a,b;
		cin >> a >>b;
		add(a,b);
	}
	
	int res = 0;
	for(int i=1;i<=n1;i++){
		memset(st, false ,sizeof st);
		if(find(i)) res++;
	}
	
	cout << res;
	return 0;
}
