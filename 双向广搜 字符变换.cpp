//双向奔赴广搜 用于最短步数优化
//字符变换
//https://www.acwing.com/problem/content/192/
#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>

using namespace std;
const int N = 6;

string a[N],b[N];
int n;

int extend(queue<string>& q,unordered_map<string,int>& da,unordered_map<string,int>& db,string a[],string b[]){
	string t = q.front();
	q.pop();
	
	for(unsigned int i=0;i<t.size();i++){ //枚举字符串
		for(int j=0;j<n;j++){	//枚举变换规则
			if(t.substr(i,a[j].size()) == a[j]){
			 // 变换之后的结果state:前面不变的部分+ 变化的部分 + 后面不变的部分
			// 比如abcd ，根据规则abc--> xu，变成 xud，这里的state就是xud
				string state = t.substr(0,i) + b[j] + t.substr(i+a[j].size());
				 // state状态是否落到b里面去，两个方向会师，返回最小步数
				if(db.count(state)) return da[t] + 1 + db[state];
				//如果扩展过了则继续
				if(da.count(state)) continue;
				da[state] = da[t] + 1; //步数+1
				q.push(state);
			}
		}
	}
	return 11;
}

int bfs(string A,string B){
	if(A == B) return 0; //特判
	
	queue<string> qa,qb; //两个方向的队列
	unordered_map<string,int> da,db; //每个状态到起点与终点距离
	
	qa.push(A); qb.push(B);
	da[A] = 0;	db[B] = 0;
	
	//qa与qb都有值，说明可以扩展，否则不相交
	while(qa.size() && qb.size()){
		int t; //记录最小步数
		//从队列长度较小的一队开始扩展
		if(qa.size() <= qb.size())
			t = extend(qa,da,db,a,b);
		else t = extend(qb,db,da,b,a); //从后往前时规则也应反过来
		
		if(t <= 10) return t;
	}
	return 11; //不连通或最小步数大于10
}

int main(){
	string A,B;
	cin >> A >> B;
	
	while(cin >> a[n] >> b[n]) n++; //读入规则
	
	int step = bfs(A,B);
	if(step > 10) cout << "NO ANSWER!";
	else cout << step << endl;
	
	return 0;
}
