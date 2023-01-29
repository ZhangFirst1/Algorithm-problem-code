//https://www.acwing.com/problem/content/239/

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<cstring>

using namespace std;
const int N = 2000010;

int n,m;
int fa[N];
unordered_map<int,int> s;

struct Query{
	int x,y,e;
}query[N];

//非保序离散化
int get(int x){
	if(s.count(x) == 0) s[x] = ++n; //如果x在哈希表中未出现过，分配一个新值
	return s[x]; //返回x对应的值
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		n = 0;
		s.clear();
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int x,y,e;
			scanf("%d%d%d",&x,&y,&e);
			query[i] = {get(x),get(y),e};
		}
		
		for(int i=1;i<=n;i++) fa[i] = i;
		
		//合并所有相等约数条件
		for(int i=0;i<m;i++){
			if(query[i].e == 1){
				int pa = find(query[i].x), pb = find(query[i].y);
				fa[pa] = pb;
			}
		}
		//合并不等约数条件
		bool flag = false;
		for(int i=0;i<m;i++){
			if(query[i].e == 0){
				int pa = find(query[i].x), pb = find(query[i].y);
				if(pa == pb){
					flag = true;
					break;
				}
			}
		}
		if(flag) cout << "NO" << endl;
		else cout << "YES" << endl;
		
	}	
	
	return 0;
}
