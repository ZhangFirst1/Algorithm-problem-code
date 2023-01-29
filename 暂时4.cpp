#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 70;

int w[N],sum,n,len;
bool st[N];

bool dfs(int u,int s,int start){
	if(u * len == sum) return true;
	if(s == len) return dfs(u+1,0,0);
	
	for(int i=start;i<n;i++){
		if(st[i]) continue;
		if(w[i] + s > len) continue;
		st[i] = true;
		if(dfs(u,s+w[i],i+1)) return true;
		st[i] = false;
	
		if(!s || s+w[i] == len) return false;
		int j = i;
		while(w[i] == w[j] && j <= n) j++;
		i = j-1;
		
	}
	return false;
}

int main(){
	
	while(cin >> n, n){
		memset(st, 0 ,sizeof st);
		len = 1, sum = 0;
		for(int i=0;i<n;i++){
			cin >> w[i];
			sum += w[i];
		}
		
		sort(w,w+n);
		reverse(w,w+n);
		
		while(1){
			if(sum % len == 0 && dfs(0,0,0)){
				cout << len << endl;
				break;
			}
			len++;
		}	
	}
	return 0;
}
