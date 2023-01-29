#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>

using namespace std;

int dy[] = {-1,0,0,1};
int dx[] = {0,-1,1,0};

int bfs(string start){
	string ed = "12345678x";
	queue<string> q;
	unordered_map<string ,int > ans;
	q.push(start);
	ans[start] = 0;
	
	
	while(!q.empty()){
		string t = q.front();
		q.pop();
		int d = ans[t];
		if(t == ed) return ans[t];
		
		int px,py,k;
		for(int i=0;i<9;i++)
			if(t[i] == 'x')
				k = i,px = i/3,py =i%3; 
		
		for(int i=0;i<4;i++){
			int nx = px + dx[i];
			int ny = py + dy[i];
			if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
			
			swap(t[k],t[nx*3+ny]);
			
			if(!ans.count(t)){
				ans[t] = d + 1;
				q.push(t);
			}
			
			swap(t[k],t[nx*3+ny]);
		}
		
		
	}
	return -1;
}

int main(){
	string start;
	for(int i=0;i<9;i++){
		char c;
		cin >> c;
		start += c;
	}
	
	cout << bfs(start);
	
	return 0;
}
