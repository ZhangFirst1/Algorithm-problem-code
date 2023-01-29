#include<iostream>

using namespace std;
const int N = 25;

int col[N],dg[N],udg[N],n;
char a[N][N];

void dfs(int u){
	if(u == n){
		for(int i=0;i<n;i++)
			puts(a[i]);
		cout << endl;
	}
	
	for(int i=0;i<n;i++){
		if(!col[i] && !dg[u + i] && !udg[-u+i+n]){
			a[u][i] = 'Q';
			col[i] = dg[u + i] = udg[-u + i + n] = 1;
			dfs(u+1);
			col[i] = dg[u + i] = udg[-u + i + n] = 0;
			a[u][i] = '.';
		}
		
	}
	
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j] = '.';
	
	dfs(0);
	
	return 0;
}
