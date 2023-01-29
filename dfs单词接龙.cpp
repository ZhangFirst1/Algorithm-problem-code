#include<iostream>
#include<cstring>

using namespace std;
const int N = 30;

int g[N][N]; //存两个单词的最小公共部分
string word[N];
int cnt,n;
int used[N];

void dfs(string dragon,int last){
	cnt = max(cnt, (int)dragon.size());
	
	used[last]++;
	for(int i=0;i<n;i++)
		if(g[last][i] && used[i] < 2)
			dfs(dragon + word[i].substr(g[last][i]),i);	
	
	used[last]--;
}

int main(){
	char s;
	cin >> n;
	for(int i=0;i<n;i++) cin >> word[i];
	cin >> s;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(unsigned k=1;k<min(word[i].size(),word[j].size());k++){
				if(word[i].substr(word[i].size()-k,k) == word[j].substr(0,k)){
					g[i][j] = k;
					break;
				}
			}
		}	
	}
	
	for(int i=0;i<n;i++)
		if(word[i][0] == s)
			dfs(word[i],i);
	
	cout << cnt;
	return 0;
}
