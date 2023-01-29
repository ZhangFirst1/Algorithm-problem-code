//木棍
//将几个数分为几组，保证组内数字和相等，求最小和
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 70;

int n,sum,len;
int w[N];
bool st[N];

//u表示第几跟长木棍，s表示当前木棍长度，start表示第u组枚举位置
bool dfs(int u,int s,int start){
	if(u * len == sum) return true; //如果总长度为sum则返回
	if(s == len) return dfs(u+1,0,0); //true返回时要连续
	
	for(int i=start;i < n;i++){
		if(st[i]) continue;
		if(s + w[i] > len) continue; //可行性剪枝
		
		st[i] = true;
		if(dfs(u, s+w[i], i + 1)) return true;
		st[i] = false; //恢复现场
		
		if(!s || w[i] + s == len) return false; //如果第一根或最后一根失败，则一定失败 
		
		int j = i; //如果i失败，则和i长度一样的也会失败
		while(j <= n && w[j] == w[i]) j++;
		i = j- 1;
	}
	
	return false;
}

int main(){
	while(cin >> n , n){
		memset(st,0,sizeof st);
		sum = 0, len = 1; 
		
		for(int i=0;i<n;i++){
			cin >> w[i];
			sum += w[i];
		}
		
		sort(w,w+n); //优化顺序剪枝
		reverse(w,w+n);
		
		while(1){ //枚举木棍长度
			if(sum % len == 0 && dfs(0,0,0)){ //整除才能分，剪枝1
				cout << len << endl;
				break;
			}
			len++;
		}
	}
	
	return 0;
}
