#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 210;

int n;
int w[N][N];
int dis[N];
bool st[N];

int prim(){
	int res = 0;
	memset(dis, 0x3f ,sizeof dis);
	dis[1] = 0;
	
	for(int i=1;i<=n;i++){
		int t = -1;
		for(int j=1;j<=n;j++){
			if(!st[j] && (t == -1 || dis[j] < dis[t]))
				t = j;	
		}
		
		res += dis[t];
		st[t] = true;
		
		for(int j = 1;j <= n;j++) dis[j] = min(dis[j], w[t][j]);
		
	}

	return res;
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> w[i][j];
	
	cout << prim() << endl;
	
	return 0;
}
