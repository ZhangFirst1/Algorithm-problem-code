/*A*算法
1.拿出队头并扩展元素
2.估计扩展元素到终点的距离
3.将扩展后的元素进行从小到大排序，并且小的作为队头

八数码https://www.acwing.com/solution/content/35528/
ps  1.估计距离要小于真实距离
	2.题目保证有解，否则O（logn）
	3.逆序对为奇数时一定无解
	4.终点出队后确定答案
*/

//超时了 改完删去这行注释
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_map>

#define x first
#define y second

using namespace std;
typedef pair<int,string> PIS;

int f(string m){	//估计函数
	int dt = 0;
	for(int i=0;i<9;i++){
		if(m[i] != 'x'){
			int t = m[i] - '1'; //对应下标
			dt = dt + abs(i/3 - t/3) + abs(i%3 - t%3); //曼哈顿距离（理想步数即为）
		}
	}
	return dt;
}

string bfs(string start){
	string end = "12345678x";
	
	unordered_map<string,int> d; //存储距离
	priority_queue<PIS, vector<PIS>, greater<PIS> > heap; // 将元素估计终点距离从小到大排序
	unordered_map<string, pair<string,char> > pre; //存储上一状态
	
	heap.push({f(start), start}); //加入起点
	d[start] = 0; //初始化起点距离
	
	char oper[] = "udlr";
	int dy[4] = {-1,0,0,1}; int dx[4] = {0,-1,1,0};
	
	while(heap.size()){
		auto t = heap.top();
		heap.pop();
		string state = t.y; //记录
		
		if(t.y == end) break; //终点出列则退出
		
		int aa,bb; //记录x的位置
		for(int i=0;i<=8;i++){
			if(state[i] == 'X'){
				aa = i / 3,bb = i % 3;
				break;
			}
		}
		
		string init = state;
		for(int i=0;i<4;i++){
			int a = aa + dx[i]; int b = bb + dy[i];
			if(a < 0 || a >=3 || b < 0 || b >= 3) continue;
			swap(state[a*3+b],state[aa*3+bb]); //交换下标位置
			if(!d.count(state)|| d[state] > d[init] + 1){ //没有被记录或小于记录值
				d[state] = d[init] + 1;
				heap.push({f(state) + d[state], state}); //加入堆中
				pre[state] = {init, oper[i]};// 标记由哪种状态转移来，并记录操作
			}
			state = init; //还原
		}	
	}
	
	string ans;
	while(end != start){
		ans += pre[end].y;
		end = pre[end].x;
	}
	reverse(ans.begin(),ans.end());
	
	return ans;
	
}


int main(){
	string start,xx;
	for(int i=0;i<9;i++){
		char c;
		cin >> c;
		start += c;
		if(c != 'x') xx += c;
	}
	
	int res = 0; //统计逆序对
	for(int i=0;i<8;i++)
		for(int j=i+1;j<8;j++)
			if(xx[i] > xx[j]) res++;
	
	if(res%2) cout << "unsolvable" << endl;
	else cout << bfs(start) << endl;
	
	
	return 0;
}
