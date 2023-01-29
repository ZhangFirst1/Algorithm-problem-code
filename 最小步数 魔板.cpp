//最小步数模型 魔板
//由初始状态变成最终状态所需要的最小操作步数及操作过程
#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<cstring>

using namespace std;
unordered_map <string, pair<string, char> > pre; //当前状态对应的对应的上一状态和操作
string ed,start,res;

string operA(string str){
	for(int i=0;i<4;i++) swap(str[i],str[7-i]);
	return str;
}

string operB(string str){
	for(int i=0;i<3;i++) swap(str[2-i],str[3-i]), swap(str[4+i],str[5+i]);
	return str;
}

string operC(string str){
	swap(str[1],str[2]),swap(str[5],str[6]),swap(str[1],str[5]);
	return str;
}

void bfs(string start,string ed){
	queue<string> q;
	q.push(start);
	
	while(!q.empty()){
		string t = q.front();
		q.pop();
		if(t == ed) return;
		string move[3];
		move[0] = operA(t);
		move[1] = operB(t);
		move[2] = operC(t);
		for(int i=0;i<3;i++){ //遍历三种状态
			if(!pre.count(move[i])){	//如果当前状态还没被记录过
				q.push(move[i]);		//当前状态入队
				pre[move[i]] = make_pair(t, 'A' + i); //记录当下状态所对应的上一状态的状态和操作
			}
		}
		
	}
	
}





int main(){
	start = "12345678";
for(int i=0;i<8;i++)
    {
        int x;
        cin>>x;
        ed += char(x+'0'); //建立结束状态
    }
	bfs(start, ed);
	
	while(start != ed){  //从最终状态向起始状态回溯
		res = pre[ed].second + res; //把前一个操作放在输出序的前边
		ed = pre[ed].first;
	}
		
	if(res.length() == 0) cout << "0";
	else cout << res.length() << endl << res;
	
	return 0;
}
