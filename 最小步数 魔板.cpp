//��С����ģ�� ħ��
//�ɳ�ʼ״̬�������״̬����Ҫ����С������������������
#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<cstring>

using namespace std;
unordered_map <string, pair<string, char> > pre; //��ǰ״̬��Ӧ�Ķ�Ӧ����һ״̬�Ͳ���
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
		for(int i=0;i<3;i++){ //��������״̬
			if(!pre.count(move[i])){	//�����ǰ״̬��û����¼��
				q.push(move[i]);		//��ǰ״̬���
				pre[move[i]] = make_pair(t, 'A' + i); //��¼����״̬����Ӧ����һ״̬��״̬�Ͳ���
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
        ed += char(x+'0'); //��������״̬
    }
	bfs(start, ed);
	
	while(start != ed){  //������״̬����ʼ״̬����
		res = pre[ed].second + res; //��ǰһ����������������ǰ��
		ed = pre[ed].first;
	}
		
	if(res.length() == 0) cout << "0";
	else cout << res.length() << endl << res;
	
	return 0;
}
