#include<iostream>
#include<algorithm>

const int N = 10;
using namespace std;

int e[N][N],ans;
int fa[N];
bool st[N];

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void init() {
    e[1][2] = e[1][6] = 1;
    e[2][1] = e[2][3] = e[2][7] = 1;
    e[3][2] = e[3][4] = e[3][7] = 1;
    e[4][3] = e[4][5] = 1;
    e[5][4] = e[5][6] = e[5][7] = 1;
    e[6][1] = e[6][5] = e[6][7] = 1;
    e[7][2] = e[7][3] = e[7][5] = e[7][6] = 1;
}

void dfs(int u){
	if(u > 7){
		for(int i=1;i<=7;i++) fa[i] = i;
	
	for(int i=1;i<=7;i++){
		for(int j=1;j<=7;j++){
			if(st[i] && st[j] && e[i][j] == 1){
				if(find(i) != find(j))
					fa[find(i)] = find(j);
			}
		}
	}
	
	int cnt = 0;
	for(int i=1;i<=7;i++)
		if(fa[i] == i && st[i]) cnt++;
	if(cnt == 1) ans++;
	
		return;
	}
	st[u] = true;
	dfs(u+1);
	
	st[u] = false;
	dfs(u+1); 
	
}

int main(){
	init();
	dfs(1);
	cout << ans;
	return 0;
} 
